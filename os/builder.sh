#!/bin/bash

# check if cmake is installed
[ -f /bin/cmake ] || {
	echo "cmake not found"
	exit
}

# cmake to generate build files
cmake -S . -B build/

# build the files
cmake --build build/

# install
cmake --install build/

# Step 5: Print completion message
echo "Build process completed.\nBinary File in ~/zin"
