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
	Graphics::renderTexture(renderer, enemyImage, (int)position.getX(), (int)position.getY());

}

void Enemy::init()
{
    if(enemyImage == nullptr)
    {
	enemyImage = Graphics::loadTexture(Application::getInstance().getRenderer(), "res/game/enemy.png");
    }
}
