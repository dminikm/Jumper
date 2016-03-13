#ifndef CGRAPHICSMANAGER_H
#define CGRAPHICSMANAGER_H

#include "SDL2/SDL.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "TextureManager.h"


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
        CTextureManager* mainTextureManager;
        
        //std::vector<SDL_Texture*> localNumFonts;
        
        template <typename T>
        std::string to_string(T value)
        {
            std::ostringstream os ;
            os << value ;
            return os.str() ;
        }
    public:
        CGraphicsManager(SDL_Renderer* renderer, SDL_Window* window, CTextureManager* textureManager);
        ~CGraphicsManager();
        
        void CreateRenderTarget(SDL_Texture* texture, SDL_Rect rect, double angle = 0.00, SDL_Point* centre = NULL, unsigned int depth = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void SetBackground(SDL_Texture* texture, bool fit = true, double angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void ClearRenderCatalogue();
        
        void Draw();
        
        SDL_Renderer* GetRenderer();
        SDL_Window* GetWindow();
        CTextureManager* GetTextureManager();
        
        int GetWindowWidth();
        int GetWindowHeight();
};
#endif