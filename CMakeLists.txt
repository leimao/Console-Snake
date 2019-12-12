cmake_minimum_required(VERSION 3.0.0)

project(SNAKE VERSION 0.0.1)

set (CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp snake.cpp game.cpp)
target_link_libraries(main PRIVATE curses)