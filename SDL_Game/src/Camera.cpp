#include "Camera.h"

Camera::Camera(unsigned int width, unsigned int height, Entity* target)
	:m_width(width), m_height(height), target(target)
{
}

void Camera::Render()
{
	SDL_Rect rect;
	rect.x = m_width/2 - target->w/2;
	rect.y = m_height/2 - target->h;
	rect.w = target->w;
	rect.h = target->h;
	SDL_RenderDrawRect(m_renderer, &rect);
}
