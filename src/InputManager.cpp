#include "Headers/InputManager.h"

CInputManager::CInputManager(SDL_Event* event)
{
    this->mainGameEvent = event;
    this->mouseButtonStates.resize(5);
}

CInputManager::~CInputManager()
{
    
}

bool CInputManager::IsKeyDown(SDL_Scancode key)
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    return (keystate[key] == 1);
}

bool CInputManager::IsKeyUp(SDL_Scancode key)
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    return (keystate[key] == 0);
}

SDL_Scancode CInputManager::GetPressedKey()
{
    if (this->mainGameEvent->type == SDL_KEYDOWN)
    {
        return this->mainGameEvent->key.keysym.scancode;
    }
    else
    {
        return SDL_SCANCODE_LANG6;
    }
}

SDL_Scancode CInputManager::GetReleasedKey()
{
    if (this->mainGameEvent->type == SDL_KEYUP)
    {
        return this->mainGameEvent->key.keysym.scancode;
    }
    else
    {
        return SDL_SCANCODE_LANG6;
    }
}

bool CInputManager::IsMouseDown(Uint8 button)
{
    if (button > this->mouseButtonStates.size())
    {
        this->mouseButtonStates.resize(button + 1);
    }
    return this->mouseButtonStates[button];
}

bool CInputManager::IsMouseUp(Uint8 button)
{
    if (button > this->mouseButtonStates.size())
    {
        this->mouseButtonStates.resize(button + 1);
    }
    return !this->mouseButtonStates[button];
}

Uint8 CInputManager::GetMousePressed()
{
    if (this->mainGameEvent->type == SDL_MOUSEBUTTONDOWN)
    {
        return this->mainGameEvent->button.button;
    }
    else
    {
        return 0;
    }
}

Uint8 CInputManager::GetMouseReleased()
{
    if (this->mainGameEvent->type == SDL_MOUSEBUTTONUP)
    {
        return this->mainGameEvent->button.button;
    }
    else
    {
        return 0;
    }
}

void CInputManager::GetMousePos(int* x, int* y)
{
    SDL_GetMouseState(x, y);
}

void CInputManager::Update()
{
    for (int i = 0; i < this->mouseButtonStates.size(); i++)
    {
        if (this->mouseButtonStates[i])
        {
            if (this->GetMouseReleased() == i)
            {
                this->mouseButtonStates[i] = false;
            }
        }
        else
        {
            if (this->GetMousePressed() == i)
            {
                this->mouseButtonStates[i] = true;
            }
        }
    }
}