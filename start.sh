#!/bin/bash

SOURCE_DIR="src"
OUTPUT_DIR="build"
SOURCE_FILES=(
    "${SOURCE_DIR}/main.cpp"
    "${SOURCE_DIR}/gui.h"
    "${SOURCE_DIR}/gui.cpp"
    "${SOURCE_DIR}/animate.h"
    "${SOURCE_DIR}/animate.cpp"
)

INCLUDE_DIRS=(
    -Ilibs/webview
    $(pkg-config --cflags gtk+-3.0 webkit2gtk-4.1)
    -I/usr/include/webkitgtk-4.0/JavaScriptCore
)

LIBRARIES=(
    # $(pkg-config --libs gtk+-3.0 webkit2gtk-4.0)
)

g++ "${SOURCE_FILES[@]}" \
    -std=c++17 \
    "${INCLUDE_DIRS[@]}" \
    -o "${OUTPUT_DIR}/basic" \
    && "${OUTPUT_DIR}/basic"
