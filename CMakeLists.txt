cmake_minimum_required(VERSION 3.0.0)

project(SNAKE VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)

#set(CPLAYER_PATH ./modules/Console_Player)
#message(CPLAYER_PATH)
# Check if CPlayer submodule has been git cloned
find_path(CPLAYER_DIR src/cplayer.h ${CMAKE_SOURCE_DIR}/modules/Console_Player/)
if((NOT CPLAYER_DIR) OR (NOT EXISTS ${CPLAYER_DIR}))
    # Could not confirm the existence of CPlayer in the project directory
    message("Could not find CPlayer!")
    execute_process(COMMAND git submodule update --init --recursive)
endif()



#message(${CPLAYER_DIR})


#find_package(CONSOLE_SOUND_PLAYER)


message(${CMAKE_SOURCE_DIR})
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/modules/Console_Player/)
    message("Not found CPlayer!")
endif()



add_executable(main main.cpp snake.cpp game.cpp)
target_link_libraries(main PRIVATE curses)