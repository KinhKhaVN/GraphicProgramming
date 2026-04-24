#ifndef UTILITY_H
#define UTILITY_H


#include "include/raylib.h"
#include "include/raymath.h"
#include <deque>

bool eventTriggered(double interval);
bool elementInDeque(Vector2 element, std::deque<Vector2> deque);




#endif
