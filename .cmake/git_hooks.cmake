# Symlink the clang-format hooks into place.
execute_process(
  COMMAND "${CMAKE_COMMAND}" "-E" "create_symlink" "${CMAKE_CURRENT_SOURCE_DIR}/.hooks/pre-commit-clang-format" "${CMAKE_CURRENT_SOURCE_DIR}/.git/hooks/pre-commit"
  OUTPUT_VARIABLE output
)
message(STATUS "Created clang-format pre-commit hook. ${output}")
