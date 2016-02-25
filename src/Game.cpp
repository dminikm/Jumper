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
    
    this->mainTextureManager = new CTextureManager(this->mainGameRenderer);
    this->mainGraphicsManager = new CGraphicsManager(this->mainGameRenderer, this->mainGameWindow);
    this->mainPlatformManager = new CPlatformManager(this->mainGraphicsManager);
<<<<<<< HEAD
<<<<<<< HEAD
    this->mainInputManager = new CInputManager(&this->mainGameEvent);
=======
>>>>>>> a0740abe57096b8f50acb49e7ba0cc21cbfdc3c6
=======
>>>>>>> a0740abe57096b8f50acb49e7ba0cc21cbfdc3c6
    
    this->mainGraphicsManager->SetBackground(this->mainTextureManager->CreateTexture("Art/background.bmp"), true, 0, SDL_FLIP_NONE);
    
    this->running = true;
    return 0;
}

void CGame::End()
{
    this->running = false;
    SDL_DestroyWindow(this->mainGameWindow);
    SDL_DestroyRenderer(this->mainGameRenderer);
    SDL_Quit();
}

void CGame::Run()
{  
<<<<<<< HEAD
<<<<<<< HEAD
    while (this->running)
    {
        this->Update();
        this->Draw();
    }
}

void CGame::Update()
{
    this->deltaNow = SDL_GetTicks();
    this->delta = (double)(((double)this->deltaNow - (double)this->deltaLast) / 1000);
    this->deltaLast = this->deltaNow;
        
    SDL_RenderClear(this->mainGameRenderer);
    SDL_PollEvent(&this->mainGameEvent);
    
    if (this->mainGameEvent.type == SDL_QUIT)
    {
        this->End();
=======
=======
>>>>>>> a0740abe57096b8f50acb49e7ba0cc21cbfdc3c6
    while (true)
    {
        this->deltaNow = SDL_GetTicks();
        this->delta = (double)(((double)this->deltaNow - (double)this->deltaLast) / 1000);
        this->deltaLast = this->deltaNow;
        
        SDL_RenderClear(this->mainGameRenderer);
        SDL_PollEvent(&this->mainGameEvent);
        if (this->mainGameEvent.type == SDL_QUIT)
        {
            this->End();
            break;
        }
        
        this->mainPlatformManager->Update(this->delta);
        this->mainPlatformManager->Draw();
        
        this->mainGraphicsManager->Draw();
        this->mainGraphicsManager->ClearRenderCatalogue();
        SDL_RenderPresent(this->mainGameRenderer);
>>>>>>> a0740abe57096b8f50acb49e7ba0cc21cbfdc3c6
    }
        
        
this->mainPlatformManager->Update(this->delta);
 
}

void CGame::Draw()
{
    this->mainPlatformManager->Draw();
    this->mainGraphicsManager->Draw();
    this->mainGraphicsManager->ClearRenderCatalogue();
    SDL_RenderPresent(this->mainGameRenderer);

}