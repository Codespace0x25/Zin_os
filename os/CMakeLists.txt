cmake_minimum_required(VERSION 3.0)
project(ZinOS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore")
set(CMAKE_ASM_FLAGS "--32")

file(GLOB SOURCES "*.cpp")
file(GLOB ASM_SOURCES "*.s")

# Add gdt.cpp to the SOURCES list
list(APPEND SOURCES "gdt.cpp")

add_executable(zinKernel ${SOURCES} ${ASM_SOURCES})

install(TARGETS zinKernel DESTINATION ${HOME}/zin)
