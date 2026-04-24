#include <cstdlib>
#include <ctime>
#include <limits>
#include <set>

#include "main.h"
#include "include/raylib.h"
#include "include/raymath.h"
#include "Food.h"
#include "Snake.h"
#include "Game.h"
#include "utility.h"
//#include "utility.cpp"
//#include "Game.cpp"
//#include "Food.cpp"
//#include "Snake.cpp"

int main ()
{
  SetTargetFPS(FPS);
  InitWindow(+ CELL_COUNT*CELL_SIZE, CELL_COUNT*CELL_SIZE, "Snake Game");

  Game game = Game();

  PlayMusicStream(game.gamePlayMusic);

  while (!WindowShouldClose()) {
    DrawFPS(10, 10);
    DrawText(TextFormat("%i", game.score), 10, 30, 40, RED);
    ClearBackground(LIGHTGRAY);

    UpdateMusicStream(game.gamePlayMusic);


    BeginDrawing();
    if (eventTriggered(0.1))
    {
      game.Update();
    }
    if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1)
    {
      game.snake.direction = {0, -1};
      game.isRunning = true;
    }
    if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1)
    {
      game.snake.direction = {0, 1};
      game.isRunning = true;
    }
    if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1)
    {
      game.snake.direction = {-1, 0};
      game.isRunning = true;
    }
    if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1)
    {
      game.snake.direction = {1, 0};
      game.isRunning = true;
    }

    game.Draw();

    game.drawGrid(CELL_COUNT, CELL_COUNT, CELL_SIZE, WHITE);

    game.checkPausing();
    // Lose game
    if (!game.isRunning)
    {
      game.drawMessageBoxGameOver();
      PauseMusicStream(game.gamePlayMusic);
    }else if (game.isPausing) // Pause game
    {
      game.drawMessageBoxGamePause();
      PauseMusicStream(game.gamePlayMusic);
    }else ResumeMusicStream(game.gamePlayMusic);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
