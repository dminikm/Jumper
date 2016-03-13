#pragma once
#ifndef CPLATFORM_H

#include "SDL2/SDL.h"
#include <iostream>
#include <random>
#include "GraphicsManager.h"
#include "RandomGenerator.h"

class CPlatform 
{
    private:
    double x;
    double y;
    double w;
    double h;
    
    SDL_Texture* texture;
    
    int velocity;
    
    public:
    CPlatform(SDL_Texture* texture, double x, double y, double w, double h, CRandomGenerator* randomGenerator);
    ~CPlatform();
    
    SDL_Rect GetRect();
    void Update(double delta);
    void Draw(CGraphicsManager* graphicsManager);
    
    bool IsBelowScreen(SDL_Window* window);
};

#endif