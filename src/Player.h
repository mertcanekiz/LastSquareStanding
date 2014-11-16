#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "Graphics.h"
#include "Vector2f.h"

class Player
{

public:
    Player();

    void input(SDL_Event);
    void update(float);
    void render(SDL_Renderer*);
    void init();

    static const int WIDTH = 16;
    static const int HEIGHT = 16;

    inline Vector2f getPosition() { return position; }
    inline Vector2f getSize() { return size; }

private:
    SDL_Texture* playerImage;

    Vector2f velocity;
    Vector2f position;
    Vector2f size;
    const float moveSpeed = 5.0f;
    bool move[4];
    
};

#endif
