#include "Headers/Game.h"

CGame::CGame()
{
    
}

CGame::~CGame()
{
    this->mainRandomGenerator->~CRandomGenerator();
    this->mainTextureManager->~CTextureManager();
    this->mainGraphicsManager->~CGraphicsManager();
    this->mainPlatformManager->~CPlatformManager();
    this->mainInputManager->~CInputManager();
    this->mainPlayer->~CPlayer();
    this->mainFontManager->~CFontManager();
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
    this->mainGameRenderer = SDL_CreateRenderer(this->mainGameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    
    if (!this->mainGameWindow  && !this->mainGameRenderer)
    {
        return 1;
    }
    
    this->mainRandomGenerator = new CRandomGenerator();
    this->mainTextureManager = new CTextureManager(this->mainGameRenderer, this->mainRandomGenerator);
    this->mainGraphicsManager = new CGraphicsManager(this->mainGameRenderer, this->mainGameWindow, this->mainTextureManager);
    this->mainPlatformManager = new CPlatformManager(this->mainGraphicsManager, this->mainRandomGenerator);
    this->mainInputManager = new CInputManager(&this->mainGameEvent);
    this->mainPlayer = new CPlayer(this->mainGraphicsManager, this->mainInputManager, this->mainPlatformManager);
    this->mainFontManager = new CFontManager(this->mainGraphicsManager, this->mainTextureManager->CreateTexture("Art/numsheet.bmp"));
    this->mainButtonManager = new CButtonManager(this->mainGraphicsManager, this->mainInputManager);
    this->mainMenu = new CMenu(this->mainGraphicsManager, this->mainInputManager, this->mainButtonManager);
    
    this->mainGraphicsManager->SetBackground(this->mainTextureManager->CreateTexture("Art/background.bmp"), true, 0, SDL_FLIP_NONE);
    
    this->running = true;
    this->gameState = this->gameMenuInit;
    
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
    while (this->running)
    {
        if (this->gameState == this->gameMenuInit)
        {
            this->mainButtonManager->RemoveAllButtons();
            this->mainPlatformManager->RemoveAllPlatforms();
            this->mainPlayer->DespawnPlayer();
            this->mainMenu->Init(this->mainTextureManager->CreateTexture("Art/menubackground.bmp"),this->mainTextureManager->CreateTexture("Art/start.bmp"),this->mainTextureManager->CreateTexture("Art/startpressed.bmp"),this->mainTextureManager->CreateTexture("Art/starthover.bmp"),64, 64);
            this->gameState = this->gameMenu;
        }
        if (this->gameState == this->gameMenu)
        {
            SDL_PollEvent(&this->mainGameEvent);
            if (this->mainGameEvent.type == SDL_QUIT)
            {
                this->End();
            }
            
            this->mainInputManager->Update();
            this->mainButtonManager->Update();
            
            if (this->mainMenu->Update())
            {
                this->gameState = this->gameInit;
            }
            
            this->mainMenu->Draw();
            this->Draw();
        }
        if (this->gameState == this->gameInit)
        {
            this->mainButtonManager->RemoveAllButtons();
            this->mainPlatformManager->RemoveAllPlatforms();
            this->mainPlayer->SpawnPlayer((this->mainGraphicsManager->GetWindowWidth() / 2) - this->mainPlayer->GetPlayerRect().w / 2, (this->mainGraphicsManager->GetWindowHeight() / 2) - this->mainPlayer->GetPlayerRect().h / 2);
            this->mainPlatformManager->CreatePlatform(this->mainTextureManager->CreateTexture("Art/platform.bmp"), ((this->mainGraphicsManager->GetWindowWidth() / 2) - this->mainPlayer->GetPlayerRect().w / 2) - 64, ((this->mainGraphicsManager->GetWindowHeight() / 2) - this->mainPlayer->GetPlayerRect().h / 2) + 128, 128, 32);
            this->mainPlatformManager->CreatePlatform(this->mainTextureManager->CreateTexture("Art/platform.bmp"), this->mainRandomGenerator->GetRandomBetween(0, this->mainGraphicsManager->GetWindowWidth() - 128), 140, 128, 32);
            this->mainPlatformManager->CreatePlatform(this->mainTextureManager->CreateTexture("Art/platform.bmp"), this->mainRandomGenerator->GetRandomBetween(0, this->mainGraphicsManager->GetWindowWidth() - 128), 25, 128, 32);
            this->mainGraphicsManager->SetBackground(this->mainTextureManager->CreateTexture("Art/background.bmp"), true, 0, SDL_FLIP_NONE);
            this->gameState = this->gamePlay;
            
            
        }
        if (this->gameState == this->gamePlay)
        {
            this->Update();
            this->Draw();
        }
        
    }
}

void CGame::Update()
{
    this->deltaNow = SDL_GetTicks();
    this->delta = (double)(((double)this->deltaNow - (double)this->deltaLast) / 1000);
    this->deltaLast = this->deltaNow;

    
    SDL_PollEvent(&this->mainGameEvent);
    this->mainInputManager->Update();
    
    if (this->mainGameEvent.type == SDL_QUIT)
    {
        this->End();
    }
    
    
    this->mainPlayer->Update(this->delta);
    this->mainPlatformManager->Update(this->delta);
    
    if (this->mainPlayer->GetPlayerRect().y + this->mainPlayer->GetPlayerRect().h + 1 > this->winHeight || this->mainInputManager->IsKeyDown(SDL_SCANCODE_ESCAPE))
    {
        this->gameState = this->gameMenuInit;
    }
    
}

void CGame::Draw()
{
    this->mainPlatformManager->Draw();
    this->mainPlayer->Draw();
    this->mainGraphicsManager->Draw();
    this->mainButtonManager->Draw();
    this->mainGraphicsManager->ClearRenderCatalogue();
    SDL_RenderPresent(this->mainGameRenderer);
    SDL_RenderClear(this->mainGameRenderer);
}