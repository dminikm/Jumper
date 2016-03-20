#include "Headers/FontManager.h"

CFontManager::CFontManager(CGraphicsManager* graphicsManager, SDL_Texture* numericSheet)
{
    this->mainGraphicsManager = graphicsManager;
    this->mainTextureManager = this->mainGraphicsManager->GetTextureManager();
    this->mainGameWindow = this->mainGraphicsManager->GetWindow();
    this->mainGameRenderer = this->mainGraphicsManager->GetRenderer();
    this->numSheet = numericSheet;
    this->targetTexture = SDL_CreateTexture(this->mainGameRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1, 1);
}

CFontManager::~CFontManager()
{
    SDL_DestroyTexture(this->targetTexture);
    SDL_DestroyTexture(this->numSheet);
}

std::string CFontManager::ConvertIntToString(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

SDL_Texture* CFontManager::CreateNumTexture(int number)
{
    SDL_DestroyTexture(this->targetTexture);
    std::string numString = this->ConvertIntToString(number);
    Uint32 format;
    int w;
    int h; 
    
    SDL_QueryTexture(this->numSheet, &format, NULL, &w, &h);
    
    this->targetTexture = SDL_CreateTexture(this->mainGameRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, numString.size() * (w / 11), h);
    SDL_SetRenderTarget(this->mainGameRenderer, this->targetTexture);
    SDL_SetTextureBlendMode(this->targetTexture, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(this->mainGameRenderer, 0,0,0,0); 
    SDL_RenderClear(this->mainGameRenderer);

    SDL_Rect rect1;
    rect1.x = 0;
    rect1.y = 0;
    rect1.w = w / 11;
    rect1.h = h;
    
    SDL_Rect rect2;
    rect2.x = 0;
    rect2.y = 0;
    rect2.w = w / 11;
    rect2.h = h;

    for (int i = 0; i < numString.size(); i++)
    {
        rect1.x = i * (w / 11);
        rect2.x = (atoi(numString.substr(i, 1).c_str())) * (w / 11);
        if (numString.substr(i, 1) == "-")
        {
            rect2.x = w - (w / 11); 
        }
        
        SDL_RenderCopy(this->mainGameRenderer, this->numSheet, &rect2, &rect1);
    }
    
    SDL_SetRenderTarget(this->mainGameRenderer, NULL);
    return this->targetTexture;
}