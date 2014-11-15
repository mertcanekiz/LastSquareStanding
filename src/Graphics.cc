#include "Graphics.h"

SDL_Texture* Graphics::loadTexture(SDL_Renderer* renderer, const char* filename)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, filename);

    if(texture == nullptr)
    {
	printf("Could not load texture from %s: %s\n", filename, SDL_GetError());
	exit(1);
    }

    return texture;
}

void Graphics::renderTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y)
{
    if(texture == nullptr)
    {
	exit(1);
    }
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(texture, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, texture, nullptr, &dst);
}
