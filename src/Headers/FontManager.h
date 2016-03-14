#pragma once
#ifndef CFONTMANAGER_H
#define CFONTMANAGER_H

#include "SDL2/SDL.h"
#include "TextureManager.h"
#include "GraphicsManager.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

class CFontManager
{
    private:
        CTextureManager* mainTextureManager;
        CGraphicsManager* mainGraphicsManager;
        SDL_Window* mainGameWindow;
        SDL_Renderer* mainGameRenderer;

        SDL_Texture* numSheet;
        SDL_Texture* targetTexture;
    
        std::string ConvertIntToString(int number);
    public:
        CFontManager(CGraphicsManager* graphicsManager, SDL_Texture* numericSheet);
        ~CFontManager();
        
        SDL_Texture* CreateNumTexture(int number);
};

#endif