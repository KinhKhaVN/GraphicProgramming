#ifndef BALL_H
#define BALL_H
#include "Shape.h"
#include "math.h"

class Ball: public Shape{
  public:
    Ball(int _x, int _y, int _r):
      r(_r)
      {
        x          = _x;
        y          = _y;
        dx         = 2;
        dy         = 2;
        speed      = 5;
        isCollided = false;
      }

    void Update() override;
    void Render() override;
    void Move() override;
    virtual void handleCollisionToBorder()   override;
    virtual bool isCollisionToBorder()       override;
    virtual bool isCollisionToTopBorder()    override;
    virtual bool isCollisionToBottomBorder() override;
    virtual bool isCollisionToLeftBorder()   override;
    virtual bool isCollisionToRightBorder()  override;

  public:
    int r;
};

#endif

