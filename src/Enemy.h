#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>

#include "Vector2f.h"

class Enemy
{

public:
    Enemy(int, int, float, float);

    static const int WIDTH = 16;
    static const int HEIGHT = 16;

    void update(float);
    void render(SDL_Renderer*);

private:
    static SDL_Texture* enemyImage;

    Vector2f position;
    Vector2f size;
    Vector2f velocity;
    
};

#endif
