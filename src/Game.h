#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GameState.h"
#include "Player.h"
#include "Enemy.h"

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
    std::vector<Enemy> enemies;
};

#endif
