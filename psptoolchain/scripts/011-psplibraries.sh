#!/bin/sh

# psplibraries.sh by Takeshi Watanabe (takechi101010@gmail.com)

 ## clear CC and CXX
 unset CC
 unset CXX
 ## Enter the source directory.
 cd $BUILDDIR/psplibraries

 ## Configure the build.
 ./libraries.sh
