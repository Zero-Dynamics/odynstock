
Debian
====================
This directory contains files used to package odynstockd/odynstock-qt
for Debian-based Linux systems. If you compile odynstockd/odynstock-qt yourself, there are some useful files here.

## odynstock: URI support ##


odynstock-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install odynstock-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your odynstock-qt binary to `/usr/bin`
and the `../../share/pixmaps/odynstock128.png` to `/usr/share/pixmaps`

odynstock-qt.protocol (KDE)

