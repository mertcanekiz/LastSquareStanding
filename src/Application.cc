#include "Application.h"

int Application::execute()
{
    if(initialize() == false)
    {
	return -1;
    }

    running = true;
    SDL_Event event;

    Uint32 previousTime = SDL_GetTicks();
    
    currentState = GameState::getStateByID(GameState::SPLASH);
    currentState->init();
    
    while(running)
    {
	Uint32 currentTime = SDL_GetTicks();
	float delta = (float)((currentTime - previousTime) / 1000.0);
	previousTime = currentTime;

	while(SDL_PollEvent(&event))
	{
	    input(event);
	}

	update(delta);
	render();
    }

    cleanUp();
    return 0;
}

void Application::input(SDL_Event event)
{
    if(event.type == SDL_QUIT)
    {
	stop();
    }
    currentState->input(event);
}

void Application::update(float delta)
{
    currentState->update(delta);
}

void Application::render()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(renderer);
    currentState->render(renderer);
    SDL_RenderPresent(renderer);
}

void Application::stop()
{
    if(!running) return;
    running = false;
}

void Application::changeState(int id)
{
    currentState = GameState::getStateByID(id);
    currentState->init();
}

bool Application::initialize()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
	printf("Could not initialize SDL: %s\n", SDL_GetError());
	return false;
    }
    

    window = SDL_CreateWindow("Last Square Standing v0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			      SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if(window == nullptr)
    {
	printf("Could not create window: %s\n", SDL_GetError());
	SDL_Quit();
	return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == nullptr)
    {
	SDL_DestroyWindow(window);
	printf("Could not create renderer: %s\n", SDL_GetError());
	SDL_Quit();
	return false;
    }

    if(!Graphics::init())
    {
	return false;
    }

    //Load scores from scores.txt file and store in scores vector
    std::ifstream ifs("scores.txt");
    int tmp_score;

    while(ifs >> tmp_score)
    {
	scores.push_back(tmp_score);
    }

    ifs.close();

    for(auto &i : scores)
    {
	printf("%i\n", i);
    }

    //Return true if all of the above is done
    return true;
}

unsigned int Application::getPreviousScore() const
{
    if(scores.size() != 0)
    {
	return scores[scores.size() - 1];
    }

    return 0;
}

unsigned int Application::getHighScore() const
{
    std::vector<unsigned int> tmpScores;
    tmpScores = scores;
    if(tmpScores.size() != 0)
    {
     std::sort(tmpScores.begin(), tmpScores.end());
     return tmpScores[tmpScores.size()-1];
    }
    return 0;
}

void Application::cleanUp()
{
    //Replace 'scores.txt' file with the new scores
    std::ofstream ofs("scores.txt", std::ofstream::out);
    for(auto &i : scores)
    {
	ofs << i << "\n";
    }
    ofs.close();
    
    GameState::cleanUp();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
