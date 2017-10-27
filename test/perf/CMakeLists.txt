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

### std::map #########################################################

add_executable(map_insert map_insert.cpp)
target_link_libraries(map_insert benchmark)
add_perf_test(map_insert_test map_insert)

add_executable(map_iterate map_iterate.cpp)
target_link_libraries(map_iterate benchmark)
add_perf_test(map_iterate_test map_iterate)

add_executable(map_find map_find.cpp)
target_link_libraries(map_find benchmark)
add_perf_test(map_find_test map_find)

### boost::container::flat_map #######################################

add_executable(flat_map_insert flat_map_insert.cpp)
target_link_libraries(flat_map_insert benchmark)
add_perf_test(flat_map_insert_test flat_map_insert)

add_executable(flat_map_iterate flat_map_iterate.cpp)
target_link_libraries(flat_map_iterate benchmark)
add_perf_test(flat_map_iterate_test flat_map_iterate)

add_executable(flat_map_find flat_map_find.cpp)
target_link_libraries(flat_map_find benchmark)
add_perf_test(flat_map_find_test flat_map_find)

### std::unordered_map ###############################################

add_executable(unordered_map_insert unordered_map_insert.cpp)
target_link_libraries(unordered_map_insert benchmark)
add_perf_test(unordered_map_insert_test unordered_map_insert)

add_executable(unordered_map_insert_sort unordered_map_insert_sort.cpp)
target_link_libraries(unordered_map_insert_sort benchmark)
add_perf_test(unordered_map_insert_sort_test unordered_map_insert_sort)

add_executable(unordered_map_iterate unordered_map_iterate.cpp)
target_link_libraries(unordered_map_iterate benchmark)
add_perf_test(unordered_map_iterate_test unordered_map_iterate)

add_executable(unordered_map_insert_sort_iterate unordered_map_insert_sort_iterate.cpp)
target_link_libraries(unordered_map_insert_sort_iterate benchmark)
add_perf_test(unordered_map_insert_sort_iterate_test unordered_map_insert_sort_iterate)

add_executable(unordered_map_find unordered_map_find.cpp)
target_link_libraries(unordered_map_find benchmark)
add_perf_test(unordered_map_find_test unordered_map_find)

