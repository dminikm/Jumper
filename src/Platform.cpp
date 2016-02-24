#include "Headers/Platform.h"

CPlatform::CPlatform(SDL_Texture* texture, double x, double y, double w, double h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->texture = texture;
    
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(20,45);
    
    this->velocity = uni(rng);
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