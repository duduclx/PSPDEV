#!/bin/sh

# pspsdk-stage1.sh by Dan Peori (danpeori@oopo.net)

 ## Enter the source directory.
 cd $BUILDDIR/pspsdk1

 ## Bootstrap the source.
 ./bootstrap

 ## Configure the build.
 ./configure --with-pspdev="$PSPDEV"

 ## Build and install.
 make clean
 make install-data
 make clean
