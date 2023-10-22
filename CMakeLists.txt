cmake_minimum_required(VERSION 3.5)

project(CADEX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (TBB_DIR "/oneapi-tbb-2021.10.0/lib/cmake/tbb")

add_subdirectory(Curve)
find_package(TBB)

set(TARGET_SOURCES )
add_executable(CADEX  src/main.cpp
                      src/RadiusParallelSummator.h)

target_link_libraries(CADEX PUBLIC Curve)

target_compile_options(CADEX PRIVATE
                    -Wall -Wextra -Wpedantic -Werror
                  )

if (${TBB_FOUND})
  add_definitions(-DTBB_FOUND)
  target_link_libraries(CADEX PUBLIC ${TBB_IMPORTED_TARGETS})
endif()
