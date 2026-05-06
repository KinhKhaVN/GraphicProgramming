#include "../include/Rectangle.h"


void Rec::Update()
{
  Render();
  Move();
  checkCollisionToBorder();
}

void Rec::Render()
{
  DrawRectangle(x, y, width, height, WHITE);
}

void Rec::Move()
{
  x += dx;
  y += dy;
}

void Rec::checkCollisionToBorder()
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

bool Rec::isCollisionToTopBorder()
{
  return y <= 0;
}

bool Rec::isCollisionToBottomBorder()
{
  return y + height >= HEIGHT;
}
bool Rec::isCollisionToLeftBorder()
{
  return x <= 0;
}
bool Rec::isCollisionToRightBorder()
{
  return x + width >= WIDTH;
}
