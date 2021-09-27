#pragma once
#pragma comment(lib, "msimg32.lib")
#include "Config.h"
#include "Scene.h"

class Image;
class Command;
class ChAnimation;
class HealthBar;
class AnimationScene : public Scene
{
private:
	Image* mpEndImage = nullptr;
	BLENDFUNCTION bf;

	RECT mCameraSize = RECT();
	RECT mBackgroundSize = RECT();

	ChAnimation* mpPlayer1 = nullptr;
	ChAnimation* mpPlayer2 = nullptr;

	Command* mpWeakPunch1 = nullptr;
	Command* mpStrongPunch1 = nullptr;
	Command* mpWeakKick1 = nullptr;
	Command* mpStrongKick1 = nullptr;
	Command* mpMoveLeft1 = nullptr;
	Command* mpMoveRight1 = nullptr;

	Command* mpNearWeakPunch1 = nullptr;
	Command* mpNearStrongPunch1 = nullptr;
	Command* mpNearWeakKick1 = nullptr;
	Command* mpNearStrongKick1 = nullptr;

	Command* mpWeakPunch2 = nullptr;
	Command* mpStrongPunch2 = nullptr;
	Command* mpWeakKick2 = nullptr;
	Command* mpStrongKick2 = nullptr;
	Command* mpMoveLeft2 = nullptr;
	Command* mpMoveRight2 = nullptr;

	Command* mpNearWeakPunch2 = nullptr;
	Command* mpNearStrongPunch2 = nullptr;
	Command* mpNearWeakKick2 = nullptr;
	Command* mpNearStrongKick2 = nullptr;

	HealthBar* mpPlayer1Bar = nullptr;
	HealthBar* mpPlayer2Bar = nullptr;

	Image** mpArrBackground = nullptr;

	Image** mpArrEffect = nullptr;

	const int MaxBackGroundFrame = 39;
	int mCurBackgroundFrame = 0;
	int mCurElapseTime = 0;

	int mBackgroundPosX = 0;

	int mDistance=0;

	POINTFLOAT Player1HitPos;
	POINTFLOAT Player2HitPos;
	bool mbPrintEffect1 = false;
	bool mbPrintEffect2 = false;
	int mCurEffectFrame = 0;
	int mCurEffectElapseTime = 0;
	const int MaxEffectFrame = 8;

	const int NearMaxPixel = 36;

public:

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;
};

