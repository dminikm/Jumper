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
#include "Player.h"
#include "FontManager.h"
#include "ButtonManager.h"
#include "Menu.h"
#include "SoundManager.h"
#include "ScoreManager.h"
#include "GameOver.h"

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
        
        CSoundManager* mainSoundManager;
        CTextureManager* mainTextureManager;
        CGraphicsManager* mainGraphicsManager;
        CPlatformManager* mainPlatformManager;
        CInputManager* mainInputManager;
        CRandomGenerator* mainRandomGenerator;
        CPlayer* mainPlayer;
        CFontManager* mainFontManager;
        CButtonManager* mainButtonManager;
        CMenu* mainMenu;
        CScoreManager* mainScoreManager;
        CGameOver* mainGameOver;
        
        
        
        unsigned int deltaLast = 0;
        unsigned int deltaNow = 0;
        double delta = 0;

        bool running;
        
        int gameState;
        //const int gameIntro = 0;
        const int gameMenu = 1;
        const int gameMenuInit = 2;
        const int gameInit = 3;
        const int gamePlay = 4;
        const int gameOverInit = 5;
        const int gameOver = 6;
    public:
        CGame();
        ~CGame();
    
        int Init(std::string gameName = "Title", int posX = SDL_WINDOWPOS_UNDEFINED, int posY = SDL_WINDOWPOS_UNDEFINED, int resX = 640, int resY = 480);
        void Run();
        void End();
        
        void Update();
        void Draw();

#ifdef __EMSCRIPTEN__
        void SingleIteration();
        friend void WebLoopIteration(void* arg);
#endif
};

#endif