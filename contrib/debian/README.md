
Debian
====================
This directory contains files used to package LORDTROLLCOINd/LORDTROLLCOIN-qt
for Debian-based LMemex systems. If you compile LORDTROLLCOINd/LORDTROLLCOIN-qt yourself, there are some useful files here.

## LORDTROLLCOIN: URI support ##


LORDTROLLCOIN-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install LORDTROLLCOIN-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your LORDTROLLCOIN-qt binary to `/usr/bin`
and the `../../share/pixmaps/LORDTROLLCOIN128.png` to `/usr/share/pixmaps`

LORDTROLLCOIN-qt.protocol (KDE)

