#!/usr/bin/env python3
# Copyright (c) 2015-2016 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

"""
This module contains utilities for doing coverage analysis on the RPC
interface.

It provides a way to track which RPC commands are exercised during
testing.

"""
import os


REFERENCE_FILENAME = 'rpc_interface.txt'


class AuthServiceProxyWrapper(object):
    """
    An object that wraps AuthServiceProxy to record specific RPC calls.

    """
    def __init__(self, auth_service_proxy_instance, coverage_logfile=None):
        """
        Kwargs:
            auth_service_proxy_instance (AuthServiceProxy): the instance
                being wrapped.
            coverage_logfile (str): if specified, write each service_name
                out to a file when called.

        """
        self.auth_service_proxy_instance = auth_service_proxy_instance
        self.coverage_logfile = coverage_logfile

    def __getattr__(self, *args, **kwargs):
        return_val = self.auth_service_proxy_instance.__getattr__(
            *args, **kwargs)

        return AuthServiceProxyWrapper(return_val, self.coverage_logfile)

    def __call__(self, *args, **kwargs):
        """
        Delegates to AuthServiceProxy, then writes the particular RPC method
        called to a file.

        """
        return_val = self.auth_service_proxy_instance.__call__(*args, **kwargs)
        rpc_method = self.auth_service_proxy_instance._service_name

        if self.coverage_logfile:
            with open(self.coverage_logfile, 'a+') as f:
                f.write("%s\n" % rpc_method)

        return return_val

    @property
    def url(self):
        return self.auth_service_proxy_instance.url


def get_filename(dirname, n_node):
    """
    Get a filename unique to the test process ID and node.

    This file will contain a list of RPC commands covered.
    """
    pid = str(os.getpid())
    return os.path.join(
        dirname, "coverage.pid%s.node%s.txt" % (pid, str(n_node)))


def write_all_rpc_commands(dirname, node):
    """
    Write out a list of all RPC functions available in `odynstock-cli` for
    coverage comparison. This will only happen once per coverage
    directory.

    Args:
        dirname (str): temporary test dir
        node (AuthServiceProxy): client

    Returns:
        bool. if the RPC interface file was written.

    """
    filename = os.path.join(dirname, REFERENCE_FILENAME)

    if os.path.isfile(filename):
        return False

    help_output = node.help().split('\n')
    commands = set()

    for line in help_output:
        line = line.strip()

        # Ignore blanks and headers
        if line and not line.startswith('='):
            commands.add("%s\n" % line.split()[0])

    with open(filename, 'w') as f:
        f.writelines(list(commands))

    return True
