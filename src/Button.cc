#include "Button.h"
#include "Application.h"

Button::Button(char* name, int x, int y) : name(name), x(x), y(y), state(STATE_NORMAL)
{
    bounds.x = x;
    bounds.y = y;
    bounds.w = WIDTH;
    bounds.h = HEIGHT;
}

void Button::init()
{
    loadImages(name, images);
}

void Button::render(SDL_Renderer* renderer)
{
    Graphics::renderTexture(renderer, images[state], x, y);
}

void Button::click()
{
    if(name == "exit")
    {
	Application::getInstance().stop();
    }
    else if(name == "start")
    {
	Application::getInstance().changeState(GameState::GAME);
    }
}

void Button::changeState(int state)
{
    lastState = this->state;
    this->state = state;
}

void Button::loadImages(std::string name, SDL_Texture* images[])
{
    for(int i = 0; i < 3; i++)
    {
	std::string filename = std::string("res/menu/buttons/") + name + std::to_string(i) + ".png";
	if(images[i] == nullptr)
	{
	    images[i] = Graphics::loadTexture(Application::getInstance().getRenderer(), filename.c_str());
	}
    }
}
