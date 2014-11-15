#ifndef SPLASH_H
#define SPLASH_H

#include "GameState.h"

class Splash : public GameState
{

public:
    Splash(int);
    virtual ~Splash() { }

    static const int SPLASH_TIME = 2000;
    
    void init();
    void input(SDL_Event);
    void update(float);
    void render(SDL_Renderer*);

private:
    SDL_Texture* splashImage;
    int timer;
    
};

#endif
