#include "Player.h"
#include "Log.h"

Player::Player()
	:Entity({ 3, 3 })
{
	w = 16;
	h = 32;
}

Player::~Player()
{
}

void Player::onUpdate(double deltaTime)
{
}

void Player::handleInput(const Uint8* state, float deltaTime)
{
	Vec2f _move = Vec2f::ZERO();
	if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_DOWN])
	{
		if (state[SDL_SCANCODE_RIGHT])
			_move.x += acl;
		if (state[SDL_SCANCODE_LEFT])
			_move.x -= acl;
		if (state[SDL_SCANCODE_UP])
			_move.y += acl;
		if (state[SDL_SCANCODE_DOWN])
			_move.y -= acl;
		if (_move.Amplitude())
		{
		    move = _move + move;
		}
	}
	else
		move = move.Lerp(Vec2f::ZERO(), dcl);
		// this debug print makes thins work (??????????????????)
		std::cout << "(" << move.x << ", " << move.y << ")" << std::endl;
	if (move.Amplitude() > 1)
		move.Normalize();

	// clamping movement vector to zero whenever it gets lerped to a very small number
	else if (abs(move.x) < .0005 && abs(move.y) < .0005)
		move = Vec2f::ZERO();

	pos = pos + move * velocity * deltaTime;
}

void Player::onRender(SDL_Renderer* renderer)
{
}
