cmake_minimum_required(VERSION 3.30)
project(basic2d_engine)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

enable_testing()

add_subdirectory(engine)
add_subdirectory(examples)
add_subdirectory(tests)