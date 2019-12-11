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
    void createSnake();
    void createRamdonFood();
    void renderBoard();
    void renderSnake();
    void renderFood();
    void renderPoints();
    void gameCycle();
    void controlSnake();
    void start();
    void startGame();

private:
    // We need to have two windows
    // One is for game introduction
    // One is for game mWindows
    int mScreenWidth;
    int mScreenHeight;
    int mGameBoardWidth;
    int mGameBoardHeight;
    const int mSnakeInitialLength = 2;
    const int mInformationHeight = 5;
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
    int mDifficulty;
    
};

#endif