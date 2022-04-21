#!/bin/bash

declare -r BUILD_DIR="build"

cmake -B$BUILD_DIR -DCMAKE_BUILD_TYPE=Release
cmake --build $BUILD_DIR/ -j8
echo
echo

./$BUILD_DIR/lookandsay
