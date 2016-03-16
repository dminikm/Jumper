#include "Headers/SoundManager.h"

CSoundManager::CSoundManager(int channels)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, channels, 2048);
    std::cout << Mix_GetError() << std::endl;
    this->soundCatalogue.resize(0);
    this->channels = channels;
}

CSoundManager::~CSoundManager()
{
    this->RemoveAllSounds();
    Mix_CloseAudio();
}

CSound* CSoundManager::CreateSound(std::string fileName)
{
    CSound* sound = new CSound(fileName);
    this->soundCatalogue.push_back(sound);
    return this->soundCatalogue[this->soundCatalogue.size() - 1];
}

void CSoundManager::RemoveSound(CSound* sound)
{
    for (int i = 0; i < this->soundCatalogue.size(); i++)
    {
        if (this->soundCatalogue[i] == sound)
        {
            this->soundCatalogue[i]->~CSound();
            this->soundCatalogue.erase(this->soundCatalogue.begin() + i);
            i--;
        }
    }
}

void CSoundManager::RemoveAllSounds()
{
    for (int i = 0; i < soundCatalogue.size(); i++)
    {
        this->soundCatalogue[i]->~CSound();
    }
    this->soundCatalogue.resize(0); 
}

CSound* CSoundManager::FindSound(std::string fileName)
{
    for (int i = 0; i < this->soundCatalogue.size(); i++)
    {
        if (this->soundCatalogue[i]->GetFileName() == fileName)
        {
            return this->soundCatalogue[i];
        }
    }
}

CSound* CSoundManager::FindSound(Mix_Chunk* chunk)
{
    for (int i = 0; i < this->soundCatalogue.size(); i++)
    {
        if (this->soundCatalogue[i]->GetSound() == chunk)
        {
            return this->soundCatalogue[i];
        }
    }
}

bool CSoundManager::IsSoundPlaying(CSound* sound)
{
    for (int i = 0; i < this->channels; i++)
    {
        if (Mix_GetChunk(i) == sound->GetSound())
        {
            return true;
        }
    }
    return false;
}

int CSoundManager::GetSoundChannel(CSound* sound)
{
    for (int i = 0; i < this->channels; i++)
    {
        if (Mix_GetChunk(i) == sound->GetSound())
        {
            return i;
        }
    }
    return -1;
}

void CSoundManager::PlaySound(CSound* sound, int times)
{
    for (int i = 0; i < this->channels; i++)
    {
        if (!Mix_Playing(i))
        {
            Mix_Volume(i, MIX_MAX_VOLUME * sound->GetVolume());
            Mix_PlayChannel(i, sound->GetSound(), times);
            break;
        }
    }    
}

void CSoundManager::PlaySoundTimed(CSound* sound, int time)
{
    for (int i = 0; i < this->channels; i++)
    {
        if (!Mix_Playing(i))
        {
            Mix_Volume(i, MIX_MAX_VOLUME * sound->GetVolume());
            Mix_PlayChannelTimed(i, sound->GetSound(), 0, time);
            break;
        }
    } 
}

void CSoundManager::StopSound(CSound* sound)
{
    int channel = this->GetSoundChannel(sound);
    if (!(channel > this->channels || channel < 0))
    {
        Mix_HaltChannel(channel);
    }
}

void CSoundManager::PauseSound(CSound* sound)
{
    int channel = this->GetSoundChannel(sound);
    if (!(channel > this->channels || channel < 0))
    {
        Mix_Pause(channel);
    }
}

void CSoundManager::ResumeSound(CSound* sound)
{
    int channel = this->GetSoundChannel(sound);
    if (!(channel > this->channels || channel < 0))
    {
        Mix_Resume(channel);
    }
}