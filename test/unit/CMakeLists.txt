# GTest code is not built when it is installed. Create a list of the source
# files to be used downstream when creating the binary.
# Add flags needed for building gtest, then build and set the flags back.
include_directories(/usr/include/gtest)
set(LOCAL_CXX_FLAGS ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-missing-field-initializers")
add_subdirectory(/usr/src/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest)
set(CMAKE_CXX_FLAGS ${LOCAL_CXX_FLAGS})

# Special macro for adding unit tests.
macro(add_unit_test target target_test)
  set(unit_test_targets ${unit_test_targets} ${target_test} PARENT_SCOPE)

  add_test(${target} ${CMAKE_BINARY_DIR}/share/${PROJECT_NAME}/${target_test})

  add_custom_target(all_${target_test} ALL DEPENDS run_${target_test})
  add_custom_target(run_${target_test} DEPENDS ${target_test}.passed)

  add_custom_command(OUTPUT ${target_test}.passed
    PRE_BUILD COMMAND ${target_test}
    COMMAND ${CMAKE_COMMAND} -E touch ${target_test}.passed
    DEPENDS ${target_test})

endmacro(add_unit_test)

add_subdirectory(lib)
