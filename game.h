#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <vector>
#include "snake.h"
#include <memory>

class Game
{
public:
    Game();
    void createInformationBoard();
    void createGameBoard();
    void createInstructionBoard();
    void initializeGame();
    void runGame();
    void createSnake();
    void createRamdonFood();
    void renderBoards();
    void renderSnake();
    void renderFood();
    void renderPoints();
    void gameCycle();
    void controlSnake();
    void start();
    void startGame();
    bool renderRestartMenu();

private:
    // We need to have two windows
    // One is for game introduction
    // One is for game mWindows
    int mScreenWidth;
    int mScreenHeight;
    int mGameBoardWidth;
    int mGameBoardHeight;
    const int mInformationHeight = 6;
    const int mInstructionWidth = 15;
    std::vector<WINDOW *> mWindows;
    // Snake information
    const int mInitialSnakeLength = 2;
    const char mSnakeSymbol = '@';
    // Food information
    std::unique_ptr<Snake> mPtrSnake;
    SnakeBody mFood;
    const char mFoodSymbol = '#';
    int mPoints = 0;
    int mDifficulty = 0;
    
};

#endif