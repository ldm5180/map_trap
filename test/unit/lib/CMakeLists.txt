file(GLOB SRCS *.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/share/${PROJECT_NAME})

add_executable(lib_unit_test ${SRCS})

target_link_libraries(lib_unit_test LINK_PUBLIC gtest)

add_unit_test(LibUnitTests lib_unit_test)
