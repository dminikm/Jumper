#include "Headers/TextureManager.h"

CTextureManager::CTextureManager(SDL_Renderer* renderer)
{
    this->mainGameRenderer = renderer;
    this->CreateTexture("GimmieDatDefault");
}

CTextureManager::~CTextureManager()
{
    
}

SDL_Texture* CTextureManager::CreateTexture(std::string fileName)
{
    if (this->FindTextureID(fileName) == -1)
    {
        SDL_Surface* surfaceBuffer;
        SDL_Texture* textureBuffer;
        surfaceBuffer = SDL_LoadBMP(fileName.c_str());
        
        
        if (surfaceBuffer == NULL)
        {
            Uint32 rmask, gmask, bmask, amask;
            #if SDL_BYTEORDER == SDL_BIG_ENDIAN
                rmask = 0xff000000;
                gmask = 0x00ff0000;
                bmask = 0x0000ff00;
                amask = 0x000000ff;
            #else
                rmask = 0x000000ff;
                gmask = 0x0000ff00;
                bmask = 0x00ff0000;
                amask = 0xff000000;
            #endif
            
            surfaceBuffer = SDL_CreateRGBSurface(0,1,1,32,rmask,gmask,bmask,amask);
            SDL_FillRect(surfaceBuffer, NULL, SDL_MapRGB(surfaceBuffer->format, 255, 0, 0));
        }
        
        
        textureBuffer = SDL_CreateTextureFromSurface(this->mainGameRenderer, surfaceBuffer);
           
        this->textureCatalogue.push_back(textureBuffer);
        this->textureCatalogueFileNames.push_back(fileName);
        
        SDL_FreeSurface(surfaceBuffer);
        SDL_DestroyTexture(textureBuffer);
    }
    
    return this->FindTexture(fileName);
    
}

bool CTextureManager::RemoveTexture(std::string fileName)
{
    int textureID = this->FindTextureID(fileName);
    if ( textureID > -1)
    {
        SDL_DestroyTexture(this->textureCatalogue[textureID]);
        this->textureCatalogue.erase(this->textureCatalogue.begin() + textureID);
        this->textureCatalogueFileNames.erase(this->textureCatalogueFileNames.begin() + textureID);
    }
}

SDL_Texture* CTextureManager::FindTexture(std::string fileName)
{
    int textureID = -1;
    
    for (int i = 0; i < this->textureCatalogue.size(); i++)
    {
        if (this->textureCatalogueFileNames[i] == fileName)
        {
            textureID = i;
            break;
        }
    }
    if (textureID == -1)
    {
        return this->textureCatalogue[0];
    }
    else
    {
        return this->textureCatalogue[textureID];
    }
    
}

int CTextureManager::FindTextureID(std::string fileName)
{
    int textureID = -1;
    
    for (int i = 0; i < this->textureCatalogue.size(); i++)
    {
        if (this->textureCatalogueFileNames[i] == fileName)
        {
            textureID = i;
            break;
        }
    }
    
    return textureID;
}

SDL_Texture* CTextureManager::GetTexture(int index)
{
    if (index <= this->textureCatalogue.size())
    {
        return this->textureCatalogue[index];
    }
    else
    {
        return this->textureCatalogue[0];
    }
}

void CTextureManager::RemoveAllTextures()
{
    for (int i = 0; i < this->textureCatalogue.size();i++)
    {
        SDL_DestroyTexture(this->textureCatalogue[i]);
    }
    this->textureCatalogue.resize(0);
}