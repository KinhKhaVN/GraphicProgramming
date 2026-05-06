#include "../include/Ball.h"
#include <iostream>

void Ball::Update()
{
  Render();
  Move();
  checkCollisionToBorder();
}

void Ball::Render()
{
  DrawCircle(x, y, r, WHITE);
}

void Ball::Move()
{
  x += dx;
  y += dy;
  std::cout << "(" << x << "," << y << ")" << '\n';
}

void Ball::checkCollisionToBorder()
{
  if (isCollisionToTopBorder() || isCollisionToBottomBorder()) 
  {
    dy = -dy;
  };
  
  if (isCollisionToLeftBorder() || isCollisionToRightBorder())
  {
    dx = -dx;
  }
}

bool Ball::isCollisionToTopBorder()
{
  return y - r <= 0;
}

bool Ball::isCollisionToBottomBorder()
{
  return y + r >= HEIGHT;
}
bool Ball::isCollisionToLeftBorder()
{
  return x - r <= 0;
}
bool Ball::isCollisionToRightBorder()
{
  return x + r >= WIDTH;
}
