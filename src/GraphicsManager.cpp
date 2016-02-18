#include "Headers/GraphicsManager.h"

CGraphicsManager::CGraphicsManager(SDL_Renderer* renderer)
{
    this->mainGameRenderer = renderer;
}

CGraphicsManager::~CGraphicsManager()
{
    
}

void CGraphicsManager::CreateRenderTarget(SDL_Texture* texture, SDL_Rect* rect, double angle, SDL_Point* centre, unsigned int depth, SDL_RendererFlip flip)
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
    for (int i = 0; i < this->renderCatalogue.size(); i++)
    {
        for (int o = 0; o < this->renderCatalogue[i].size(); o++)
        {
            SDL_RenderCopyEx(this->mainGameRenderer, this->renderCatalogue[i][o].texture, NULL, this->renderCatalogue[i][o].rect, this->renderCatalogue[i][o].angle, this->renderCatalogue[i][o].centre, this->renderCatalogue[i][o].flip);
        }
    }
}