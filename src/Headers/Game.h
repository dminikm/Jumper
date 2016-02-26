#pragma once
#ifndef CGAME_H
#define CGAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_thread.h"
#include "SDL2/SDL_timer.h"
#include <iostream>
#include <string>
#include <thread>
#include "TextureManager.h"
#include "GraphicsManager.h"
#include "PlatformManager.h"
#include "InputManager.h"
#include "RandomGenerator.h"


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
        
        CTextureManager* mainTextureManager;
        CGraphicsManager* mainGraphicsManager;
        CPlatformManager* mainPlatformManager;
        CInputManager* mainInputManager;
        CRandomGenerator* mainRandomGenerator;
        
        unsigned int deltaLast = 0;
        unsigned int deltaNow = 0;
        double delta = 0;
        
        bool running;
    public:
        CGame();
        ~CGame();
    
        int Init(std::string gameName = "Title", int posX = SDL_WINDOWPOS_UNDEFINED, int posY = SDL_WINDOWPOS_UNDEFINED, int resX = 640, int resY = 480);
        void Run();
        void End();
        
        void Update();
        void Draw();
};

#endif