#include "GameState.h"
#include "Splash.h"
#include "Menu.h"
#include "Game.h"

GameState* GameState::splash = new Splash(GameState::SPLASH);
GameState* GameState::menu = new Menu(GameState::MENU);
GameState* GameState::game = new Game(GameState::GAME);

GameState::GameState(int id) : id(id)
{

}


void GameState::cleanUp()
{
    delete splash;
    delete menu;
    delete game;
}

GameState* GameState::getStateByID(int id)
{
    switch(id)
    {
    case SPLASH:
	return splash;
    case MENU:
	return menu;
    case GAME:
	return game;
    }

    printf("Invalid GameState ID\n");
    return nullptr;
}
