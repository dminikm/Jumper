#pragma once
#ifndef CGAME_H
#define CGAME_H

#include "SDL2/SDL.h"
#include <iostream>
#include <string>

#undef main

class CGame
{
    private:
        SDL_Window* mainGameWindow;
        SDL_Renderer* mainGameRenderer;
        SDL_Event mainGameEvent;
        
        std::string gameName;
        int winPosX;
        int winPosY;
        int winWidth;
        int winHeight; 
        
        
    public:
        CGame();
        ~CGame();
    
        int Init(std::string gameName = "Title", int posX = SDL_WINDOWPOS_UNDEFINED, int posY = SDL_WINDOWPOS_UNDEFINED, int resX = 640, int resY = 480);
        void Run();
        void End();
};

#endif