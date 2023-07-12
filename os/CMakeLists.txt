cmake_minimum_required(VERSION 3.0)
project(MyKernel)

set(CMAKE_CXX_FLAGS "-m32")
set(CMAKE_ASM_FLAGS "--32")
set(CMAKE_EXE_LINKER_FLAGS "-melf_i386")

file(GLOB SOURCES "*.cpp")
file(GLOB ASM_SOURCES "*.s")

add_executable(myKernel ${SOURCES} ${ASM_SOURCES})

install(TARGETS myKernel DESTINATION /boot)
