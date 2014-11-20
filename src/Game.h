#ifndef GAME_H
#define GAME_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include "GameState.h"
#include "Player.h"
#include "Enemy.h"
#include "Vector2f.h"

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

    Vector2f getRandomPosition();
    Vector2f getRandomVelocity();
       
    Player* player;
    std::vector<Enemy> enemies;
    SDL_Texture* backgroundImage;
    int enemyCount, maxEnemySpeed;
    
};

#endif
