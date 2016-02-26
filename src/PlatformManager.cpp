#include "Headers/PlatformManager.h"

CPlatformManager::CPlatformManager(CGraphicsManager* graphicsManager, CRandomGenerator* randomGenerator, int maxAmount, double time)
{
    this->mainGraphicsManager = graphicsManager;
    this->mainRandomGenerator = randomGenerator;
    this->maxPlatforms = maxAmount;
    this->platformSpawnTime = time;
    this->platformSpawnCounter = 0;
    
    SDL_GetWindowSize(this->mainGraphicsManager->GetWindow(), &this->screenW, &this->screenH);
}

CPlatformManager::~CPlatformManager()
{
    for (int i = 0; i < this->platformCatalogue.size(); i ++)
    {
        platformCatalogue[i]->~CPlatform();
    }
}

void CPlatformManager::CreatePlatform(SDL_Texture* texture, double x, double y, double w, double h)
{
    CPlatform* platform = new CPlatform(texture, x, y, w, h, this->mainRandomGenerator);
    platformCatalogue.push_back(platform);
}

void CPlatformManager::Update(double delta)
{
    this->UpdatePlatforms(delta);
    this->platformSpawnCounter += delta;
    if (this->platformSpawnCounter >= this->platformSpawnTime && this->platformCatalogue.size() < this->maxPlatforms)
    {
        this->CreatePlatform(this->mainGraphicsManager->GetTextureManager()->CreateTexture("Art/platform.bmp"), this->mainRandomGenerator->GetRandomBetween(0, this->screenW - this->paddleW), -32,this->paddleW, this->paddleH);
        this->platformSpawnCounter = 0;
    }
}

void CPlatformManager::UpdatePlatforms(double delta)
{
    for (int i = 0; i < this->platformCatalogue.size(); i ++)
    {
        if (this->platformCatalogue[i]->IsBelowScreen(this->mainGraphicsManager->GetWindow()))
        {
            this->RemovePlatform(i);
            i--;
        }
        else
        {
            platformCatalogue[i]->Update(delta);     
        } 
    }
}

void CPlatformManager::Draw()
{
    for (int i = 0; i < this->platformCatalogue.size(); i ++)
    {
        platformCatalogue[i]->Draw(this->mainGraphicsManager);
    }
}

void CPlatformManager::RemovePlatform(int index)
{
    if (index < this->platformCatalogue.size() && index >= 0)
    {
        platformCatalogue.erase(platformCatalogue.begin() + index);
    }
}

void CPlatformManager::SetSpawnTime(unsigned int time)
{
    this->platformSpawnTime = time;
}

void CPlatformManager::SetMaxPlatforms(int amount)
{
    this->maxPlatforms = amount;
}

unsigned int CPlatformManager::GetSpawnTime()
{
    return this->platformSpawnTime;
}

int CPlatformManager::GetMaxPlatforms()
{
    return this->maxPlatforms;
}