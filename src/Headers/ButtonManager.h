#pragma once
#ifndef CBUTTONMANAGER_H
#define CBUTTONMANAGER_H

#include "SDL2/SDL.h"
#include "Button.h"
#include "InputManager.h"
#include "GraphicsManager.h"
#include <iostream>
#include <vector>

class CButtonManager
{
    private:
        std::vector<CButton*> buttonCatalogue;
        
        CGraphicsManager* mainGraphicsManager;
        CInputManager* mainInputManager;
        
    public:
        CButtonManager(CGraphicsManager* GraphicsManager, CInputManager* InputManager);
        ~CButtonManager();
        
        void Update();
        void Draw();
        
        CButton* CreateButton(double x, double y, double w, double h, SDL_Texture* normalTexture, SDL_Texture* pressedTexture = NULL, SDL_Texture* hoverTexture = NULL);
        void RemoveAllButtons();
        void RemoveButton(int index);
        void RemoveButton(CButton* button);
        
        CInputManager* GetInputManager();
};

#endif