#include "Game.h"
#include "Application.h"

Game::Game(int id) : GameState(id)
{
    backgroundImage = nullptr;
    srand(time(0)); //Seed the random number generator
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
    for(auto &e : enemies)
    {
	e.update(delta);
	//5 is an arbitrary small number to seperate out-of-bounds enemies from newly generated enemies
	if(e.getX() + Enemy::WIDTH + 5 < 0 || e.getX() >= Application::SCREEN_WIDTH + Enemy::WIDTH + 5
	   || e.getY() + Enemy::WIDTH + 5 < 0 || e.getY() >= Application::SCREEN_HEIGHT + Enemy::HEIGHT + 5)
	{
	    //Reposition the enemy if it went out of screen
	    e.setPosition(getRandomPosition());
	}
    }
    
    if(enemies.size() < enemyCount)
    {
	enemies.push_back(Enemy(getRandomPosition(), getRandomVelocity()));
    }
}

Vector2f Game::getRandomPosition()
{
    //Generate a Vector2f with values right outside of the screen for enemy generation
    int randomIndex = rand() % 4;
    switch(randomIndex)
    {
    case 0:
	return Vector2f(-Enemy::HEIGHT, ((float)rand() / (float)RAND_MAX)*Application::SCREEN_HEIGHT); 
	break;
    case 1:
	return Vector2f(((float)rand() / (float)RAND_MAX)*Application::SCREEN_WIDTH, -Enemy::HEIGHT);
	break;
    case 2:
	return Vector2f(Application::SCREEN_WIDTH + Enemy::WIDTH, ((float)rand() / (float)RAND_MAX)*Application::SCREEN_HEIGHT);
	break;
    case 3:
	return Vector2f(((float)rand() / (float)RAND_MAX)*Application::SCREEN_WIDTH, Application::SCREEN_HEIGHT + Enemy::HEIGHT);
	break;
    }
}

Vector2f Game::getRandomVelocity()
{
    return Vector2f(((float)rand() / (float)RAND_MAX)*maxEnemySpeed, ((float)rand() / (float)RAND_MAX)*maxEnemySpeed); 
}

void Game::render(SDL_Renderer* renderer)
{
    Graphics::renderTexture(renderer, backgroundImage, 0, 0);
    player->render(renderer);
    for(auto &e : enemies)
    {
	e.render(renderer);
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
    Enemy::init();

    //Arbitrary numbers for testing; will be time-based eventually
    enemyCount = 100;
    maxEnemySpeed = 5;

}
