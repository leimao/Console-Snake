cmake_minimum_required(VERSION 3.13.0)

project(SNAKE_GAME VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp snake.cpp game.cpp)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/modules/Console-Player/src)
target_link_libraries(main PRIVATE curses cplayer pthread)

