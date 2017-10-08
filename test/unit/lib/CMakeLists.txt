set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/share/${PROJECT_NAME})

add_executable(lib_unit_test simplelib.cpp)
target_link_libraries(lib_unit_test LINK_PUBLIC
  gmock
  gtest_main
  simple
)
add_unit_test(LibUnitTests lib_unit_test)

add_executable(header_only_unit_test header_only.cpp)
target_link_libraries(header_only_unit_test LINK_PUBLIC
  gmock
  gtest_main
)
add_unit_test(HeaderOnlyUnitTests header_only_unit_test)
