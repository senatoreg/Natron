#!/bin/bash

# Install libcroco (requires glib and libxml2)
# see https://ftp.gnome.org/pub/gnome/sources/libcroco/0.6/
# https://web.archive.org/web/20190719030924/http://www.linuxfromscratch.org/blfs/view/svn/general/libcroco.html
# http://www.linuxfromscratch.org/blfs/view/svn/general/libcroco.html
LIBCROCO_VERSION=0.6.13
LIBCROCO_VERSION_SHORT=${LIBCROCO_VERSION%.*}
LIBCROCO_TAR="libcroco-${LIBCROCO_VERSION}.tar.xz"
LIBCROCO_SITE="http://ftp.gnome.org/pub/gnome/sources/libcroco/${LIBCROCO_VERSION_SHORT}"
if download_step; then
    download "$LIBCROCO_SITE" "$LIBCROCO_TAR"
fi
if build_step && { force_build || { [ ! -s "$SDK_HOME/lib/libcroco-0.6.so" ]; }; }; then
    start_build
    untar "$SRC_PATH/$LIBCROCO_TAR"
    pushd "libcroco-${LIBCROCO_VERSION}"
    env CFLAGS="$BF" CXXFLAGS="$BF" ./configure --prefix="$SDK_HOME" --disable-docs --disable-static --enable-shared
    make -j${MKJOBS}
    make install
    popd
    rm -rf "libcroco-${LIBCROCO_VERSION}"
    end_build
fi
