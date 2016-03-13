#pragma once
#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "SDL2/SDL.h"

class CCollisionManager
{
    public:
    static bool GetCollision(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2);
    static bool GetCollisionRect(SDL_Rect rect1, SDL_Rect rect2);
    static bool GetCollisionPRect(SDL_Rect* rect1, SDL_Rect* rect2);
    
};


#endif