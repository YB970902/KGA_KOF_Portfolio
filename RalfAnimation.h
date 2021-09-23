#pragma once
#include "ChAnimation.h"

class ChAnimData;
class RalfAnimation : public ChAnimation
{
public:
	ChAnimData* mData;

	void Init() override;
	void ImgUpdate(AnimStatus playerStatus) override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
	FLOAT moveAfterAction(FLOAT pos) override;
};