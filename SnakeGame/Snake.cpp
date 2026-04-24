#include "main.h"
#include "raylib.h"
#include "Snake.h"
#include "raymath.h"

Snake::Snake()
{

}

Snake::~Snake()
{

}




void Snake::Draw()
{
  for (size_t i = 0; i < body.size(); i++)
  {
    int x = body[i].x;
    int y = body[i].y;
    Rectangle segment = Rectangle{(float)x * CELL_SIZE, (float)y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
    if ( i & 1)
      DrawRectangleRounded(segment, 1.0 ,6, DARKBROWN);
    else
      DrawRectangleRounded(segment, 1.0 ,6, GREEN);
  }
}

void Snake::Update()
{
  body.push_front(Vector2Add(body[0], direction));
  if (addSegment == true)
    addSegment = false;
  else
    body.pop_back();
}

void Snake::Reset()
{
  body = snakeReset;
  direction = {0,1};
}
