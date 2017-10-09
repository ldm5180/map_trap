# Set flags for all compilations.
add_definitions("-Wall -Werror -pedantic -Wextra")
add_definitions(-std=c++1z)
add_definitions(-stdlib=libc++)
add_definitions(-nodefaultlibs)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")

link_libraries(c++ c++abi)

# Set debug build flags.
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -fno-omit-frame-pointer")

# Set release build flags.
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

find_program(CCACHE_FOUND ccache)
if (CCACHE_FOUND)
  message(STATUS "Enabling ccache to enhance build throughput.")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "ccache")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "ccache")
else()
  message(STATUS "ccache not enabled. Install ccache for speedier builds.")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
