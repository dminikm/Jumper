#ifndef CGRAPHICSMANAGER_H
#define CGRAPHICSMANAGER_H

#include "SDL2/SDL.h"
#include <vector>
#include <iostream>


struct RenderTarget {
            SDL_Texture* texture;
            SDL_Point* centre;
            SDL_Rect rect;
            SDL_RendererFlip flip;
            double angle;
};

class CGraphicsManager 
{
    private:
        std::vector<std::vector<RenderTarget>> renderCatalogue;
        RenderTarget background;
        
        SDL_Renderer* mainGameRenderer;
        SDL_Window* mainGameWindow;
        
    public:
        CGraphicsManager(SDL_Renderer* renderer, SDL_Window* window);
        ~CGraphicsManager();
        
        void CreateRenderTarget(SDL_Texture* texture, SDL_Rect rect, double angle, SDL_Point* centre, unsigned int depth, SDL_RendererFlip flip);
        void SetBackground(SDL_Texture* texture, bool fit, double angle, SDL_RendererFlip flip);
        void ClearRenderCatalogue();
        
        void Draw();
        
        SDL_Renderer* GetRenderer();
        SDL_Window* GetWindow();
};
#endif