#pragma once
#include "Config.h"
#include "Scene.h"

class Image;
class Command;
class ChAnimation;
class HealthBar;
class AnimationScene : public Scene
{
private:
	Image* mBattleGroundImg;

	RECT mCameraSize = RECT();
	RECT mBackgroundSize = RECT();

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

	HealthBar* mPlayer1Bar = nullptr;
	HealthBar* mPlayer2Bar = nullptr;

	Image** mpArrBackground = nullptr;

	int mCurBackgroundFrame = 0;
	const int MaxBackGroundFrame = 39;
	int mCurElapseTime = 0;

	int mBackgroundPosX = 0;

public:

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;
};

