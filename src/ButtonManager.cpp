#include "Headers/ButtonManager.h"

CButtonManager::CButtonManager(CGraphicsManager* graphicsManager, CInputManager* inputManager)
{
    this->mainGraphicsManager = graphicsManager;
    this->mainInputManager = inputManager;
    
    this->buttonCatalogue.resize(0);
}

CButtonManager::~CButtonManager()
{
    
}

void CButtonManager::Update()
{
    for (int i = 0; i < this->buttonCatalogue.size(); i++)
    {
        this->buttonCatalogue[i]->Update(this->mainInputManager);
    }
}

void CButtonManager::Draw()
{
    for (int i = 0; i < this->buttonCatalogue.size(); i++)
    {
        this->buttonCatalogue[i]->Draw(this->mainGraphicsManager);
    }
}

CButton* CButtonManager::CreateButton(double x, double y, double w, double h, SDL_Texture* normalTexture, SDL_Texture* pressedTexture, SDL_Texture* hoverTexture)
{
    CButton* button = new CButton(x,y,w,h,normalTexture,pressedTexture,hoverTexture);
    this->buttonCatalogue.push_back(button);
}

void CButtonManager::RemoveAllButtons()
{
    for (int i = 0; i < this->buttonCatalogue.size(); i++)
    {
        this->buttonCatalogue[i]->~CButton();
    }
    this->buttonCatalogue.resize(0);
}

void CButtonManager::RemoveButton(int index)
{
    if (index < this->buttonCatalogue.size())
    {
        this->buttonCatalogue[index]->~CButton();
        this->buttonCatalogue.erase(this->buttonCatalogue.begin() + index);
    }
}

void CButtonManager::RemoveButton(CButton* button)
{
    for (int i = 0; i < this->buttonCatalogue.size(); i++)
    {
        if (button == this->buttonCatalogue[i])
        {
            this->buttonCatalogue[i]->~CButton();
            this->buttonCatalogue.erase(this->buttonCatalogue.begin() + i);
        }
    }
}