#include "snake.h"

#include <iostream>
#include <memory>

int main()
{
    Snake snake = Snake(36, 24);
    std::cout << snake.getLength() << std::endl;
    std::vector<SnakeBody>& snakeBodies = snake.getSnake();
    std::cout << snakeBodies.size() << std::endl;
    for (int i = 0; i < snakeBodies.size(); i ++)
    {
        std::cout << snakeBodies[i].getX() << " " << snakeBodies[i].getY() << " " << std::endl;
    }
    std::cout << snakeBodies.size() << std::endl;

    std::unique_ptr<Snake> mPtrSnake;
    mPtrSnake.reset(new Snake(80, 40));
    std::vector<SnakeBody>& snake2 = mPtrSnake->getSnake();
    std::cout << snake2.size() << std::endl;
    for (int i = 0; i < snake2.size(); i ++)
    {
        std::cout << snake2[i].getX() << " " << snake2[i].getY() << " " << std::endl;
    }

    mPtrSnake->moveFoward();
    std::cout << mPtrSnake->getLength() << std::endl;
    mPtrSnake->moveFoward();
    std::cout << mPtrSnake->getLength() << std::endl;

}