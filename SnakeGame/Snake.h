#ifndef SNAKE_H
#define SNAKE_H

#include "include/raylib.h"
#include "main.h"
#include <deque>

class Snake
{
  public:
    bool addSegment = false;
    float speed = 0.05;
    Vector2 direction = {1, 0};
    Vector2 pos = {WIDTH / 2.0, HEIGHT / 2.0};
    std::deque<Vector2> snakeReset = {Vector2{6, 9}};
    std::deque<Vector2> body = {Vector2{6, 9}};
  public:
    Snake();
    ~Snake();

    void Draw();
    void Update();
    void Reset();
};



#endif
