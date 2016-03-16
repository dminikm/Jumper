#pragma once
#ifndef CSOUND_H
#define CSOUND_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include <iostream>
#include <algorithm>
#include <string>

class CSound
{
    private:
        std::string fileName;
        Mix_Chunk* sound;
        double volume;
        bool active;
        
    public:
        CSound(std::string fileName);
        ~CSound();
        
        Mix_Chunk* GetSound();
        std::string GetFileName();
        double GetVolume();
        bool GetActive();
        
        void SetVolume(double volume);
        void SetPlaying(bool state);
};

#endif