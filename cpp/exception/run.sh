#!/usr/bin/env bash

set -euo pipefail

clang-format -i *.cpp -style=file

g++ main.cpp -o main

./main
