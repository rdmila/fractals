cmake_minimum_required(VERSION 3.17)
project(fractals)

set(MAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(fractals main.cpp calcPixels.cpp Complex/Complex.cpp)

target_link_libraries(fractals sfml-graphics)

