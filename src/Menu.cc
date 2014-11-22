#include "Menu.h"
#include "Application.h"

Menu::Menu(int id) : GameState(id),
		     buttons{  //Initialize buttons in the appropriate positions
                             Button("start", Application::SCREEN_WIDTH - Button::WIDTH - 24, 210),
			     Button("options", Application::SCREEN_WIDTH - Button::WIDTH - 24, 235),
			     Button("exit", Application::SCREEN_WIDTH - Button::WIDTH - 24, 260)}
{
    menubg = nullptr;
}

bool mousedown = false;

void Menu::input(SDL_Event event)
{
    int x = event.motion.x;
    int y = event.motion.y;

    if(event.type == SDL_KEYDOWN)
    {
	if(event.key.keysym.sym == SDLK_ESCAPE)
	{
	    Application::getInstance().stop();
	}
	if(event.key.keysym.sym == SDLK_SPACE)
	{
	    Application::getInstance().changeState(GameState::GAME);
	}
    }

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
	if(x > b.getX() && x < b.getX() + Button::WIDTH &&  //If the mouse is within a button's bounds
	   y > b.getY() && y < b.getY() + Button::HEIGHT)   //////////////////////////////////////////
	{
	    if(!mousedown)
	    {
		//State is "hover" if mouse button is not down
		b.changeState(Button::STATE_HOVER);
	    }
	    if(mousedown)
	    {
		//State is "press" if mouse button is down
		b.changeState(Button::STATE_PRESS);
	    }
	    if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT && b.getLastState() == Button::STATE_PRESS)
	    {
		//"Click" happens if the mouse button is released within the button and the button's
		//last state was "press"
		b.click();
	    }
	}
	else
	{
	    //If mouse is not inside the button, revert to state "normal"
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
