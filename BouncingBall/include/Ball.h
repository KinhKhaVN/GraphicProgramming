#ifndef BALL_H
#define BALL_H
#include "Shape.h"

class Ball: public Shape{
  public:
    Ball(int _x, int _y, int _r):
      r(_r)
      {
        x = _x;
        y = _y;
        dx = 2;
        dy = 2;
      }

    void Update() override;
    void Render() override;
    void Move() override;
    virtual void checkCollisionToBorder() override;
    virtual bool isCollisionToTopBorder() override;
    virtual bool isCollisionToBottomBorder() override;
    virtual bool isCollisionToLeftBorder() override;
    virtual bool isCollisionToRightBorder() override;

  private:
    int r;
};

#endif

