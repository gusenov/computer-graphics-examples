#!/usr/bin/env bash

EXE_FILE="./a.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++17 \
    -I"/usr/local/Cellar/freeglut/3.0.0/include/" \
    -L"/usr/local/Cellar/freeglut/3.0.0/lib/" -lglut \
    -framework OpenGL \
    -DGL_SILENCE_DEPRECATION \
    main.cc OpenGLApplication.cc -o "$EXE_FILE" \
     && DISPLAY=:0 /opt/X11/bin/xterm -e "$EXE_FILE"

# Для генерация списка исходников:
# `find . -maxdepth 1 -name "*.cc" | tr '\n' ' '`
