#include "Enemy.h"
#include "Application.h"

SDL_Texture* Enemy::enemyImage = nullptr;

Enemy::Enemy(Vector2f position, Vector2f velocity) : position(position), velocity(velocity)
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

    if(position.getX() > -WIDTH && position.getX() <= Application::SCREEN_WIDTH
       && position.getY() > -HEIGHT && position.getY() <= Application::SCREEN_HEIGHT)
    {
	Graphics::renderTexture(renderer, enemyImage, (int)position.getX(), (int)position.getY());
    }
}
