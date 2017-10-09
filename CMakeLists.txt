cmake_minimum_required(VERSION 2.8)

# Name the project.
project(project-template)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/.cmake)

include(build_type)
include(git_hooks)
include(compiler_flags)  

add_subdirectory(vendor/googletest)

# Project specific include directories.
include_directories("include")

# Add the directories containing more CMakeLists.
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)
