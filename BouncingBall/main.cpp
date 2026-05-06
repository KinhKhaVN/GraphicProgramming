#include <iostream>
#include "include/Ball.h"
#include "include/Rectangle.h"
#include "include/main.h"


int main() {

  SetTargetFPS(60);
  InitWindow(WIDTH, HEIGHT, "Boucing Shape");

  Ball ball(WIDTH / 2, HEIGHT / 2, 50);
  Rec rec(WIDTH / 2, HEIGHT / 2, 100, 50);

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(BLACK);

    ball.Update();
    rec.Update();

    EndDrawing();

  }


  return 0;
}
