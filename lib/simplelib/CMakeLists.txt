# Shared library. Remove "SHARED" to get a statically linked library.
add_library (simple SHARED simple.cpp)

# Make sure the compiler can find include files for our library.
target_include_directories (simple PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
