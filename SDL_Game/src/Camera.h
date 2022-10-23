#pragma once
#include "entity/Entity.h"

class Camera
{
private:
	SDL_Renderer* m_renderer;
	unsigned int m_width, m_height;
public:
	Entity* target;
	Camera(unsigned int width, unsigned int height, Entity* target);
	const void inline SetRenderer(SDL_Renderer* renderer) { m_renderer = renderer; }
	void Render();
};