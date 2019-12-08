#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <ncurses.h>


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
    void createFood();
    bool isCollision(int x, int y);
    void start();


private:
    // We need to have two windows
    // One is for game introduction
    // One is for game board
    int screenWidth;
    int screenHeight;
    const int informationHeight = 5;
    const int instructionWidth = 15;
    std::vector<WINDOW *> board;
    // Snake information
    const int initialSnakeLength = 2;
    const char snakeSymbol = '@';
    // Food information
    const char foodSymbol = '#';
    // Four directions
    char direction;
    // 
    std::vector<SnakeBody> snake;
};


#endif