#pragma once

#include "GameEntity.h"

class GameObject : public GameEntity
{
protected:
	POINTFLOAT pos = POINTFLOAT();
	RECT shape = RECT();
	float moveSpeed = 0.0f;
	int bodySize = 0;
	bool isControl = false;

public:
	inline void SetPos(POINTFLOAT pos) { this->pos = pos; }
	inline POINTFLOAT GetPos() { return this->pos; }
	inline void SetMoveSpeed(float speed) { this->moveSpeed = speed; }
	inline int GetBodySize() { return this->bodySize; }
	inline void SetIsControl(bool isControl) { this->isControl = isControl; }
	inline bool GetIsControl() { return this->isControl; }

	GameObject();
	~GameObject();
};

