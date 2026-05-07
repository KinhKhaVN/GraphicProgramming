#include <cstdlib>
#include <ctime>
#include <iostream>
#include "include/Ball.h"
#include "include/Rectangle.h"
#include "include/raylib.h"
#include "include/main.h"


int main() {

  std::srand(std::time(NULL));
  SetTargetFPS(120);
  InitWindow(WIDTH, HEIGHT, "Boucing Shape");

  Ball ball(60 + rand() % (WIDTH - 50 + 1),
            60 + rand() % (HEIGHT - 50 + 1),
            50 );
  Rec rec(10+ rand() % (WIDTH - 300 + 1),
          10 + rand() % (HEIGHT - 100 + 1),
          200, 100);

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(BLACK);

    ball.Update();
    rec.Update();


    EndDrawing();

  }


  return 0;
}
