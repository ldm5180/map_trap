cmake_minimum_required(VERSION 2.8)

# Default build type is debug.
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "No build type selected, default to Debug")
  set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the default CTest output on failure to true.
if (NOT CTEST_OUTPUT_ON_FAILURE)
  message(STATUS "Enabling CTest output on failure.")
  set(CTEST_OUTPUT_ON_FAILURE TRUE)
endif()

# Set the default CTest parallel level to the number of cores.
if (NOT CTEST_PARALLEL_LEVEL)
  execute_process(
    COMMAND "/usr/bin/nproc"
    OUTPUT_VARIABLE NPROC OUTPUT_STRIP_TRAILING_WHITESPACE)
  message(STATUS "Setting the CTest parallel level to ${NPROC}")
  set(CTEST_PARALLEL_LEVEL ${NPROC})
endif()

message("${CMAKE_BUILD_TYPE} build environment being generated in ${CMAKE_BINARY_DIR}")

# Name the project.
project(project-template)

# Enable C++14.
add_definitions(-std=c++14)

# Set flags for all compilations.
add_definitions("-Wall -Werror -pedantic -Wextra")

# Symlink the clang-format hooks into place.
execute_process(
  COMMAND "${CMAKE_COMMAND}" "-E" "create_symlink" "${CMAKE_CURRENT_SOURCE_DIR}/.hooks/pre-commit-clang-format" "${CMAKE_CURRENT_SOURCE_DIR}/.git/hooks/pre-commit"
  OUTPUT_VARIABLE output
)
message(STATUS "Created clang-format pre-commit hook. ${output}")

# Prevent in-tree builds.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed.
Please create a directory and run cmake from there, passing the path
to this source directory as the last argument.
This process created the file `CMakeCache.txt' and the directory `CMakeFiles'.
Please delete them.")
endif()
  
# The version number.
set(Reverse_VERSION_MAJOR 1)
set(Reverse_VERSION_MINOR 0)
set(Reverse_VERSION_PATCH 0)
set(Reverse_VERSION_SUFFIX git)

if (NOT PACKAGE_VERSION)
  set(PACKAGE_VERSION
    "${Reverse_VERSION_MAJOR}.${Reverse_VERSION_MINOR}.${Reverse_VERSION_PATCH}${Reverse_VERSION_SUFFIX}")
endif()

# Only permit DEBUG and RELEASE build types.
string(TOUPPER "${CMAKE_BUILD_TYPE}" uppercase_CMAKE_BUILD_TYPE)
if (CMAKE_BUILD_TYPE AND
    NOT uppercase_CMAKE_BUILD_TYPE MATCHES "^(DEBUG|RELEASE)$")
  message(FATAL_ERROR "Invalid value for CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}
Valid build types are DEBUG and RELEASE")
endif()

# Set debug build flags.
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-rtti -g -fno-omit-frame-pointer")

# Set release build flags.
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-rtti")

include_directories("include")
include_directories("include/range-v3/include")

# Setup unit tests
enable_testing()

# Add the directories containing more CMakeLists.
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)
