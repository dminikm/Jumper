#include "Headers/Sound.h"

CSound::CSound(std::string fileName)
{
    this->sound = Mix_LoadWAV(fileName.c_str());
    std::cout << Mix_GetError();
    this->volume = 1;
    this->fileName = fileName;
    this->active = false;
}

CSound::~CSound()
{
    Mix_FreeChunk(this->sound);
}

Mix_Chunk* CSound::GetSound()
{
    return this->sound;
}

std::string CSound::GetFileName()
{
    return this->fileName;
}

double CSound::GetVolume()
{
    return this->volume;
}

void CSound::SetVolume(double volume)
{
    volume = std::min(1.00, volume);
    volume = std::max(0.00, volume);
    
    this->volume = volume;
}

void CSound::SetPlaying(bool state)
{
    this->active = state;
}

bool CSound::GetActive()
{
    return this->active;
}
