#!/bin/bash

# 创建构建目录
mkdir -p build
cd build
# 运行 CMake
cmake -DCMAKE_C_COMPILER=clang  ..
# 编译
make -j$(nproc)
# 回到原目录
cd ..