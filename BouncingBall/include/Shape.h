#ifndef SHAPE_H
#define SHAPE_H

#include "../include/raylib.h"
#include "../include/main.h"

class Shape{
  public:
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Move() = 0;
    virtual void handleCollisionToBorder() = 0;
    virtual bool isCollisionToBorder() = 0;
    virtual bool isCollisionToTopBorder() = 0;
    virtual bool isCollisionToBottomBorder() = 0;
    virtual bool isCollisionToLeftBorder() = 0;
    virtual bool isCollisionToRightBorder() = 0;

  public:
    double speed;
    int x;
    int y;
    int dx;
    int dy;
    bool isCollided;
    Color color = WHITE;
};



#endif
