#!/bin/bash

# Variables
CXX="g++"
SRC=("../src/main.cpp")
OUTPUT="vulkan_triangle_tut"
CFLAGS="-std=c++11 -g -O0 -Wall -Wextra -pedantic"
LDFLAGS="-lglfw -lvulkan"
DEFINES="-DDEBUG"

# Disable pushd and popd echoing
pushd () {
    command pushd "$@" > /dev/null
}

popd () {
    command popd "$@" > /dev/null
}

# Create bin folder and enter it
mkdir -p bin
pushd bin

# Compile command
$CXX $SRC $CFLAGS $LDFLAGS -o $OUTPUT

# Leave bin folder
popd
