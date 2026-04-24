#include "utility.h"
#include "raylib.h"
#include "raymath.h"
#include <deque>
#include <exception>

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
        double currentTime = GetTime();
        
        if (currentTime - lastUpdateTime >= interval)
        {
                lastUpdateTime = currentTime;
                return true;
        }
        return false;
}

bool elementInDeque(Vector2 element, std::deque<Vector2> deque)
{
        for (size_t i = 0; i < deque.size(); i++)
        {
                if (Vector2Equals(deque[i], element))
                {
                        return true;
                }
        }
        return false;
}
