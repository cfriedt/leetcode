#!/bin/sh

E() {
	local r=$?
	if [ 0 -ne $r ]; then
		r=1
	fi
	if [ "" != "$*" ]; then
		echo "E: $*" > /dev/stderr
		echo "" > /dev/stderr
	fi

	usage

	exit $r
}

cd /usr/src/gtest || E failed to change to /usr/src/gtest
cmake -DBUILD_SHARED_LIBS=ON || E "cmake -DBUILD_SHARED_LIBS=ON failed"
make || E make failed
cp *.so /usr/lib/ || E failed to copy .so files to /usr/lib

#cd /usr/src/gtest || E failed to change to /usr/src/gtest
#make clean || E failed to clean source directory
#rm -Rf CMakeCache.txt CMakeFiles/ || E failed to clean cmake files
#cmake || E cmake failed
#make || E make failed
#cp *.a /usr/lib/ || E failed to copy .a files to /usr/lib


