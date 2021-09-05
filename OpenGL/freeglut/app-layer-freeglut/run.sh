#!/usr/bin/env bash

EXE_FILE="./a.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++17 \
    -I"/usr/local/Cellar/freeglut/3.0.0/include/" \
    -L"/usr/local/Cellar/freeglut/3.0.0/lib/" -lglut \
    -framework OpenGL \
    `find . -maxdepth 1 -name "*.cc" | tr '\n' ' '` -o "$EXE_FILE" \
     && DISPLAY=:0 /opt/X11/bin/xterm -e "$EXE_FILE"


# $ cat /usr/local/Cellar/freeglut/3.0.0/lib/pkgconfig/freeglut.pc 
# prefix=/usr/local/Cellar/freeglut/3.0.0
# libdir=/usr/local/Cellar/freeglut/3.0.0/lib
# includedir=${prefix}/include
# 
# Name: glut
# Description: A freely licensed and improved alternative to the GLUT library
# Version: 3.0.0
# Libs: -L${libdir} -lglut
# Libs.private: -lX11 -lXxf86vm -lXrandr -lGL -lm
# Cflags: -I${includedir} 
