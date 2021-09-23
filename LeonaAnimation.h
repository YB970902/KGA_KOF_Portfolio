#pragma once
#include "ChAnimation.h"

class ChAnimData;
class LeonaAnimation : public ChAnimation
{
public:
	ChAnimData* mData;

	// ChAnimation을(를) 통해 상속됨
	void Init(Lookat dir) override;
	void ImgUpdate(AnimStatus playerStatus) override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
	FLOAT moveAfterAction(FLOAT pos) override;
};
