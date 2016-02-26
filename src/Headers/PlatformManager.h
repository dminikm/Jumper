#pragma once
#ifndef PLATFORMMANAGER_H
#define PLATFORMMANAGER_H

#include <iostream>
#include <vector>
#include <chrono>
#include "SDL2/SDL.h"
#include "RandomGenerator.h"
#include "GraphicsManager.h"
#include "Platform.h"

class CPlatformManager 
{
    private: 
        std::vector<CPlatform*> platformCatalogue;
        CGraphicsManager* mainGraphicsManager;
        CRandomGenerator* mainRandomGenerator;
        
        int maxPlatforms;
        double platformSpawnTime;
        double platformSpawnCounter;
        
        void UpdatePlatforms(double delta);
        
        int screenW;
        int screenH;
        int paddleW = 128;
        int paddleH = 32;
        
    public:
        CPlatformManager(CGraphicsManager* graphicsManager, CRandomGenerator* randomGenerator , int maxAmount = 6, double time = 2.5);
        ~CPlatformManager();
        
        void CreatePlatform(SDL_Texture* texture, double x, double y, double w, double h);
        
        void Update(double delta);
        void Draw();
        
        void RemovePlatform(int index);
        
        void SetSpawnTime(unsigned int time);
        void SetMaxPlatforms(int amount);
        
        unsigned int GetSpawnTime();
        int GetMaxPlatforms();
};

#endif