#include "../include/Rectangle.h"


void Rec::Update()
{
  Render();
  Move();
  handleCollisionToBorder();
}

void Rec::Render()
{
  if ( isCollisionToBorder() ) countCollide++;
  if (countCollide > 20) countCollide = 1;

  DrawRectangle(x, y, width, height, colors[countCollide % 20]);
}

void Rec::Move()
{
  x += dx;
  y += dy;
}

void Rec::handleCollisionToBorder()
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

bool Rec::isCollisionToBorder()
{
  return isCollisionToTopBorder()   ||
         isCollisionToBottomBorder()||
         isCollisionToLeftBorder()  ||
         isCollisionToRightBorder();
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
