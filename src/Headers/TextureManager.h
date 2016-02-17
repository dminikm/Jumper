#pragma once
#ifndef CTEXTUREMANAGER_H
#define CTEXTUREMANAGER_H

#include "SDL2/SDL.h"
#include <iostream>
#include <string>
#include <vector>

#undef main

class CTextureManager
{
    private:
        std::vector<SDL_Texture*> textureCatalogue;
        std::vector<std::string> textureCatalogueFileNames;
        
        SDL_Renderer* mainGameRenderer;
    public:
        CTextureManager(SDL_Renderer* renderer);
        ~CTextureManager();
        
        SDL_Texture* CreateTexture(std::string fileName);
        bool RemoveTexture(std::string fileName);
        SDL_Texture* FindTexture(std::string fileName);
        int FindTextureID(std::string fileName);
        SDL_Texture* GetTexture(int index);
};

#endif