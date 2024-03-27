#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <vector>
#include <memory>
#include <string>

#include "snake.h"
#include "cplayer.h"

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
    void loadLeadBoard();
    void updateLeadBoard();
    void setBGM(std::string filename);
    void playKillableBGM();
    bool readLeaderBoard();
    bool updateLeaderBoard();
    bool writeLeaderBoard();
    void renderLeaderBoard() const;

private:
    // We need to have two windows
    // One is for game introduction
    // One is for game mWindows
    int mScreenWidth;
    int mScreenHeight;
    int mGameBoardWidth;
    int mGameBoardHeight;
    const int mInformationHeight = 6;
    const int mInstructionWidth = 18;
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
    std::unique_ptr<CPlayer> mPtrPlayer;
    const std::string mRecordBoardFilePath{"record.dat"};
    std::vector<int> mLeaderBoard;
    const int mNumLeaders = 3;
};

#endif