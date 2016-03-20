#include "Headers/ScoreManager.h"

CScoreManager::CScoreManager(CGraphicsManager* graphicsManager, CFontManager* fontManager, SDL_Texture* message, int length)
{
    this->score = 0;
    this->mainGraphicsManager = graphicsManager;
    this->mainFontManager = fontManager;
    this->counting = false;
    this->messageTexture = message;
    this->messageLength = length;
}

CScoreManager::~CScoreManager()
{
    
}

void CScoreManager::Start()
{
    this->counting = true;
    this->score = 0;
}

void CScoreManager::Update(double delta)
{
    if (this->counting)
    {
        this->score += delta;
    }
}

void CScoreManager::Draw()
{
    if (this->counting)
    {
        SDL_Texture* texture = this->mainFontManager->CreateNumTexture((int)this->score);
        
        int winw;
        int winh;
        int texw;
        int texh;
        int tex2w;
        int tex2h;
    
        winw = this->mainGraphicsManager->GetWindowWidth();
        winh = this->mainGraphicsManager->GetWindowHeight();
        SDL_QueryTexture(texture, NULL, NULL, &texw, &texh);
        SDL_QueryTexture(this->messageTexture, NULL, NULL, &tex2w, &tex2h);
        
        SDL_Rect rect;
        rect.x = winw - (texw * 0.25);
        rect.y = 0;
        rect.w = texw * 0.25;
        rect.h = texh * 0.25;
        
        SDL_Rect rect2;
        rect2.x = rect.x - (tex2w * 0.25)- 4;
        rect2.y = 0;
        rect2.w = (tex2w * 0.25);
        rect2.h = texh * 0.25;
        
        this->mainGraphicsManager->CreateRenderTarget(texture, rect);
        this->mainGraphicsManager->CreateRenderTarget(this->messageTexture, rect2);
    }
}

void CScoreManager::Stop()
{
    this->counting = false;
}

int CScoreManager::GetScore()
{
    return this->score;
}