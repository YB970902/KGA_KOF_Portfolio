#pragma once
#include "Config.h"
#include "Scene.h"

class AnimManager;
class AnimationScene : public Scene
{
	AnimManager* Ralf = nullptr;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;
};

