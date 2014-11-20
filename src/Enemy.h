#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>

#include "Vector2f.h"

class Enemy
{

public:
    Enemy(Vector2f, Vector2f);

    static const int WIDTH = 16;
    static const int HEIGHT = 16;

    inline Vector2f getPosition() const { return position; }
    inline void setPosition(Vector2f v) { position = v; }

    void update(float);
    void render(SDL_Renderer*);
    static void init();

private:
    static SDL_Texture* enemyImage;

    Vector2f position;
    Vector2f size;
    Vector2f velocity;
    
};

#endif
