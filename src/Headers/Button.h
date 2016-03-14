#pragma once
#ifndef CBUTTON_H
#define CBUTTON_H

#include "SDL2/SDL.h"
#include "InputManager.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"

class CButton 
{
    private:
        SDL_Texture* normalTexture;
        SDL_Texture* pressedTexture;
        SDL_Texture* hoverTexture;
        
        double x;
        double y;
        double w;
        double h;
        
        bool hover;
        bool pressed;
    public:
        CButton(double x, double y, double w, double h, SDL_Texture* normalTexture, SDL_Texture* pressedTexture = NULL, SDL_Texture* hoverTexture = NULL);
        ~CButton();
        
        void Draw(CGraphicsManager* graphicsManager);
        void Update(CInputManager* inputManager);
        
        SDL_Rect GetRect();
        bool GetPressed();
        bool GetReleased(CInputManager* inputManager);
        bool GetHover();
};

#endif