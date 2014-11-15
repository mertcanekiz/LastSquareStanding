#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "Player.h"

class Game : public GameState
{

public:
    Game(int);
    virtual ~Game() { delete player; }

    void init();
    void input(SDL_Event);
    void update(float);
    void render(SDL_Renderer*);

private:
    Player* player;
};

#endif
