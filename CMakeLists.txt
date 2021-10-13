cmake_minimum_required(VERSION 3.21)
project(FractionOP)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wall)

add_executable(FractionOP main.cpp Fraction.h Fraction.cpp)
