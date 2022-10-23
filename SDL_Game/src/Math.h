#pragma once
#include <math.h>

struct Vec2f
{
	float x, y;

	Vec2f operator + (Vec2f other)
	{
		return { x + other.x, y + other.y };
	}

	Vec2f operator + (float scale)
	{
		return { x + scale, y + scale };
	}

	Vec2f operator - (Vec2f other)
	{
		return { x - other.x, y - other.y };
	}

	Vec2f operator - (float scale)
	{
		return { x - scale, y - scale };
	}

	Vec2f operator * (float scale)
	{
		return { x * scale, y * scale };
	}

	Vec2f operator / (float scale)
	{
		return { x / scale, y / scale };
	}

	void Normalize()
	{
		float amp = Amplitude();
		x /= amp;
		y /= amp;
	}

	Vec2f Normalized()
	{
		float amp = Amplitude();
		if (amp)
			return { x / amp, y / amp };
		return { 0, 0 };
	}

	float Amplitude()
	{
		return (float)sqrt(x * x + y * y);
	}

	static const Vec2f ZERO() { return { 0.0f, 0.0f }; }

	Vec2f Lerp(Vec2f other, float t)
	{
		return { x + (other.x - x) * t, y + (other.y - y) * t };
	}
};

