#include "Game.h"
#include "Application.h"

Game::Game(int id) : GameState(id)
{
    backgroundImage = nullptr;
}

void Game::input(SDL_Event event)
{
    if(event.type == SDL_KEYDOWN)
    {
	switch(event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	    Application::getInstance().stop();
	    break;
	}
    }
    player->input(event);
}

void Game::update(float delta)
{
    player->update(delta);
    for(int i = 0; i < enemies.size(); i++)
    {
	enemies[i].update(delta);
    }
}

void Game::render(SDL_Renderer* renderer)
{
    Graphics::renderTexture(renderer, backgroundImage, 0, 0);
    player->render(renderer);
    for(int i = 0; i < enemies.size(); i++)
    {
	enemies[i].render(renderer);
    }
}

void Game::init()
{

    if(backgroundImage == nullptr)
    {

	backgroundImage = Graphics::loadTexture(Application::getInstance().getRenderer(), "res/game/background.png");
    }
    player = new Player();
    player->init();
    for(int i = 0; i < 10; i++)
    {
	enemies.push_back(Enemy(i*32, i*16, i, i));
    }
}
