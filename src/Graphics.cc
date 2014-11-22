#include "Graphics.h"

TTF_Font* Graphics::font = nullptr;

bool Graphics::init()
{
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
	printf("SDL_image could not initialize. SDL_image Error: %s\n", IMG_GetError());
	return false;
    }

    if(TTF_Init() == -1)
    {
	printf("SDL_ttf could not initialize. SDL_ttf Error: %s\n", TTF_GetError());
	return false;
    }

    font = TTF_OpenFont("res/fonts/FreeMonoBold.ttf", 20);

    if(font == nullptr)
    {
	printf("Could not load font. SDL_ttf Error: %s\n", TTF_GetError());
	return false;
    }

    return true;
}

SDL_Texture* Graphics::createTextureFromText(SDL_Renderer* renderer, const char* text, SDL_Color color)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = nullptr;
    if(textSurface == nullptr)
    {
	printf("Couldn't render text surface. SDL_ttf Error: %s\n", TTF_GetError());
    }
    else
    {
	texture = SDL_CreateTextureFromSurface(renderer, textSurface);

	if(texture == nullptr)
	{
	    printf("Could not create texture from text surface. SDL Error: %s\n", SDL_GetError());
	}

	SDL_FreeSurface(textSurface);
    }

    return texture;
}

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
