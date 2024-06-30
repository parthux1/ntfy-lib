# Version requirement
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/tooling/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

project(ntfy-lib VERSION 0.1.0 DESCRIPTION "ntfy API for C++")

option(ntfy_build_example "Build Example" OFF)

# make lib
set(ntfy_INCLUDE
        ${PROJECT_SOURCE_DIR}/include/Credentials.hpp
        ${PROJECT_SOURCE_DIR}/include/jsonFunc.hpp
        ${PROJECT_SOURCE_DIR}/include/Message.hpp
        ${PROJECT_SOURCE_DIR}/include/MessageListener.hpp
        ${PROJECT_SOURCE_DIR}/include/ntfy.hpp
        ${PROJECT_SOURCE_DIR}/include/Server.hpp
        ${PROJECT_SOURCE_DIR}/include/YamlConfiguration.hpp)

set(ntfy_SRC
        ${PROJECT_SOURCE_DIR}/src/jsonFunc.cpp
        ${PROJECT_SOURCE_DIR}/src/Message.cpp
        ${PROJECT_SOURCE_DIR}/src/MessageListener.cpp
        ${PROJECT_SOURCE_DIR}/src/Server.cpp
        ${PROJECT_SOURCE_DIR}/src/YamlConfiguration.cpp)

add_library(ntfy SHARED ${ntfy_INCLUDE} ${ntfy_SRC})
set_target_properties(ntfy PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(ntfy PROPERTIES PUBLIC_HEADER ${ntfy_INCLUDE})

# install rule
include(GNUInstallDirs)
install(TARGETS ntfy
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

find_package(nlohmann_json REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(spdlog REQUIRED)
find_package(cpr REQUIRED)

target_include_directories(ntfy PRIVATE
        include)

target_link_libraries(ntfy PUBLIC
        spdlog::spdlog
        yaml-cpp::yaml-cpp
        cpr::cpr
        nlohmann_json::nlohmann_json)

if (ntfy_build_example)
    add_subdirectory(example)
endif ()