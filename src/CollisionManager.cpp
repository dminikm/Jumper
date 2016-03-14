#include "Headers/CollisionManager.h"

bool CCollisionManager::GetCollision(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2)
{
    return x1 < x2+w2 && x2 < x1+w1 && y1 < y2+h2 && y2 < y1+h1;
}

bool CCollisionManager::GetCollisionRect(SDL_Rect rect1, SDL_Rect rect2)
{
    return CCollisionManager::GetCollision(rect1.x, rect1.y, rect1.w, rect1.h, rect2.x, rect2.y, rect2.w, rect2.h);
}

bool CCollisionManager::GetCollisionPRect(SDL_Rect* rect1, SDL_Rect* rect2)
{
    return CCollisionManager::GetCollision(rect1->x, rect1->y, rect1->w, rect1->h, rect2->x, rect2->y, rect2->w, rect2->h);
}