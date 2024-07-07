# Version requirement
# for .23 for FILESETS
cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/tooling/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

project(ntfy-lib VERSION 0.1.1 DESCRIPTION "ntfy API for C++")

option(ntfy_build_example "Build Example" OFF)

add_library(ntfy SHARED)

add_subdirectory(include)
add_subdirectory(src)

set_target_properties(ntfy PROPERTIES VERSION ${PROJECT_VERSION})


# install rule
include(GNUInstallDirs)
install(TARGETS ntfy
        FILE_SET HEADERS
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


# dependencies
find_package(nlohmann_json REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(spdlog REQUIRED)
find_package(cpr REQUIRED)


target_link_libraries(ntfy PUBLIC
        spdlog::spdlog
        yaml-cpp::yaml-cpp
        cpr::cpr
        nlohmann_json::nlohmann_json)

# build examples if flag is set
if (ntfy_build_example)
    add_subdirectory(example)
endif ()