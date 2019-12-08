#include "snake.h"
#include <string>
#include <cstdlib>

Snake::Snake()
{
    this->board.resize(3);
    initscr();
    noecho();
    getmaxyx(stdscr, this->screenHeight, this->screenWidth);
    this->createInformationBoard();
    this->createGameBoard();
    this->createInstructionBoard();
}

void Snake::createInformationBoard()
{
    int startY = 0;
    int startX = 0;
    this->board[0] = newwin(this->informationHeight, this->screenWidth, startY, startX);
    mvwprintw(this->board[0], 1, 1, "Welcome to Snake Game!");
    mvwprintw(this->board[0], 2, 1, "Author: Lei Mao");
}

void Snake::createGameBoard()
{
    int startY = this->informationHeight;
    int startX = 0;
    this->board[1] = newwin(this->screenHeight - this->informationHeight, this->screenWidth - this->instructionWidth, startY, startX);
    //mvwprintw(this->board[1], 1, 1, "Welcome to Snake Game!");
    //mvwprintw(this->board[1], 2, 1, "Author: Lei Mao");
}


void Snake::createInstructionBoard()
{
    int startY = this->informationHeight;
    int startX = this->screenWidth - this->instructionWidth;
    this->board[2] = newwin(this->screenHeight - this->informationHeight, this->instructionWidth, startY, startX);
    mvwprintw(this->board[2], 1, 1, "Manual");
    /*
    std::string s1(1, char(24));
    std::string s2(1, char(25));
    std::string s3(1, char(26));
    std::string s4(1, char(27));
    */
   std::string s1 = "W: Up";
   std::string s2 = "S: Down";
   std::string s3 = "A: Left";
   std::string s4 = "D: Right";
    //s1 = ":";
    mvwprintw(this->board[2], 3, 1, "W: Up");
    mvwprintw(this->board[2], 4, 1, "S: Down");
    mvwprintw(this->board[2], 5, 1, "A: Left");
    mvwprintw(this->board[2], 6, 1, "D: Right");

    mvwprintw(this->board[2], 8, 1, "Difficulty");
    mvwprintw(this->board[2], 11, 1, "Points");
}


void Snake::renderBoard()
{
    refresh();
    for (int i = 0; i < this->board.size(); i ++)
    {
        box(this->board[i], 0, 0);
        wrefresh(this->board[i]);
    }
    refresh();
    // Get a character from keyboard before exit.
    getch();
    endwin();
}

void Snake::start()
{
    this->createInformationBoard();
    this->createGameBoard();
    this->renderBoard();
}

bool Snake::isCollision(int x, int y)
{
    for (int i = 0; i < this->snake.size(); i ++)
    {
        if (this->snake[i].getX == x && this->snake[i].getY == y)
        {
            return true;
        }
    }
    return false;
}


void Snake::createFood()
{
    int gameBoardWidth = this->screenHeight - this->instructionWidth;
    int gameBoardHeight = this->screenWidth - this->informationHeight;

    std::vector<SnakeBody> availableGrids;
    for (int i = 1; i < gameBoardHeight - 1; i ++)
    {
        for (int j = 1; j < gameBoardWidth - 1; i ++)
        {
            if(this->isCollision(j, i))
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
    SnakeBody food = availableGrids[random_idx];
    
    
}



SnakeBody::SnakeBody(int x, int y): x(x), y(y)
{
}

int SnakeBody::getX() const
{
    return this->x;
}

int SnakeBody::getY() const
{
    return this->y;
}


bool SnakeBody::operator == (const SnakeBody& snakeBody)
{
    if (snakeBody.getX() == this->getX() && snakeBody.getY() == this->getY())
    {
        return true;
    }
    else
    {
        return false;
    }
}




