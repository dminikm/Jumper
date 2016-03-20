#include "Headers/GameOver.h"

CGameOver::CGameOver(CGraphicsManager* graphicsManager, CButtonManager* buttonManager, CFontManager* fontManager)
{
    this->mainGraphicsManager = graphicsManager;
    this->mainFontManager = fontManager;
    this->mainButtonManager = buttonManager;
}

CGameOver::~CGameOver()
{
    
}

void CGameOver::Init(int score, SDL_Texture* messageTexture, SDL_Texture* menuButton, SDL_Texture* menuButtonPressed, SDL_Texture* menuButtonHover, SDL_Texture* continueButton, SDL_Texture* continueButtonPressed, SDL_Texture* continueButtonHover)
{
    int buttonw = 64;
    int buttonh = 64;
    
    int winw = this->mainGraphicsManager->GetWindowWidth();
    int winh = this->mainGraphicsManager->GetWindowHeight();
    
    
    this->menuButton = this->mainButtonManager->CreateButton((winw / 3) - (buttonw /2), winh * 0.8, buttonw, buttonh, menuButton, menuButtonPressed, menuButtonHover);
    this->continueButton = this->mainButtonManager->CreateButton((2 * (winw / 3)) - (buttonw /2), winh * 0.8, buttonw, buttonh, continueButton, continueButtonPressed, continueButtonHover);
    
    this->score = score;
    
    this->messageTexture = messageTexture;
}

void CGameOver::Draw()
{
    SDL_Texture* numTexture = this->mainFontManager->CreateNumTexture(this->score);
    
    int winw = this->mainGraphicsManager->GetWindowWidth();
    int winh = this->mainGraphicsManager->GetWindowHeight();
    
    int tex1w, tex1h, tex2w, tex2h;
    
    SDL_QueryTexture(this->messageTexture, NULL, NULL, &tex1w, &tex1h);
    SDL_QueryTexture(numTexture, NULL, NULL, &tex2w, &tex2h);
    
    SDL_Rect rect1;
    rect1.x = (winw / 2) - (tex1w / 2);
    rect1.y = (winh / 2) - (tex1h / 2) - 64;
    rect1.w = tex1w;
    rect1.h = tex1h;
    
    SDL_Rect rect2;
    rect2.x = (winw / 2) - (tex2w / 2);
    rect2.y = (winh / 2) - (tex2h / 2) + 64;
    rect2.w = tex2w;
    rect2.h = tex2h;
    
    this->mainGraphicsManager->CreateRenderTarget(numTexture, rect2);
    this->mainGraphicsManager->CreateRenderTarget(this->messageTexture, rect1);
}

int CGameOver::Update()
{
    if (this->menuButton->GetReleased(this->mainButtonManager->GetInputManager()))
    {
        return 0;
    }
    else if (this->continueButton->GetReleased(this->mainButtonManager->GetInputManager()))
    {
        return 1;
    }
    
    return 3;
}