#pragma once
#ifndef CSCOREMANAGER_H
#define CSCOREMANAGER_H

#include "SDL2/SDL.h"
#include "FontManager.h"
#include "GraphicsManager.h"

class CScoreManager 
{
    private:
        CGraphicsManager* mainGraphicsManager;
        CFontManager* mainFontManager;
        
        SDL_Texture* messageTexture;
        int messageLength;
        
        double score;
        bool counting;
    public:
        CScoreManager(CGraphicsManager* graphicsManager, CFontManager* fontManager, SDL_Texture* message, int length);
        ~CScoreManager();
        
        void Start();
        void Update(double delta);
        void Draw();
        void Stop();
        
        int GetScore();
};

#endif