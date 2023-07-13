#!/bin/bash

# Step 1: Create build directory
mkdir -p build
cd build || exit

# Step 2: Generate build files
cmake -DCMAKE_CXX_FLAGS="-m32" -DCMAKE_ASM_FLAGS="--32" ..

# Step 3: Build the project
make

# Step 4: Install the executable
make install

# Step 5: Print completion message
echo "Build process completed."

