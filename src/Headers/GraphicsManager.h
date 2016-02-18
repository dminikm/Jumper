#ifndef CGRAPHICSMANAGER_H
#define CGRAPHICSMANAGER_H

#include "SDL2/SDL.h"
#include <vector>
#include <iostream>

struct RenderTarget {
            SDL_Texture* texture;
            SDL_Point* centre;
            SDL_Rect* rect;
            SDL_RendererFlip flip;
            double angle;
};

class CGraphicsManager 
{
    private:
        std::vector<std::vector<RenderTarget>> renderCatalogue;
        
        SDL_Renderer* mainGameRenderer;
        
        
    public:
        CGraphicsManager(SDL_Renderer* renderer);
        ~CGraphicsManager();
        
        void CreateRenderTarget(SDL_Texture* texture, SDL_Rect* rect, double angle, SDL_Point* centre, unsigned int depth, SDL_RendererFlip flip);
        void ClearRenderCatalogue();
        
        void Draw();
        
        
};
#endif