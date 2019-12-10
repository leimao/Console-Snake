#include "snake.h"
#include <string>
#include <cstdlib>

Snake::Snake(int gameBoardWidth, int gameBoardHeight): mGameBoardWidth(gameBoardWidth), mGameBoardHeight(mGameBoardHeight)
{
}



void Snake::initializeSnake()
{
    // Instead of using a random initialization algorithm
    // We always put the snake at the center of the game board
    int centerX = this->mGameBoardWidth / 2;
    int centerY = this->mGameBoardHeight / 2;
    for (int i = 0; i < this->mInitialSnakeLength; i ++)
    {
        this->mSnake.push_back(SnakeBody(centerX, centerY + i));
    }
    this->mSnake.push_back(SnakeBody(centerX, centerY));
    this->mDirection = Direction::Up;
}



bool Snake::isPartOfSnake(int x, int y)
{
    SnakeBody temp = SnakeBody(x, y);
    for (int i = 0; i < this->mSnake.size(); i ++)
    {
        if (this->mSnake[i] == temp)
        {
            return true;
        }
    }
    return false;
}

/*
 * Assumption:
 * Only the head would hit wall.
 */
bool Snake::hitWall()
{
    SnakeBody& head = this->mSnake[0];
    int headX = head.getX();
    int headY = head.getY();
    if (headX < 0 || headX >= this->mGameBoardWidth)
    {
        return true;
    }
    if (headY < 0 || headY >= this->mGameBoardHeight)
    {
        return true;
    }
    return false;
}

/*
 * The snake head is overlapping with its body
 */
bool Snake::hitSelf()
{
    SnakeBody& head = this->mSnake[0];
    // Exclude the snake head
    for (int i = 1; i < this->mSnake.size(); i ++)
    {
        if (this->mSnake[i] == head)
        {
            return true;
        }
    }
    return false;
}


bool Snake::touchFood()
{
    SnakeBody& head = this->mSnake[0];
    int headX = head.getX();
    int headY = head.getY();
    int headXNext;
    int headYNext;
    switch (this->mDirection)
    {
        case Direction::Up:
        {
            headXNext = headX;
            headYNext = headY - 1;
            break;
        }
        case Direction::Down:
        {
            headXNext = headX;
            headYNext = headY + 1;
            break;
        }
        case Direction::Left:
        {
            headXNext = headX - 1;
            headYNext = headY;
            break;
        }
        case Direction::Right:
        {
            headXNext = headX + 1;
            headYNext = headY;
            break;
        }
    }
    if (this->mFood == SnakeBody(headXNext, headYNext))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Snake::grow()
{
    // Create a copy of food
    SnakeBody newBody = this->mFood;
    if (this->touchFood())
    {
        // Put the new body to the head of the snake
        this->mSnake.insert(this->mSnake.begin(), newBody); 
        return true;
    }
    else
    {
        return false;
    }
}


void Snake::senseFood(SnakeBody food)
{
    this->mFood = food;
}


std::vector<SnakeBody>& Snake::getSnake()
{
    return this->mSnake;
}


bool Snake::changeDirection(Direction newDirection)
{
    switch (this->mDirection)
    {
        case Direction::Up:
        {
            if (newDirection == Direction::Left || newDirection == Direction::Right)
            {
                this->mDirection = newDirection;
                return true;
            }
            else
            {
                return false;
            }
        }
        case Direction::Down:
        {
            if (newDirection == Direction::Left || newDirection == Direction::Right)
            {
                this->mDirection = newDirection;
                return true;
            }
            else
            {
                return false;
            }
        }
        case Direction::Left:
        {
            if (newDirection == Direction::Up || newDirection == Direction::Down)
            {
                this->mDirection = newDirection;
                return true;
            }
            else
            {
                return false;
            }
        }
        case Direction::Right:
        {
            if (newDirection == Direction::Up || newDirection == Direction::Down)
            {
                this->mDirection = newDirection;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}


/*
bool Snake::moveFoward()
{bool changeDirection(Direction newDirection);
    SnakeBody lastBody = this->mSnake[this->mSnake.size()-1];
    SnakeBody 
}
*/