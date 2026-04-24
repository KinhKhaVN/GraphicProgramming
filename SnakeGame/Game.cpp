#include <deque>

#include "raylib.h"
#include "main.h"
#include "raymath.h"
#include "utility.h"
#include "Game.h"



Game::Game()
{
  InitAudioDevice();
  eatSound = LoadSound("./assert/mixkit-hungry-man-eating-2252.wav");
  wallSound = LoadSound("./assert/uh_pjRnSML.mp3");
  gamePlayMusic = LoadMusicStream("./assert/gamePlayMusic.mp3");
  SetSoundVolume(eatSound, 1.0);
  SetMusicVolume(gamePlayMusic, 0.5);
}

Game::~Game()
{
  UnloadSound(eatSound);
  UnloadSound(wallSound);
  UnloadMusicStream(gamePlayMusic);
  CloseAudioDevice();
}

void Game::Draw()
{
  snake.Draw();
  food.Draw();
  food2.Draw();
}

void Game::Update()
{
  if (isRunning && (!isPausing))
  {
    snake.Update();
    food.Update();
    food2.Update();

    checkCollisionWithEdges();
    checkCollisionWithFood();
    checkCollisionWithTail();
  }
}

bool Game::isAnyKeyPressed()
{
  int key = GetKeyPressed();

  if (key)
  {
    return true;
  }        

  return false;
}

void Game::drawMessageBoxGameOver()
{
  DrawRectangle(CELL_COUNT * CELL_SIZE / 5, 300, 600, 300, DARKPURPLE);
  DrawText("GAME OVER!", 
      CELL_COUNT * CELL_SIZE / 2.6, 
      350, 
      40, 
      WHITE);
  DrawText("Press arrow key to start new game",
      CELL_COUNT*CELL_SIZE/4.3, 
      450, 
      30, 
      WHITE);
  if (isAnyKeyPressed())
    isRunning = true;
}


void Game::drawMessageBoxGamePause()
{
  DrawRectangle(CELL_COUNT * CELL_SIZE / 5, 300, 600, 300, DARKPURPLE);
  DrawText("GAME PAUSE", 
      CELL_COUNT * CELL_SIZE / 2.6, 
      350, 
      40, 
      WHITE);
  DrawText("Press space to resume game",
      CELL_COUNT*CELL_SIZE/3.8, 
      450, 
      30, 
      WHITE);
}

void Game::drawGrid(int columns, int rows, int cellSize, Color color)
{
  for (int i = 0; i < columns; i++) 
    DrawLine(i*cellSize, 0, i*cellSize, rows*cellSize, color);

  for (int i = 0; i < rows; i++) 
    DrawLine(0, i*cellSize, columns*cellSize, i*cellSize, color);
}

void Game::gameOver()
{
  snake.Reset();
  food.pos = food.generateRandomPos(snake.body);
  isRunning = false;
  score = 0;
}

void Game::checkCollisionWithFood()
{
  Vector2 head = snake.body[0];

  if (Vector2Equals(head, food.pos))
  {
    food.pos = food.generateRandomPos(snake.body);
    snake.addSegment = true;
    score++;
    PlaySound(eatSound);
    return;
  }

  if (Vector2Equals(head, food2.pos))
  {
    food2.pos = food.generateRandomPos(snake.body);
    snake.addSegment = true;
    score++;
    PlaySound(eatSound);
    return;
  }
}

void Game::checkCollisionWithEdges()
{
  Vector2 head = snake.body[0];

  if (head.x == CELL_COUNT || head.x <= -1) PlaySound(wallSound), gameOver();
  if (head.y == CELL_COUNT || head.y <= -1) PlaySound(wallSound), gameOver();

}


void Game::checkCollisionWithTail()
{
  Vector2 head = snake.body[0];
  std::deque<Vector2> bodyHeadLess = snake.body;

  bodyHeadLess.pop_front();

  if (elementInDeque(head, bodyHeadLess))
  {
    PlaySound(wallSound);
    gameOver();
  }
}

void Game::checkPausing()
{
  if (IsKeyPressed(KEY_SPACE))
    isPausing = !isPausing;

  if (isPausing) PauseMusicStream(gamePlayMusic);
  else ResumeMusicStream(gamePlayMusic);
}
