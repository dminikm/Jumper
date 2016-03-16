#pragma once
#ifndef CSOUNDMANAGER_H
#define CSOUNDMANAGER_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "Sound.h"
#include <iostream>
#include <string>
#include <vector>

class CSoundManager
{
    private:
        std::vector<CSound*> soundCatalogue;
        int channels;
        
    public:
        CSoundManager(int channels = 4);
        ~CSoundManager();
        
        CSound* CreateSound(std::string fileName);
        void RemoveSound(CSound* sound);
        void RemoveAllSounds();
        
        CSound* FindSound(std::string fileName);
        CSound* FindSound(Mix_Chunk* chunk);
        
        bool IsSoundPlaying(CSound* sound);
        int GetSoundChannel(CSound* sound);
        
        void PlaySound(CSound* sound, int times = 0);
        void PlaySoundTimed(CSound* sound, int time = 1000);
        void StopSound(CSound* sound);
        void PauseSound(CSound* sound);
        void ResumeSound(CSound* sound);
};

#endif