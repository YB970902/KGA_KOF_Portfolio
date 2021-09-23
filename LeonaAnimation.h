#pragma once
#include "ChAnimation.h"

class ChAnimData;
class LeonaAnimation : public ChAnimation
{
public:
	ChAnimData* mData;

	// ChAnimation��(��) ���� ��ӵ�
	void Init(Lookat dir) override;
	void ImgUpdate(AnimStatus playerStatus) override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;
	FLOAT moveAfterAction(FLOAT pos) override;
};
