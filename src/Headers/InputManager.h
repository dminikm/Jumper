#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "SDL2/SDL.h"
#include <iostream>
#include <vector>

class CInputManager 
{
    private:
        SDL_Event* mainGameEvent;
        
        std::vector<bool> mouseButtonStates;
    public:
        CInputManager(SDL_Event* event);
        ~CInputManager();
        
        void Update();
        
        bool IsKeyDown(SDL_Scancode key);
        bool IsKeyUp(SDL_Scancode key);
        SDL_Scancode GetPressedKey();
        SDL_Scancode GetReleasedKey();
        
        bool IsMouseDown(Uint8 button);
        bool IsMouseUp(Uint8 button);
        Uint8 GetMousePressed();
        Uint8 GetMouseReleased();
        
        void GetMousePos(int* x, int* y);
};
#endif