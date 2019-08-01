
cmake_minimum_required (VERSION 2.6)

project(cali)

# Set default compile flags for GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_C_FLAGS "-Wall -g -O0")
endif(CMAKE_COMPILER_IS_GNUCXX)

add_subdirectory(cgen/src)

set(ALL_SOURCES main.c)

set(ALL_SOURCES ${ALL_SOURCES} CMemLeak.c)

include_directories("${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}")

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

# add_definitions(-D_DEBUG)


add_executable(cali ${ALL_SOURCES})

set_property(TARGET cali PROPERTY C_STANDARD 11)
