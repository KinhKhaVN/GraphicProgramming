#ifndef GAME_H
#define GAME_H

#include "Food.h"
#include "Snake.h"
#include "include/raylib.h"
#include <deque>



class Game
{
  public:
    bool isRunning = true;
    bool isPausing = false;
    int score = 0;
    Snake snake = Snake();
    Food food = Food(snake.body);
    Food food2 = Food(snake.body);
    Sound eatSound;
    Sound wallSound;
    Music gamePlayMusic;
  public:
    Game();
    ~Game();

    bool isAnyKeyPressed();

    void Draw();
    void Update();

    void checkPausing();
    void checkCollisionWithFood();
    void checkCollisionWithEdges();
    void checkCollisionWithTail();
    void drawMessageBoxGameOver();
    void drawMessageBoxGamePause();
    void drawGrid(int columns, int rows, int cellSize, Color color);
    void gameOver();
};

#endif
