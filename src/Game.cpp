#include "Headers/Game.h"



CGame::CGame()
{
    
}

CGame::~CGame()
{
    
}

int CGame::Init(std::string gameName, int posX, int posY, int resX, int resY)
{
    this->gameName = gameName;
    this->winPosX = posX;
    this->winPosY = posY;
    this->winWidth = resX;
    this->winHeight = resY;
    
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER );
    this->mainGameWindow = SDL_CreateWindow(this->gameName.c_str(), this->winPosX, this->winPosY, this->winWidth, this->winHeight, SDL_WINDOW_SHOWN);
    this->mainGameEvent = SDL_Event();
    this->mainGameRenderer = SDL_CreateRenderer(this->mainGameWindow, -1, SDL_RENDERER_ACCELERATED);
    
    if (!this->mainGameWindow  && !this->mainGameRenderer)
    {
        return 1;
    }
    
    this->mainTextureManager = new CTextureManager(mainGameRenderer);
    this->mainGraphicsManager = new CGraphicsManager(mainGameRenderer);
    
    return 0;
}

void CGame::End()
{
    SDL_DestroyWindow(this->mainGameWindow);
    SDL_DestroyRenderer(this->mainGameRenderer);
    SDL_Quit();
}

void CGame::Run()
{
    while (true)
    {
        SDL_RenderClear(this->mainGameRenderer);
        SDL_PollEvent(&this->mainGameEvent);
        if (this->mainGameEvent.type == SDL_QUIT)
        {
            this->End();
            break;
        }
        
        this->mainGraphicsManager->Draw();
        
        SDL_RenderPresent(this->mainGameRenderer);
    }
}