#!/bin/bash

VIDEOS="./videos"
VIDEOS=$(readlink -f $VIDEOS)

mkdir -p build && cd build

# Build tomeo
qmake ..
make $@

# Execute with expanded path
./tomeo "$VIDEOS"
