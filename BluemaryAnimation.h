#pragma once
#include "ChAnimation.h"

class ChAnimData;
class BluemaryAnimation : public ChAnimation
{
public:
	ChAnimData* mData;


	void Init(Lookat dir) override;
	void ImgUpdate(AnimStatus playerStatus) override;
	FLOAT moveAfterAction(FLOAT pos) override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

};
