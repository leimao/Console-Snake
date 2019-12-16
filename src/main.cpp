#include "game.h"

int main(int argc, char** argv)
{
    Game game;
    // Check the number of parameters
    if (argc < 2) {
        game.setBGM("../../audios/bgm.wav");
    }
    else
    {
        game.setBGM(argv[1]);
    }
    game.startGame();
}