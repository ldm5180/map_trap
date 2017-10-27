# Special macro for adding performance tests.
macro(add_perf_test target target_test)
  set(perf_test_targets ${perf_test_targets} ${target_test} PARENT_SCOPE)

  add_custom_target(all_${target_test} ALL DEPENDS run_${target_test})
  add_custom_target(run_${target_test} DEPENDS ${target_test}.passed)

  add_custom_command(OUTPUT ${target_test}.passed
    PRE_BUILD COMMAND ${target_test}
    COMMAND ${CMAKE_COMMAND} -E touch ${target_test}.passed
    DEPENDS ${target_test})
endmacro(add_perf_test)

add_executable(map_baseline map_baseline.cpp)
target_link_libraries(map_baseline benchmark)
add_perf_test(map_baseline_test map_baseline)
