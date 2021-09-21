#pragma once
#include "Config.h"

class Scene
{
public:
	Scene() {};
	virtual ~Scene() {};
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Exit() = 0;
};

