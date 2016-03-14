#include "Headers/Platform.h"

CPlatform::CPlatform(SDL_Texture* texture, double x, double y, double w, double h, CRandomGenerator* randomGenerator)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->texture = texture;
    
    this->velocity = randomGenerator->GetRandomBetween(30, 40);
}

CPlatform::~CPlatform()
{
    
}

void CPlatform::Update(double delta)
{
    this->y = this->y + (this->velocity * delta);
}

void CPlatform::Draw(CGraphicsManager* graphicsManager)
{
    SDL_Rect rect;
    rect.x = (int)this->x;
    rect.y = (int)this->y;
    rect.w = (int)this->w;
    rect.h = (int)this->h;
    
    graphicsManager->CreateRenderTarget(this->texture, rect, 0.00, NULL, 0, SDL_FLIP_NONE);
}

bool CPlatform::IsBelowScreen(SDL_Window* window)
{
    int winH;
    SDL_GetWindowSize(window, NULL, &winH);
    
    return this->y > winH;
}

SDL_Rect CPlatform::GetRect()
{
    SDL_Rect rect;
    rect.x = this->x;
    rect.y = this->y;
    rect.w = this->w;
    rect.h = this->h;
    
    return rect;
}

int CPlatform::GetVelocity()
{
    return this->velocity;
}
