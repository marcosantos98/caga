cmake_minimum_required(VERSION 3.20)

project(caga C)

find_package(raylib 4.0.0 QUIET)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

set(CMAKE_C_COMPILER ${cc})
set(CMAKE_C_FLAGS "-Wall -Wextra -std=c99 -pedantic")

set(JANSSON_WITHOUT_TESTS ON)
add_subdirectory(vendor/jansson)
include_directories(vendor/jansson/src)

file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

file(GLOB PROJ_SOURCES "src/*.c" "src/*.h")
add_executable(caga ${PROJ_SOURCES})

target_link_libraries(caga raylib jansson)