#pragma once
#ifndef CGAMEOVER_H
#define CGAMEOVER_H

#include "SDL2/SDL.h"
#include "FontManager.h"
#include "GraphicsManager.h"
#include "Button.h"
#include "ButtonManager.h"

class CGameOver
{
    private:
        CGraphicsManager* mainGraphicsManager;
        CFontManager* mainFontManager;
        CButtonManager* mainButtonManager;
        
        int score;
        
        CButton* menuButton;
        CButton* continueButton;
        
        SDL_Texture* messageTexture;
    public:
        CGameOver(CGraphicsManager* graphicsManager, CButtonManager* buttonManager,CFontManager* fontManager);
        ~CGameOver();
        
        void Init(int score, SDL_Texture* messageTexture, SDL_Texture* menuButton, SDL_Texture* menuButtonPressed, SDL_Texture* menuButtonHover, SDL_Texture* continueButton, SDL_Texture* continueButtonPressed, SDL_Texture* continueButtonHover);
        int Update();
        void Draw();
};

#endif