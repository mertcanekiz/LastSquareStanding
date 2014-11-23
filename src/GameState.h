#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Graphics.h"

class GameState
{

public:
    GameState(int);
    virtual ~GameState() {}

    static const int SPLASH = 0x00;
    static const int MENU   = 0x01;
    static const int GAME   = 0x02;

    static GameState* splash;
    static GameState* menu;
    static GameState* game;

    const SDL_Color color_blue = { 0x00, 0x6f, 0xb0 };
    const SDL_Color color_white = { 0xff, 0xff, 0xff };

    static GameState* getStateByID(int);
    static void cleanUp();

    inline int getID() const { return id; }

    virtual void init() = 0;
    virtual void input(SDL_Event) = 0;
    virtual void update(float) = 0;
    virtual void render(SDL_Renderer*) = 0;

private:

    int id;

};

#endif
