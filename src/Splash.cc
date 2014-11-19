#include "Splash.h"
#include "Application.h"

Splash::Splash(int id) : GameState(id)
{
    splashImage = nullptr;
}


void Splash::init()
{
    timer = SDL_GetTicks();
}

void Splash::input(SDL_Event event)
{

}

void Splash::update(float delta)
{
    if(SDL_GetTicks() - timer >= SPLASH_TIME)
    {
	Application::getInstance().changeState(GameState::MENU);
    }
}

void Splash::render(SDL_Renderer* renderer)
{
    if(splashImage == nullptr)
    {
	splashImage = Graphics::loadTexture(renderer, "res/splash/splash.png");
    }

    Graphics::renderTexture(renderer, splashImage, 0, 0);
    
}
