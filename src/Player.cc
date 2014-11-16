#include "Player.h"
#include "Application.h"
#include "GameState.h"
#include <cstdio>

Player::Player() : size(WIDTH, HEIGHT)
{
    playerImage = nullptr;
}

void Player::input(SDL_Event event)
{

    //Set movement flags according to the keys that are pressed (w, a, s, d)
    
    if(event.type == SDL_KEYDOWN)
    {
	switch(event.key.keysym.sym)
	{
	case SDLK_w:
	    move[0] = true;
	    break;
	case SDLK_d:
	    move[1] = true;
	    break;
	case SDLK_s:
	    move[2] = true;
	    break;
	case SDLK_a:
	    move[3] = true;
	    break;
	}
    }

    if(event.type == SDL_KEYUP)
    {
	switch(event.key.keysym.sym)
	{
	case SDLK_w:
	    move[0] = false;
	    break;
	case SDLK_d:
	    move[1] = false;
	    break;
	case SDLK_s:
	    move[2] = false;
	    break;
	case SDLK_a:
	    move[3] = false;
	    break;
	}	
    }
}

void Player::update(float delta)
{
    //stop if no key is pressed
    velocity.setX(0);
    velocity.setY(0);

    //Only one of the two opposite directions can be active at any time
    if(move[0] ^ move[2])
    {
	velocity.setY((move[0]?-1:1)*moveSpeed);
    }
    else if(move[1] ^ move[3])
    {
	velocity.setX((move[1]?1:-1)*moveSpeed);
    }

    //Slow down diagonal movement with cosine and sine of 45 degrees (~ 1/1.4)
    if(move[0] && move[1])
    {
	velocity.setX(moveSpeed / 1.4f);
	velocity.setY(-moveSpeed / 1.4f);
    }
    if(move[0] && move[3])
    {
	velocity.setX(-moveSpeed / 1.4f);
	velocity.setY(-moveSpeed / 1.4f);
    }
    if(move[2] && move[1])
    {
	velocity.setX(moveSpeed / 1.4f);
	velocity.setY(moveSpeed / 1.4f);	
    }
    if(move[2] && move[3])
    {
	velocity.setX(-moveSpeed / 1.4f);
	velocity.setY(moveSpeed / 1.4f);	
    }
    
    position.add(velocity);
    
    //Prevent the player from going off screen
    if(position.getX() < 0)
    {
	position.add((0 - position.getX()), 0);
    }

    if(position.getX() + size.getX() >= Application::SCREEN_WIDTH)
    {
	position.add((Application::SCREEN_WIDTH - (position.getX() + size.getX())), 0);
    }

    if(position.getY() < 0)
    {
	position.add(0, (0 - position.getY()));
    }

    if(position.getY() + size.getY() >= Application::SCREEN_HEIGHT)
    {
	position.add(0, (Application::SCREEN_HEIGHT - (position.getY() + size.getY())));
    }
}

void Player::render(SDL_Renderer* renderer)
{
    Graphics::renderTexture(renderer, playerImage, (int)position.getX(), (int)position.getY());
}

void Player::init()
{
    //align the player to the center of the screen
    position.setX(Application::SCREEN_WIDTH / 2 - WIDTH / 2);
    position.setY(Application::SCREEN_HEIGHT / 2 - HEIGHT / 2);

    
    for(int i = 0; i < 4; i++)
    {
	//set movement flags for all directions to "false"
	move[i] = false; 
    }
    if(playerImage == nullptr)
    {
	//load the image only if it isn't loaded yet
	playerImage = Graphics::loadTexture(Application::getInstance().getRenderer(), "res/game/player.png"); 
    }
}
