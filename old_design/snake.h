#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <ncurses.h>

enum class Direction
{
    Up = 0,
    Down = 1,
    Left = 2,
    Right = 3,
};

class SnakeBody
{
public:
    SnakeBody();
    SnakeBody(int x, int y);
    int getX() const;
    int getY() const;
    bool operator == (const SnakeBody& snakeBody);
private:
    int x;
    int y;
};


class Snake
{
public:
    Snake();
    void createInformationBoard();
    void createGameBoard();
    void createInstructionBoard();
    void renderBoard();
    void setRandomSeed(unsigned int seed);
    void initializeSnake();
    void createFood();
    bool isOverlapSnake(int x, int y);
    void start();


private:
    // We need to have two windows
    // One is for game introduction
    // One is for game board
    int screenWidth;
    int screenHeight;
    int gameBoardWidth;
    int gameBoardHeight;
    const int snakeInitialLength = 2;
    const int informationHeight = 5;
    const int instructionWidth = 15;
    std::vector<WINDOW *> board;
    // Snake information
    const int initialSnakeLength = 2;
    const char snakeSymbol = '@';
    // Food information
    SnakeBody food;
    const char foodSymbol = '#';
    // Four directions
    char direction;
    // 
    std::vector<SnakeBody> snake;
};


#endif