#include "Headers/PlatformManager.h"

CPlatformManager::CPlatformManager(CGraphicsManager* graphicsManager)
{
    this->mainGraphicsManager = graphicsManager;
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
    CPlatform* platform = new CPlatform(texture, x, y, w, h);
    platformCatalogue.push_back(platform);
}

void CPlatformManager::Update(double delta)
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