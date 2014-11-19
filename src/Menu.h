#ifndef MENU_H
#define MENU_H

#include "GameState.h"
#include "Button.h"

#define NUM_BUTTONS 3

class Menu : public GameState
{

public:
    Menu(int);
    virtual ~Menu() {};

    void input(SDL_Event);
    void update(float);
    void render(SDL_Renderer*);
    void init();

private:
    SDL_Texture* menubg;
    Button buttons[NUM_BUTTONS];

};

#endif
