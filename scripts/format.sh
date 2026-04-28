#!/bin/bash

clang-format --style=file:.clang-format include/**/*.hpp -i --Werror
clang-format --style=file:.clang-format src/**/*.cpp -i --Werror
clang-format --style=file:.clang-format test/*.cpp -i --Werror