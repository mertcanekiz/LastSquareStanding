#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Graphics
{

public:
    static bool init();
    static SDL_Texture* loadTexture(SDL_Renderer*, const char*);
    static SDL_Texture* createTextureFromText(SDL_Renderer*, std::string, SDL_Color);
    static void renderTexture(SDL_Renderer*, SDL_Texture*, int, int);

private:
    static TTF_Font* font;
    
};

#endif
