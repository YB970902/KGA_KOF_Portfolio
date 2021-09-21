#pragma once
#include "Config.h"
#include "Scene.h"

class Character;
class Command;
class HitBoxScene : public Scene
{
	Character* mpRect1 = nullptr;
	Character* mpRect2 = nullptr;

	Command* mpLeftMoveCom = nullptr;
	Command* mpRightMoveCom = nullptr;
	Command* mpSmallAttack = nullptr;
	Command* mpBigAttack = nullptr;
	
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;
};

