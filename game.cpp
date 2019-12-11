#include "game.h"
#include <string>


#include <iostream>

#include <chrono>
#include <thread>
//#include <unistd.h>

Game::Game()
{
    this->mWindows.resize(3);
    initscr();
    nodelay(stdscr,true);                   //if there wasn't any key pressed don't wait for keypress
    keypad(stdscr, true);
    noecho();
    curs_set(0);

    getmaxyx(stdscr, this->mScreenHeight, this->mScreenWidth);
    this->mGameBoardWidth = this->mScreenWidth - this->mInstructionWidth;
    this->mGameBoardHeight = this->mScreenHeight - this->mInformationHeight;
}


void Game::createInformationBoard()
{
    int startY = 0;
    int startX = 0;
    this->mWindows[0] = newwin(this->mInformationHeight, this->mScreenWidth, startY, startX);
    mvwprintw(this->mWindows[0], 1, 1, "Welcome to Snake Game!");
    mvwprintw(this->mWindows[0], 2, 1, "Author: Lei Mao");
}

void Game::createGameBoard()
{
    int startY = this->mInformationHeight;
    int startX = 0;
    this->mWindows[1] = newwin(this->mScreenHeight - this->mInformationHeight, this->mScreenWidth - this->mInstructionWidth, startY, startX);
    //mvwprintw(this->mWindows[1], 1, 1, "Welcome to Snake Game!");
    //mvwprintw(this->mWindows[1], 2, 1, "Author: Lei Mao");
}


void Game::createInstructionBoard()
{
    int startY = this->mInformationHeight;
    int startX = this->mScreenWidth - this->mInstructionWidth;
    this->mWindows[2] = newwin(this->mScreenHeight - this->mInformationHeight, this->mInstructionWidth, startY, startX);
    mvwprintw(this->mWindows[2], 1, 1, "Manual");

    mvwprintw(this->mWindows[2], 3, 1, "W: Up");
    mvwprintw(this->mWindows[2], 4, 1, "S: Down");
    mvwprintw(this->mWindows[2], 5, 1, "A: Left");
    mvwprintw(this->mWindows[2], 6, 1, "D: Right");

    mvwprintw(this->mWindows[2], 8, 1, "Difficulty");
    mvwprintw(this->mWindows[2], 11, 1, "Points");
}

void Game::initializeGame()
{
    this->mPtrSnake.reset(new Snake(this->mGameBoardWidth, this->mGameBoardHeight));
    this->createRamdonFood();
    this->mPtrSnake->senseFood(this->mFood);
}

void Game::createRamdonFood()
{
    std::vector<SnakeBody> availableGrids;
    for (int i = 1; i < this->mGameBoardHeight - 1; i ++)
    {
        for (int j = 1; j < this->mGameBoardWidth - 1; j ++)
        {
            if(this->mPtrSnake->isPartOfSnake(j, i))
            {
                continue;
            }
            else
            {
                availableGrids.push_back(SnakeBody(j, i));
            }
        }
    }

    // Randomly select a grid that is not occupied by the snake
    int random_idx = std::rand() % availableGrids.size();
    this->mFood = availableGrids[random_idx];
}



void Game::renderFood()
{
    mvwaddch(this->mWindows[1], this->mFood.getY(), this->mFood.getX(), this->mFoodSymbol);
    wrefresh(this->mWindows[1]);
}


void Game::renderSnake()
{
    int snakeLength = this->mPtrSnake->getLength();
    std::vector<SnakeBody>& snake = this->mPtrSnake->getSnake();
    for (int i = 0; i < snakeLength; i ++)
    {
        mvwaddch(this->mWindows[1], snake[i].getY(), snake[i].getX(), this->mSnakeSymbol);
    }
    wrefresh(this->mWindows[1]);
}


void Game::renderBoard()
{
    refresh();
    for (int i = 0; i < this->mWindows.size(); i ++)
    {
        box(this->mWindows[i], 0, 0);
        wrefresh(this->mWindows[i]);
    }
    //mvwaddch(this->mWindows[1], 3, 3, this->mSnakeSymbol);
    //wrefresh(this->mWindows[1]);
    bool moveSuccess;
    int key;
    while (true)
    {
        //this->mPtrSnake->changeDirection(Direction::Left);
        key=getch();
        switch(key)
        {
            case KEY_LEFT:
            {
                //std::cout << "left" << std::endl;
                this->mPtrSnake->changeDirection(Direction::Left);
                break;
            }
            case KEY_UP:
            {
                this->mPtrSnake->changeDirection(Direction::Up);
                break;
            }
            case KEY_DOWN:
            {
                this->mPtrSnake->changeDirection(Direction::Down);
                break;
            }
            case KEY_RIGHT:
            {
                this->mPtrSnake->changeDirection(Direction::Right);
                break;
            }
            default:
            {
                break;
            }
        }

        werase(this->mWindows[1]);
        box(this->mWindows[1], 0, 0);
        
        bool eatFood = this->mPtrSnake->moveFoward();
        bool collision = this->mPtrSnake->checkCollision();
        if (collision == true)
        {
            break;
        }
        this->renderSnake();
        if (eatFood == true)
        {
            this->createRamdonFood();
            this->mPtrSnake->senseFood(this->mFood);
        }
        this->renderFood();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    //std::this_thread::sleep_for(std::chrono::milliseconds(x));
    //this->renderSnake();
    refresh();
    // Get a character from keyboard before exit.
    getch();
    endwin();
}


void Game::start()
{
    this->createInformationBoard();
    this->createGameBoard();
    this->createInstructionBoard();
    this->initializeGame();

    this->renderBoard();
}
