#pragma once
#include "Config.h"
#include "Scene.h"

class ChAnimation;
class AnimationScene : public Scene
{
	ChAnimation* mPlayer1 = nullptr;
	ChAnimation* mPlayer2 = nullptr;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;
};

