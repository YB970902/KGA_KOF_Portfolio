#pragma once
#include "Config.h"
#include "Scene.h"

class Character;
class Command;
class HitBoxScene : public Scene
{
	Character* mRect1 = nullptr;
	Character* mRect2 = nullptr;

	Command* mLeftMoveCom = nullptr;
	Command* mRightMoveCom = nullptr;
	Command* mSmallAttack = nullptr;
	Command* mBigAttack = nullptr;
	
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;


};

