#pragma once
#include <SDL.h>
#include "Player.h"
#include "Camera.h"
#include <vector>

class Game
{
private:
	Player p;
	Camera camera;
	unsigned int m_width, m_height;
	SDL_Window* m_window;
	SDL_Surface* m_screenSurface;
	SDL_Renderer* m_renderer;
	bool m_running;
	std::vector<Entity*> entities;

public:
	Game(unsigned int width, unsigned int height);
	void Run();
	void CleanUp();

private:
	bool Initialize();
	void OnUpdate(float deltaTime);
	void OnEvent(SDL_Event& event);
	void OnRender();
	void HandleInput(const Uint8* state, float deltaTime);
};