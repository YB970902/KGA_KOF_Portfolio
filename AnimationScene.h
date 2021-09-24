#pragma once
#include "Config.h"
#include "Scene.h"


class Command;
class ChAnimation;
class AnimationScene : public Scene
{
	ChAnimation* mPlayer1 = nullptr;
	ChAnimation* mPlayer2 = nullptr;

	Command* mWeakPunch1 = nullptr;
	Command* mStrongPunch1 = nullptr;
	Command* mWeakKick1 = nullptr;
	Command* mStrongKick1 = nullptr;
	Command* mMoveLeft1 = nullptr;
	Command* mMoveRight1 = nullptr;

	Command* mWeakPunch2 = nullptr;
	Command* mStrongPunch2 = nullptr;
	Command* mWeakKick2 = nullptr;
	Command* mStrongKick2 = nullptr;
	Command* mMoveLeft2 = nullptr;
	Command* mMoveRight2 = nullptr;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;
};

