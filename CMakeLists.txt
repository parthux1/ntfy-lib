# Version requirement
cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/tooling/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

project(ntfy-lib VERSION 0.1.0 DESCRIPTION "ntfy API for C++")

# code
add_subdirectory("src")
