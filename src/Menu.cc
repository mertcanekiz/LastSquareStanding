#include "Menu.h"
#include "Application.h"

Menu::Menu(int id) : GameState(id),
		     buttons{ Button("start", Application::SCREEN_WIDTH - Button::WIDTH - 24, 210),
	Button("options", Application::SCREEN_WIDTH - Button::WIDTH - 24, 235),
	Button("exit", Application::SCREEN_WIDTH - Button::WIDTH - 24, 260) }
{
    menubg = nullptr;
}

bool mousedown = false;

void Menu::input(SDL_Event event)
{
    int x = event.motion.x;
    int y = event.motion.y;

    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
    {
	mousedown = true;
    }

    if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
    {
	mousedown = false;
    }

    for(auto &b : buttons)
    {
	if(x > b.getX() && x < b.getX() + Button::WIDTH &&
	   y > b.getY() && y < b.getY() + Button::HEIGHT)
	{
	    if(!mousedown)
	    {
		b.changeState(Button::STATE_HOVER);
	    }
	    if(mousedown)
	    {
		b.changeState(Button::STATE_PRESS);
	    }
	    if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT && b.getLastState() == Button::STATE_PRESS)
	    {
		b.click();
	    }
	}
	else
	{
	    b.changeState(Button::STATE_NORMAL);
	}
    }
}

void Menu::update(float delta)
{

}

void Menu::render(SDL_Renderer* renderer)
{
    Graphics::renderTexture(renderer, menubg, 0, 0);
    for(auto &b : buttons)
    {
	b.render(renderer);
    }
}

void Menu::init()
{
    if(menubg == nullptr)
    {
	menubg = Graphics::loadTexture(Application::getInstance().getRenderer(), "res/menu/menubg.png");
    }
    for(auto &b : buttons)
    {
	b.init();
    }
}
