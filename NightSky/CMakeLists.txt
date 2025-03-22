cmake_minimum_required(VERSION 3.10)
project(NightSky)

find_library(RAYLIB_LIBRARY NAMES raylib PATH [path-to-raylib]/lib)
find_path(RAYLIB_INCLUDE_DIR NAMES raylib.h PATH [path-to-raylib]/include)

if (RAYLIB_LIBRARY AND RAYLIB_INCLUDE_DIR)
    message(STATUS "raylib found at ${RAYLIB_LIBRARY}")
    include_directories(${RAYLIB_INCLUDE_DIR})
else()
    message(FATAL_ERROR "raylib not found!")
endif()

add_executable(NightSky main.cpp sky.cpp star.cpp)

target_link_libraries(NightSky ${RAYLIB_LIBRARY})