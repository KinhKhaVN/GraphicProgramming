#include "../include/Ball.h"
#include <chrono>
#include <cstdlib>
#include <iostream>

void Ball::Update()
{
  Render();
  Move();
  handleCollisionToBorder();
}

void Ball::Render()
{
  if ( isCollisionToBorder() ) countCollide++;
  if (countCollide > 20) countCollide = 1;

  DrawCircle(x, y, r, colors[countCollide % 20]);
}

void Ball::Move()
{
  x += dx;
  y += dy;
}

void Ball::handleCollisionToBorder()
{
  if (isCollisionToTopBorder())
  {
    y = r;
    dy = -dy;
    isCollided = true;
  }

  if (isCollisionToBottomBorder())
  {
    y = HEIGHT - r;
    dy = -dy;
    isCollided = true;
  }

  if (isCollisionToLeftBorder())
  {
    x = r;
    dx = -dx;
    isCollided = true;
  }

  if (isCollisionToRightBorder())
  {
    x = WIDTH - r;
    dx = -dx;
    isCollided = true;
  }
}

bool Ball::isCollisionToBorder()
{
  return isCollisionToTopBorder()   ||
         isCollisionToBottomBorder()||
         isCollisionToLeftBorder()  ||
         isCollisionToRightBorder();
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
