#include "game.h"
#include <string>


Game::Game()
{
    this->board.resize(3);
    initscr();
    noecho();
    getmaxyx(stdscr, this->screenHeight, this->screenWidth);
}


void Game::createInformationBoard()
{
    int startY = 0;
    int startX = 0;
    this->board[0] = newwin(this->informationHeight, this->screenWidth, startY, startX);
    mvwprintw(this->board[0], 1, 1, "Welcome to Snake Game!");
    mvwprintw(this->board[0], 2, 1, "Author: Lei Mao");
}

void Game::createGameBoard()
{
    int startY = this->informationHeight;
    int startX = 0;
    this->board[1] = newwin(this->screenHeight - this->informationHeight, this->screenWidth - this->instructionWidth, startY, startX);
    //mvwprintw(this->board[1], 1, 1, "Welcome to Snake Game!");
    //mvwprintw(this->board[1], 2, 1, "Author: Lei Mao");
}


void Game::createInstructionBoard()
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


void Game::renderBoard()
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


void Game::start()
{
    this->createInformationBoard();
    this->createGameBoard();
    this->createInstructionBoard();
    this->renderBoard();
}


void Game::renderTest()
{
    while (true)
    {
        
    }
}