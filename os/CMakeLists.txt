cmake_minimum_required(VERSION 3.5)
project(ZinOS)

# Compiler flags
set(COMMON_FLAGS "-fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 ${COMMON_FLAGS}")  # Set additional C++ compiler flags for Windows
    set(CMAKE_ASM_FLAGS "--32")  # Set assembly compiler flags for Windows
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 ${COMMON_FLAGS}")  # Set additional C++ compiler flags for Linux
    set(CMAKE_ASM_FLAGS "-m32")  # Set assembly compiler flags for Linux
else()
    message(FATAL_ERROR "Unsupported system: ${CMAKE_SYSTEM_NAME}")  # Display a fatal error message for unsupported systems
endif()

# Source files
file(GLOB SOURCES "*.cpp")  # Collect all .cpp files in the current directory
file(GLOB ASM_SOURCES "*.s")  # Collect all .s (assembly) files in the current directory

# Executable target
add_executable(zinKernel ${SOURCES} ${ASM_SOURCES})  # Create an executable target named "zinKernel" using the collected source files

# Install target
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(INSTALL_DIR "$ENV{USERPROFILE}/zin")  # Set the installation directory to the user's profile directory on Windows
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(INSTALL_DIR "$ENV{HOME}/zin")  # Set the installation directory to the user's home directory on Linux
endif()

install(TARGETS zinKernel DESTINATION ${INSTALL_DIR})  # Install the "zinKernel" executable to the specified installation directory
