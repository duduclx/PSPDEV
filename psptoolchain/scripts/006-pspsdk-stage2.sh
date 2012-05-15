#!/bin/sh
# pspsdk-stage2.sh by Dan Peori (danpeori@oopo.net)

 ## Enter the source directory.
 cd $BUILDDIR/pspsdk2

 ## Bootstrap the source.
 ./bootstrap

 ## Configure the build.
 ./configure --with-pspdev="$PSPDEV"

 ## Build and install.
 make clean
 make
 make install
 make clean
