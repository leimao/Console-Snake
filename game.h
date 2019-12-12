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
    ~Game();
    void createInformationBoard();
    void renderInformationBoard() const;
    void createGameBoard();
    void renderGameBoard() const;
    void createInstructionBoard();
    void renderInstructionBoard() const;
    void initializeGame();
    void runGame();
    void createRamdonFood();
    void renderBoards() const;
    void renderSnake() const;
    void renderFood() const;
    void renderPoints() const;
    void renderDifficulty() const;
    void controlSnake() const;
    void startGame();
    bool renderRestartMenu() const;
    void adjustDelay();

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
    int mBaseDelay = 100;
    int mDelay;
};

#endif