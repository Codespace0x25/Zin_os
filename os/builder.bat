@echo off 

rem Step 1: Create build directory
mkdir -p build
cd build || exit

rem Step 2: Generate build files
cmake -DCMAKE_CXX_FLAGS="-m32" -DCMAKE_ASM_FLAGS="--32" ..

rem Step 3: Build the project
make

rem Step 4: Install the executable
make install

rem Step 5: Print completion message
echo "Build process completed."

