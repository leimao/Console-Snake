cmake_minimum_required(VERSION 3.0.0)

project(SENET VERSION 0.0.1)

set (CMAKE_CXX_STANDARD 11)

add_executable(game snake.cpp game.cpp)
target_link_libraries(game PRIVATE curses)