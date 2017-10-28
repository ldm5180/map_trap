# Special macro for adding performance tests.
macro(add_perf_test target target_test)
  set(perf_test_targets ${perf_test_targets} ${target_test} PARENT_SCOPE)

  add_custom_target(all_${target_test} ALL DEPENDS run_${target_test})
  add_custom_target(run_${target_test} DEPENDS ${target_test}.passed)

  add_custom_command(OUTPUT ${target_test}.passed
    PRE_BUILD COMMAND ${target_test} "--benchmark_out=${CMAKE_SOURCE_DIR}/test/perf/outputs/${target_test}.csv" "--benchmark_out_format=csv"
    COMMAND ${CMAKE_COMMAND} -E touch ${target_test}.passed
    DEPENDS ${target_test})
endmacro(add_perf_test)

add_executable(map_find find.cpp)
target_link_libraries(map_find benchmark)
add_perf_test(map_find_test map_find)

add_executable(map_iterate iterate.cpp)
target_link_libraries(map_iterate benchmark)
add_perf_test(map_iterate_test map_iterate)

add_executable(map_insert insert.cpp)
target_link_libraries(map_insert benchmark)
add_perf_test(map_insert_test map_insert)

add_executable(map_book book.cpp)
target_link_libraries(map_book benchmark)
add_perf_test(map_book_test map_book)
