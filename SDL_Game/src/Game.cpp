#include <SDL.h>
#include "Game.h"
#include "Log.h"
#include "Player.h"


const unsigned int TILESIZE = 16;


Game::Game(unsigned int width, unsigned int height)
	:m_width(width), m_height(height), m_running(true), m_screenSurface(NULL), m_window(NULL), m_renderer(NULL), camera(width, height, &p)
{
}

void Game::Run()
{
	entities.push_back(&p);
	if(!Initialize())
		logger.Error("Game failed to initialize!");
	else
	{
		SDL_Event event;
		unsigned int NOW = SDL_GetPerformanceCounter();
		unsigned int LAST = 0;
		unsigned int frameStart = SDL_GetTicks();
		unsigned int frameEnd = SDL_GetTicks();
		float fpsDelta = 0;
		float deltaTime = 0;
		while (m_running)
		{
			LAST = NOW;
			NOW = SDL_GetPerformanceCounter();
			frameStart = SDL_GetTicks();
			fpsDelta += frameStart - frameEnd;
			deltaTime = ((NOW - LAST) * 1000 / SDL_GetPerformanceFrequency());
			while (SDL_PollEvent(&event)) {
				OnEvent(event);
			}
			const Uint8* state = SDL_GetKeyboardState(NULL);
			HandleInput(state, deltaTime);
			OnUpdate(deltaTime);
			OnRender();
			frameEnd = SDL_GetTicks();
		}
	}
}

void Game::CleanUp()
{
	//Destroy stuff
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);

	//Quit SDL subsystems
	SDL_Quit();
}

bool Game::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		logger.Error("SDL could not be initialized!");
		return false;
	}
	//Create window
	m_window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_SHOWN);
	if (m_window == NULL)
	{
		logger.Error("Window could not be created!");
		return false;
	}
	//Get window surface
	m_screenSurface = SDL_GetWindowSurface(m_window);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	camera.SetRenderer(m_renderer);
	return true;
}

void Game::OnUpdate(float deltaTime)
{
	for (auto& e : entities)
	{
		e->onUpdate(deltaTime);
	}
}

void Game::OnEvent(SDL_Event& event)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (event.type == SDL_QUIT)
		m_running = false;
	for (auto& e : entities)
	{
		e->handleEvent(event);
	}
}

void Game::OnRender()
{
	SDL_RenderClear(m_renderer);
	SDL_Rect rect;
	rect.x = 3*TILESIZE - p.pos.x;
	rect.y = 3*TILESIZE + p.pos.y;
	rect.w = 16;
	rect.h = 16;
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(m_renderer, &rect);
	for (auto& e : entities)
	{
	//	e->onRender(m_renderer);
	}
	camera.Render();
	
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderPresent(m_renderer);
}

void Game::HandleInput(const Uint8* state, float deltaTime)
{
	for (auto& e : entities)
	{
		e->handleInput(state, deltaTime);
	}
}

struct Tile
{
	Vec2f pos;
};