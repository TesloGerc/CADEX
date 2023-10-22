cmake_minimum_required(VERSION 3.5)

project(CADEX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CADEX 
                                  src/main.cpp
                                  Curve/src/Circle.cpp
                                  Curve/src/Ellipse.cpp
                                  Curve/src/Helix.cpp
                                  Curve/src/Point.cpp
                                  Curve/src/Derivative.cpp
                                  Curve/src/Utils.cpp
                                  )

target_compile_options(CADEX PRIVATE
                    -Wall -Wextra -Wpedantic -Werror
                  )