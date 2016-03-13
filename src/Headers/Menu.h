#pragma once
#ifndef CMENU_H
#define CMENU_H

#include "SDL2/SDL.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "ButtonManager.h"
#include "Button.h"

class CMenu
{
    private:
        CGraphicsManager* mainGraphicsManager;
        CInputManager* mainInputManager;
        CTextureManager* mainTextureManager;
        CButtonManager* mainButtonManager;
        
        CButton* playButton;
    public:
        CMenu(CGraphicsManager* graphicsManager, CInputManager* inputManager, CButtonManager* buttonManager);
        ~CMenu();
        
        void Init(SDL_Texture* background, SDL_Texture* playButton, SDL_Texture* playButtonPressed, SDL_Texture* playButtonHover, int playButtonW, int playButtonH);
        
        void Draw();
        bool Update();
    
};
#endif