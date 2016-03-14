#include "Headers/Menu.h"

CMenu::CMenu(CGraphicsManager* graphicsManager, CInputManager* inputManager, CButtonManager* buttonManager)
{
    this->mainInputManager = inputManager;
    this->mainGraphicsManager = graphicsManager;
    this->mainTextureManager = this->mainGraphicsManager->GetTextureManager();
    this->mainButtonManager = buttonManager;
}

CMenu::~CMenu()
{
    
}

void CMenu::Init(SDL_Texture* background, SDL_Texture* playButton, SDL_Texture* playButtonPressed, SDL_Texture* playButtonHover, int playButtonW, int playButtonH)
{
    int w;
    int h;
    
    SDL_GetWindowSize(this->mainGraphicsManager->GetWindow(),&w,&h);
    
    this->mainGraphicsManager->SetBackground(background);
    this->playButton = this->mainButtonManager->CreateButton((w / 2) - (playButtonW / 2), (h / 2) - (playButtonH / 2) + 92, playButtonW, playButtonH, playButton, playButtonPressed, playButtonHover);
}

bool CMenu::Update()
{
    return this->playButton->GetReleased(this->mainInputManager);
}

void CMenu::Draw()
{
    this->mainButtonManager->Draw();
}