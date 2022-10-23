#pragma once
#include <SDL.h>
#include "../Math.h"


enum EntityType
{ALLY, ENEMY};


enum Physics
{RigidBody, StaticBody, NoPhysics};


class Entity
{
private:
	Physics m_physicsModel;
public:
	Vec2f pos;
	char* model;
	EntityType type;
	char* name;
public:
	Entity(Vec2f pos);
	~Entity();
	unsigned int w, h;
	virtual void onUpdate(double deltaTime);
	void handleEvent(SDL_Event& event);
	virtual void handleInput(const Uint8* state, float deltaTime);
	virtual void onRender(SDL_Renderer* renderer);
};