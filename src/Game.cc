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
	    Application::getInstance().changeState(GameState::MENU);
	    break;
	}
    }
    player.input(event);
}

void Game::update(float delta)
{
    player.update(delta);
    for(auto &e : enemies)
    {
	e.update(delta);
	//5 is an arbitrary small number to seperate out-of-bounds enemies from newly generated enemies
	if(e.getPosition().getX() + Enemy::WIDTH + 5 < 0 || e.getPosition().getX() >= Application::SCREEN_WIDTH + Enemy::WIDTH + 5
	   || e.getPosition().getY() + Enemy::WIDTH + 5 < 0 || e.getPosition().getY() >= Application::SCREEN_HEIGHT + Enemy::HEIGHT + 5)
	{
	    //Reposition the enemy if it went out of screen
	    e.setPosition(getRandomPosition());
	}

	//Collision check between enemy and player
	if(player.getPosition().getX() + Player::WIDTH > e.getPosition().getX()
	   && player.getPosition().getX() < e.getPosition().getX() + Enemy::WIDTH
	   && player.getPosition().getY() + Player::HEIGHT >= e.getPosition().getY()
	   && player.getPosition().getY() < e.getPosition().getY() + Enemy::HEIGHT)
	{
	    Application::getInstance().addScore(timer);	    
	    Application::getInstance().changeState(GameState::MENU);
	}
    }
    
    if(enemies.size() < enemyCount)
    {
	enemies.push_back(Enemy(getRandomPosition(), getRandomVelocity()));
    }

    
    timer++;
    enemyCount = timer / 100;
    maxEnemySpeed += (float)timer / 50000.0f;
    if(maxEnemySpeed >= maxMaxEnemySpeed)
    {
	maxEnemySpeed = maxMaxEnemySpeed;
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

    //Unreachable code, to satisfy compiler warning
    return Vector2f();
}

Vector2f Game::getRandomVelocity()
{
    //Random x and y velocities for enemies between (-maxEnemySpeed) and (+maxEnemySpeed)
    return Vector2f((float)rand() / (float)(RAND_MAX/(2*maxEnemySpeed)) - maxEnemySpeed,
		    (float)rand() / (float)(RAND_MAX/(2*maxEnemySpeed)) - maxEnemySpeed);
}

void Game::render(SDL_Renderer* renderer)
{
    Graphics::renderTexture(renderer, backgroundImage, 0, 0);
    player.render(renderer);
    for(auto &e : enemies)
    {
	e.render(renderer);
    }
    Graphics::renderTexture(renderer, Graphics::createTextureFromText(renderer, std::to_string(timer), color_blue), Application::SCREEN_WIDTH - 50, 5);
}

void Game::init()
{
    if(backgroundImage == nullptr)
    {
	backgroundImage = Graphics::loadTexture(Application::getInstance().getRenderer(), "res/game/background.png");
    }
    
    player.init();
    Enemy::init();

    enemies.clear();

    //Start with 10 enemies and max speed 2
    enemyCount = 10;  
    maxEnemySpeed = 2.0f; 
    timer = 0;
}
