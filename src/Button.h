#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <SDL2/SDL.h>

#include "Graphics.h"

class Button
{

public:
    Button(char*, int, int);

    static const int STATE_NORMAL = 0x00;
    static const int STATE_HOVER  = 0x01;
    static const int STATE_PRESS  = 0x02;

    static const int WIDTH = 120;
    static const int HEIGHT = 20;

    void init();
    void render(SDL_Renderer*);

    void changeState(int);
    void click();

    inline int getX() { return bounds.x; }
    inline int getY() { return bounds.y; }
    inline int getState() { return state; }
    inline int getLastState() { return lastState; }

private:
    SDL_Texture* images[3];
    std::string name;
    int x, y, state, lastState;
    SDL_Rect bounds;
    void loadImages(std::string name, SDL_Texture* images[]);
    
};

#endif
