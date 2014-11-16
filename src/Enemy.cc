#include "Enemy.h"
#include "Application.h"

SDL_Texture* Enemy::enemyImage = nullptr;

Enemy::Enemy(int x, int y, float vx, float vy) : position(x, y), size(WIDTH, HEIGHT), velocity(vx, vy)
{

}

void Enemy::update(float delta)
{
    position.add(velocity);
}

void Enemy::render(SDL_Renderer* renderer)
{
    if(enemyImage == nullptr)
    {
	enemyImage = Graphics::loadTexture(renderer, "res/game/enemy.png");
    }

    Graphics::renderTexture(renderer, enemyImage, (int)position.getX(), (int)position.getY());
}
