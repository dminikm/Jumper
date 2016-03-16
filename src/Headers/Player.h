#pragma once
#ifndef CPLAYER_H
#define CPLAYER_H

#include "SDL2/SDL.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "GraphicsManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "Platform.h"
#include "PlatformManager.h"
#include "SoundManager.h"
#include "Sound.h"

class CPlayer
{
    private:
        CGraphicsManager* mainGraphicsManager;
        CInputManager* mainInputManager;
        CPlatformManager* mainPlatformManager;
        CSoundManager* mainSoundManager;
        
        SDL_Texture* playerSprite;
        SDL_Texture* playerSpriteJump;
        
        CSound* jumpSound;
        
        bool flipLeft;
        
        double jumpTime = 1;
        double jumpTimeCounter;
        bool jumping;
        
        double x;
        double y;
        double w;
        double h;
        double velocityX;
        double velocityY;
        double velocityXMax;
        double velocityYMax;
        double velocityAddition;
        double gravity;
        double friction;
        
        bool active;
        
        void BindToScreen(double delta);
        void HandleSprite(double delta);
        void ApplyMotion(double delta);
        void Controll(double delta);
        void ApplyFriction(double delta);
        void ApplyGravity(double delta);
        void HandleCollision();
    public:
        CPlayer(CGraphicsManager* graphicsManager, CInputManager* inputManager, CPlatformManager* platformManager, CSoundManager* soundManager);
        ~CPlayer();
        
        void Update(double delta);
        void Draw();
        void SpawnPlayer(double x, double y, double w = 28, double h = 46, double velocityXMax = 120, double velocityYMax = 210, double velocityAddition = 480, double gravity = 98, double friction = 120);
        void DespawnPlayer();
        bool IsPlayerSpawned();
        SDL_Rect GetPlayerRect();
        
};



#endif