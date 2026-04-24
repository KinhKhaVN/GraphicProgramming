#include "raylib.h"
#include "Food.h"
#include "main.h"
#include "utility.h"

Food::Food(std::deque<Vector2> snakeBody)
{
        Image image = LoadImage("./assert/food.png");
        ImageResize(&image, CELL_SIZE * 1.2, CELL_SIZE * 1.2);
        textture = LoadTextureFromImage(image);
        pos = generateRandomPos(snakeBody);
        UnloadImage(image);
}

Food::~Food()
{
        UnloadTexture(textture);
}

void Food::Draw()
{
        DrawTexture(textture, pos.x * CELL_SIZE, pos.y * CELL_SIZE, LIGHTGRAY);
}

void Food::Update()
{

}

Vector2 Food::generateRandomCell()
{
        float x = GetRandomValue(0, CELL_COUNT - 1);
        float y = GetRandomValue(0, CELL_COUNT - 1);
        return Vector2{x, y};
}

Vector2 Food::generateRandomPos(std::deque<Vector2> snakeBody)
{
        Vector2 position = generateRandomCell();

        while (elementInDeque(position, snakeBody)) {
                position = generateRandomCell();
        }

        return position;
}
