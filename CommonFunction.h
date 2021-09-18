#pragma once
#include <Windows.h>
#include <math.h>

inline float GetDistance(const POINTFLOAT& pos1, const POINTFLOAT& pos2)
{
	return sqrtf((pos1.x - pos2.x) * (pos1.x - pos2.x)
		+ (pos1.y - pos2.y) * (pos1.y - pos2.y));
}

inline bool IsCollided(const RECT& rc1, const RECT& rc2)
{
	return (rc1.right > rc2.left
		&& rc1.left < rc2.right
		&& rc1.top < rc2.bottom
		&& rc1.bottom > rc2.top);
}