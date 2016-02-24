#pragma once
#ifndef PLATFORMMANAGER_H
#define PLATFORMMANAGER_H

#include <iostream>
#include <vector>
#include "SDL2/SDL.h"
#include "GraphicsManager.h"
#include "Platform.h"

class CPlatformManager 
{
    private: 
        std::vector<CPlatform*> platformCatalogue;
        CGraphicsManager* mainGraphicsManager;
        
    public:
        CPlatformManager(CGraphicsManager* graphicsManager);
        ~CPlatformManager();
        
        void CreatePlatform(SDL_Texture* texture, double x, double y, double w, double h);
        
        void Update(double delta);
        void Draw();
        
        void RemovePlatform(int index);
};

#endif