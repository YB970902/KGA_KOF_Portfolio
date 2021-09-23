#pragma once
#include "Scene.h"
#include "Config.h"

class CharacterSelectScene : public Scene
{

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;
};

