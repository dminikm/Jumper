#include "Headers/Player.h"

CPlayer::CPlayer(CGraphicsManager* graphicsManager, CInputManager* inputManager, CPlatformManager* platformManager, CSoundManager* soundManager)
{
    this->mainGraphicsManager = graphicsManager;
    this->mainInputManager = inputManager;
    this->mainPlatformManager = platformManager;
    this->mainSoundManager = soundManager;
    this->playerSprite = this->mainGraphicsManager->GetTextureManager()->CreateTexture("Art/player.bmp");
    this->playerSpriteJump = this->mainGraphicsManager->GetTextureManager()->CreateTexture("Art/playerjump.bmp");
    this->flipLeft = false;
    this->active = false;
    this->jumpSound = this->mainSoundManager->CreateSound("Sound/jump.wav");
}

CPlayer::~CPlayer()
{
    
}

void CPlayer::Update(double delta)
{
    if (this->active)
    {
        this->HandleCollision();
        this->Controll(delta);
        this->ApplyFriction(delta);
        this->ApplyGravity(delta);
        this->HandleSprite(delta);
        this->ApplyMotion(delta);
        this->BindToScreen(delta);
    }
}

void CPlayer::Draw()
{
    if (this->active)
    {
    SDL_Rect rect;
    rect.x = this->x;
    rect.y = this->y;
    rect.w = this->w;
    rect.h = this->h;
    
    if (flipLeft)
    {
        if (this->jumping)
        {
            this->mainGraphicsManager->CreateRenderTarget(this->playerSpriteJump, rect, 0, NULL, 1, SDL_FLIP_HORIZONTAL);
        }
        else
        {
            this->mainGraphicsManager->CreateRenderTarget(this->playerSprite, rect, 0, NULL, 1, SDL_FLIP_HORIZONTAL);
        }
    }
    else
    {
        if (this->jumping)
        {
            this->mainGraphicsManager->CreateRenderTarget(this->playerSpriteJump, rect, 0, NULL, 1, SDL_FLIP_NONE);
        }
        else
        {
            this->mainGraphicsManager->CreateRenderTarget(this->playerSprite, rect, 0, NULL, 1, SDL_FLIP_NONE);
        }
    }
    }
}

void CPlayer::SpawnPlayer(double x, double y, double w, double h, double velocityXMax, double velocityYMax, double velocityAddition, double gravity, double friction)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->velocityXMax = velocityXMax;
    this->velocityYMax = velocityYMax;
    this->velocityY = 0;
    this->velocityX = 0;
    this->velocityAddition = velocityAddition;
    this->active = true;
    this->flipLeft = false;
    this->jumping = false;
    this->gravity = gravity;
    this->friction = friction;
}

void CPlayer::DespawnPlayer()
{
    this->active = false;
}

bool CPlayer::IsPlayerSpawned()
{
    return this->active;
}

void CPlayer::BindToScreen(double delta)
{
    int winx;
    int winy;
    SDL_GetWindowSize(this->mainGraphicsManager->GetWindow(), &winx, &winy);
    this->x = std::min(this->x, (double)winx - this->w);
    this->x = std::max(this->x, 0.00);
    this->y = std::min(this->y, winy - this->h);
    this->y = std::max(this->y, 0.00);
    
    if (this->y == 0)
    {
        this->velocityY = 0;
        this->y = 1;
    }
    if (this->x == winx - this->w || this->x == 0)
    {
        this->velocityX = 0;
    }
}

void CPlayer::ApplyMotion(double delta)
{
    this->x += this->velocityX * delta;
    this->y += this->velocityY * delta;
}

void CPlayer::HandleSprite(double delta)
{
    if (this->velocityX < 0)
    {
        this->flipLeft = true;      
    }
    else if (this->velocityX > 0)
    {
        this->flipLeft = false;
    }
    if (this->jumping = true)
    {
        this->jumpTimeCounter += delta;
    }
    if (this->jumpTimeCounter >= this->jumpTime && this->jumping)
    {
        this->jumping = false;
    }
}

void CPlayer::Controll(double delta)
{
    if (this->mainInputManager->IsKeyDown(SDL_SCANCODE_A))
    {
        this->velocityX = std::max(this->velocityXMax * -1, this->velocityX - this->velocityAddition * delta);
    }
    else if (this->mainInputManager->IsKeyDown(SDL_SCANCODE_D))
    {
        this->velocityX = std::min(this->velocityXMax, this->velocityX + this->velocityAddition * delta);
    }
    if (this->mainInputManager->IsKeyDown(SDL_SCANCODE_S))
    {
        this->ApplyGravity(delta);
        this->ApplyGravity(delta);
        this->ApplyGravity(delta);
    }
    
}

void CPlayer::ApplyFriction(double delta)
{
    if (this->velocityX != 0)
    {
        if (this->velocityX > 0)
        {
            this->velocityX += this->friction * -1 * delta;
        }
        else
        {
            this->velocityX += this->friction * 1 * delta;
        }
    }
    if ((this->velocityX < 0.1 && this->velocityX > 0) || (this->velocityX > -0.1 && this->velocityX < 0))
    {
        this->velocityX = 0;
    }
}

void CPlayer::ApplyGravity(double delta)
{
    this->velocityY = std::min(this->velocityY + this->gravity * delta, this->velocityYMax);
}

void CPlayer::HandleCollision()
{
    auto platformCatalogue = this->mainPlatformManager->GetPlatformCatalogue();
    SDL_Rect rect;
    rect.x = this->x;
    rect.y = this->y;
    rect.w = this->w;
    rect.h = this->h;
    
    for (int i = 0; i < platformCatalogue.size(); i++)
    {
        if (CCollisionManager::GetCollisionRect(rect, platformCatalogue[i]->GetRect()))
        {
            if (this->velocityY > 0 && (this->y + this->h - 5) < platformCatalogue[i]->GetRect().y)
            {
                this->velocityY = - 160;
                this->jumping = true;
                this->jumpTimeCounter = 0;
                this->mainSoundManager->PlaySound(this->jumpSound);
            }
        }
    }
}

SDL_Rect CPlayer::GetPlayerRect()
{
    SDL_Rect rect;
    rect.x = this->x;
    rect.y = this->y;
    rect.w = this->w;
    rect.h = this->h;
    
    return rect;
}