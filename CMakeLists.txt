cmake_minimum_required(VERSION 3.5)

project(CADEX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CADEX 
                                  main.cpp
                                  Curve/Circle.cpp
                                  Curve/Ellipse.cpp
                                  Curve/Helix.cpp
                                  Curve/Point.cpp
                                  Curve/Derivative.cpp
                                  )

target_compile_options(CADEX PRIVATE
                    -Wall -Wextra -Wpedantic -Werror
                  )