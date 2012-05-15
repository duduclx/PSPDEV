#!/bin/sh

# psplinkusb.sh by Dan Peori (danpeori@oopo.net)

 ## Enter the source directory.
 cd $BUILDDIR/psplinkusb

 ## Build and install.
 make -f Makefile.clients clean
 make -f Makefile.clients
 make -f Makefile.clients install
 make -f Makefile.clients clean

