cmake_minimum_required(VERSION 3.0.0)

project(SNAKE VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 11)

# Check if CPlayer submodule has been git cloned
find_path(CPLAYER_DIR src/cplayer.h ${CMAKE_SOURCE_DIR}/modules/Console_Player/)
if((NOT CPLAYER_DIR) OR (NOT EXISTS ${CPLAYER_DIR}))
    # Inform the user we could not confirm the existence of CPlayer in the project directory
    message("Could not find CPlayer!")
    message("Downloading CPlayer...")
    # Download the submodule
    execute_process(COMMAND git submodule update --init --recursive)
    # Set the subdirectory properly
    set(CPLAYER_DIR ${CMAKE_SOURCE_DIR}/modules/Console_Player/)
endif()

# Built and add subdirectory
add_subdirectory(${CPLAYER_DIR})
add_subdirectory(src)

SET(CMAKE_INSTALL_PREFIX .)
install(TARGETS main DESTINATION bin)
