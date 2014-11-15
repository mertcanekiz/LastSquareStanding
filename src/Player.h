#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "Graphics.h"

class Player
{

public:
    Player(int, int);

    void input(SDL_Event);
    void update(float);
    void render(SDL_Renderer*);
    void init();

    static const int WIDTH = 16;
    static const int HEIGHT = 16;

private:
    SDL_Texture* playerImage;
    int x, y;
    
    
};

#endif
