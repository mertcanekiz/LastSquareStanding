#ifndef APPLICATION_H
#define APPLICATION_H

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <SDL2/SDL.h>
#include "GameState.h"

class Application
{

public:
    int execute();
    static Application& getInstance()
    {
	static Application instance;
	return instance;
    }
    void changeState(int);
    void stop();

    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 360;

    inline SDL_Renderer* getRenderer() const { return renderer; }
    inline void addScore(unsigned int score) { scores.push_back(score); }
    unsigned int getPreviousScore() const;
    unsigned int getHighScore() const;


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

    GameState* currentState;

    std::vector<unsigned int> scores;
    std::vector<unsigned int> newScores;

    Application(const Application&);
    void operator=(const Application&);
	

};

#endif
