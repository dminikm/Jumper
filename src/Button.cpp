#include "Headers/Button.h"

CButton::CButton(double x, double y, double w, double h, SDL_Texture* normalTexture, SDL_Texture* pressedTexture, SDL_Texture* hoverTexture)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    this->pressed = false;
    this->hover = false;
    
    this->normalTexture = normalTexture;
    
    if (pressedTexture != NULL)
    {
        this->pressedTexture = pressedTexture;
    }
    else
    {
        this->pressedTexture = this->normalTexture;
    }
    
    if (hoverTexture != NULL)
    {
        this->hoverTexture = hoverTexture;
    }
    else
    {
        this->hoverTexture = this->normalTexture;
    }
}

CButton::~CButton()
{
    
}

void CButton::Draw(CGraphicsManager* graphicsManager)
{
    SDL_Rect rect = {
        (int)this->x,
        (int)this->y,
        (int)this->w,
        (int)this->h
    };
    
    if (!this->pressed && !this->hover)
    {
        graphicsManager->CreateRenderTarget(this->normalTexture, rect);
    }
    if (this->hover)
    {
        graphicsManager->CreateRenderTarget(this->hoverTexture, rect);
    }
    if (this->pressed)
    {
        graphicsManager->CreateRenderTarget(this->pressedTexture, rect);
    }
}

void CButton::Update(CInputManager* inputManager)
{
    int mousex;
    int mousey;
    
    inputManager->GetMousePos(&mousex, &mousey);
    
    if (CCollisionManager::GetCollision(mousex, mousey, 1, 1, this->x, this->y, this->w, this->h))
    {
        if (inputManager->IsMouseDown(1))
        {
            this->hover = false;
            this->pressed = true;
        }
        else
        {
            this->hover = true;
            this->pressed = false;
        }
    }
    else
    {
        this->pressed = false;
        this->hover = false;
    }
}

SDL_Rect CButton::GetRect()
{
    SDL_Rect rect = {
        (int)this->x,
        (int)this->y,
        (int)this->w,
        (int)this->h
    };
    
    return rect;
}

bool CButton::GetPressed()
{
    return this->pressed;
}

bool CButton::GetHover()
{
    return this->hover;
}

bool CButton::GetReleased(CInputManager* inputManager)
{
    int mousex;
    int mousey;
    
    inputManager->GetMousePos(&mousex, &mousey);
    
    if (CCollisionManager::GetCollision(mousex, mousey, 1, 1, this->x, this->y, this->w, this->h) && inputManager->GetMouseReleased() == 1)
    {
        return true;
    }
    return false;
}
