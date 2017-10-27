cmake_minimum_required(VERSION 2.8.12)

# Name the project.
project(map_trap)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/.cmake)

include(build_type)
include(git_hooks)
include(compiler_flags)  

set(BENCHMARK_ENABLE_TESTING OFF)
set(BENCHMARK_ENABLE_INSTALL OFF)
add_subdirectory(vendor/benchmark)

# Add the directories containing more CMakeLists.
add_subdirectory(test)
