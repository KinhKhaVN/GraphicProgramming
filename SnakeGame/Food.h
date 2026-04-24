#ifndef FOOD_H
#define FOOD_H

#include "include/raylib.h"
#include <deque>


class Food 
{
  public:
    Vector2 pos = {5, 6};
    Texture2D textture;
  public:
    Food(std::deque<Vector2> snakeBody);
    ~Food();

    void Draw();
    void Update();

    Vector2 generateRandomCell();
    Vector2 generateRandomPos(std::deque<Vector2> snakeBody);

};

#endif
