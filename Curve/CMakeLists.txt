cmake_minimum_required(VERSION 3.5)

project (Curve)

set(CMAKE_CXX_STANDARD 20)

add_library(Curve SHARED 
                            include/Circle.h
                            include/Curve.h
                            include/Curves.h
                            include/Derivative.h
                            include/Ellipse.h
                            include/Helix.h
                            include/Point.h
                            include/RadiusException.h

                            src/Circle.cpp
                            src/Derivative.cpp
                            src/Ellipse.cpp
                            src/Helix.cpp
                            src/Point.cpp
                            )

target_include_directories(Curve PUBLIC include)