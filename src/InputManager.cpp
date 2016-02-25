#include "Headers/InputManager.h"

CInputManager::CInputManager(SDL_Event* event)
{
    this->mainGameEvent = event;
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
    return (this->mainGameEvent->type == SDL_MOUSEBUTTONDOWN && this->mainGameEvent->button.button == button);
}

bool CInputManager::IsMouseUp(Uint8 button)
{
    return (this->mainGameEvent->type == SDL_MOUSEBUTTONUP && this->mainGameEvent->button.button == button);
}

Uint8 CInputManager::GetMouseDown()
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

Uint8 CInputManager::GetMouseUp()
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

void GetMousePos(int* x, int* y)
{
    SDL_GetMouseState(&x, &y);
}