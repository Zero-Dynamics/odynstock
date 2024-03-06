from distutils.core import setup
setup(name='ODYNSspendfrom',
      version='1.0',
      description='Command-line utility for odynstock "coin control"',
      author='Gavin Andresen',
      author_email='gavin@odynstockfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
