#!/bin/sh
set -e
mkdir -p bin
cd bin
cmake -D CMAKE_BUILD_TYPE=Release ../src/
make
cp ../valid_names.txt ../training_data ../test_data training/
