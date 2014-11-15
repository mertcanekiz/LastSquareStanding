#include "Game.h"
#include "Application.h"

Game::Game(int id) : GameState(id)
{
    
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
}

void Game::update(float delta)
{
    
}

void Game::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xaa, 0xaa, 0xaa, 0xff);
    SDL_RenderClear(renderer);
    player->render(renderer);
}

void Game::init()
{
    player = new Player(100, 100);
    player->init();
}
