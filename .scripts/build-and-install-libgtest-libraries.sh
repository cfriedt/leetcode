#!/bin/sh

set -e

# N.B. Older Ubuntu versions do not carry the "googletest" package
# (which includes Google Mock and Google Test), so better to just
# install from source / git.

cd /tmp
rm -Rf googletest

git clone https://github.com/google/googletest.git
cd googletest

# installs headers to /usr/include/gtest /usr/include/gmock
# install static libraries to /usr/lib
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr . && make -j$(nproc --all) all install
# install shared libraries to /usr/lib
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr -DBUILD_SHARED_LIBS=ON && make -j$(nproc --all) all install

