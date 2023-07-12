cmake_minimum_required(VERSION 3.0)
project(MyKernel)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore")
set(CMAKE_ASM_FLAGS "--32")

file(GLOB SOURCES "*.cpp")
file(GLOB ASM_SOURCES "*.s")

add_executable(myKernel ${SOURCES} ${ASM_SOURCES})

install(TARGETS myKernel DESTINATION ~/zin)

