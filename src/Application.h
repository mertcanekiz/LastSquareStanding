#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include <cstdio>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Application
{

public:
    int execute();
    static Application& getInstance()
    {
	static Application instance;
	return instance;
    }
    void stop();

private:
    Application() { };
    bool initialize();
    void input(SDL_Event);
    void update(float);
    void render();
    void cleanUp();
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    Application(const Application&);
    void operator=(const Application&);
	

};

#endif
