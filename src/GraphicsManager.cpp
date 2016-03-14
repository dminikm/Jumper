#include "Headers/GraphicsManager.h"

CGraphicsManager::CGraphicsManager(SDL_Renderer* renderer, SDL_Window* window, CTextureManager* textureManager)
{
    this->mainGameRenderer = renderer;
    this->mainGameWindow = window;
    this->mainTextureManager = textureManager;
}

CGraphicsManager::~CGraphicsManager()
{
    
}

void CGraphicsManager::CreateRenderTarget(SDL_Texture* texture, SDL_Rect rect, double angle, SDL_Point* centre, unsigned int depth, SDL_RendererFlip flip)
{
      RenderTarget renderTarget;
      renderTarget.texture = texture;
      renderTarget.centre = centre;
      renderTarget.rect = rect;
      renderTarget.flip = flip;
      renderTarget.angle = angle;
       
      if (depth + 1 > this->renderCatalogue.size())
      {
          this->renderCatalogue.resize(depth + 1);
      }
      
      this->renderCatalogue[depth].push_back(renderTarget);
}

void CGraphicsManager::ClearRenderCatalogue()
{
    this->renderCatalogue.erase(this->renderCatalogue.begin(),this->renderCatalogue.end());
}

void CGraphicsManager::Draw()
{
    SDL_RenderCopyEx(this->mainGameRenderer, this->background.texture, NULL, &this->background.rect, this->background.angle, this->background.centre, this->background.flip);
    for (int i = 0; i < this->renderCatalogue.size(); i++)
    {
        for (int o = 0; o < this->renderCatalogue[i].size(); o++)
        {
            SDL_RenderCopyEx(this->mainGameRenderer, this->renderCatalogue[i][o].texture, NULL, &this->renderCatalogue[i][o].rect, this->renderCatalogue[i][o].angle, this->renderCatalogue[i][o].centre, this->renderCatalogue[i][o].flip);
        }
    }
}

void CGraphicsManager::SetBackground(SDL_Texture* texture, bool fit, double angle, SDL_RendererFlip flip)
{
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
    if (fit)
    {
        SDL_GetWindowSize(this->mainGameWindow, &rect.w, &rect.h);
    }
    else
    {
        SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    }

    this->background.texture = texture;
    this->background.centre = NULL;
    this->background.rect = rect;
    this->background.flip = flip;
    this->background.angle = angle;
}

SDL_Renderer* CGraphicsManager::GetRenderer()
{
    return this->mainGameRenderer;
}

SDL_Window* CGraphicsManager::GetWindow()
{
    return this->mainGameWindow;
}

CTextureManager* CGraphicsManager::GetTextureManager()
{
    return this->mainTextureManager;
}

int CGraphicsManager::GetWindowWidth()
{
    int w;
    SDL_GetWindowSize(this->mainGameWindow, &w, NULL);
    return w;
}

int CGraphicsManager::GetWindowHeight()
{
    int h;
    SDL_GetWindowSize(this->mainGameWindow, NULL, &h);
    return h;
}

