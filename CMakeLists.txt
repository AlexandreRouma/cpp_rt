cmake_minimum_required(VERSION 3.13)
project(pathtracer)

add_compile_options(/std:c++17)

file(GLOB_RECURSE SRC "src/*.cpp")

include_directories("src/")
add_executable(pathtracer ${SRC})