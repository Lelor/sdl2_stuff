#pragma once
#include "entity/Entity.h"


class Player : public Entity
{
public:
	Vec2f move = Vec2f::ZERO();
	int velocity = 5;
	float speed = 0;
	float acl = 0.005f;
	float dcl = 0.005f;
	Player();
	~Player();
	void onUpdate(double deltaTime) override;
	void handleInput(const Uint8* state, float deltaTime) override;
	void onRender(SDL_Renderer* renderer);
};