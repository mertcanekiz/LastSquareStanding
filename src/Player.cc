#include "Player.h"
#include "Application.h"
#include <cstdio>

Player::Player(int x, int y): x(x), y(y)
{
    playerImage = nullptr;
}

void Player::input(SDL_Event event)
{

}

void Player::update(float delta)
{

}

void Player::render(SDL_Renderer* renderer)
{
    Graphics::renderTexture(renderer, playerImage, x, y);
}

void Player::init()
{
    x = 100;
    y = 100;
    if(playerImage == nullptr)
    {
	playerImage = Graphics::loadTexture(Application::getInstance().getRenderer(), "res/player/player.png");
    }
}
