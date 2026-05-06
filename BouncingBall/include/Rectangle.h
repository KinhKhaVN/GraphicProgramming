#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../include/Shape.h"



class Rec:public Shape{
  public:
    Rec(int _x, int _y, int _w, int _h):
      width(_w),
      height(_h)
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
    int width;
    int height;
};


#endif
