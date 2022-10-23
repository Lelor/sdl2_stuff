#include "Entity.h"
#include "../Log.h"

Entity::Entity(Vec2f pos)
	:pos(pos)
{
}

Entity::~Entity()
{
}

void Entity::onUpdate(double deltaTime)
{
}

void Entity::handleEvent(SDL_Event& event)
{
}

void Entity::handleInput(const Uint8* state, float deltaTime)
{
}

void Entity::onRender(SDL_Renderer* renderer)
{
}
