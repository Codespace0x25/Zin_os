cmake_minimum_required(VERSION 3.5)
project(ZinOS)

# Compiler flags
set(COMMON_FLAGS "-fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 ${COMMON_FLAGS}")
    set(CMAKE_ASM_FLAGS "--32")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 ${COMMON_FLAGS}")
    set(CMAKE_ASM_FLAGS "-m32")
else()
    message(FATAL_ERROR "Unsupported system: ${CMAKE_SYSTEM_NAME}")
endif()

# Source files
file(GLOB SOURCES "*.cpp")
file(GLOB ASM_SOURCES "*.s")

# Executable target
add_executable(zinKernel ${SOURCES} ${ASM_SOURCES})

# Install target
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(INSTALL_DIR "$ENV{USERPROFILE}/zin")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(INSTALL_DIR "$ENV{HOME}/zin")
endif()

install(TARGETS zinKernel DESTINATION ${INSTALL_DIR})
