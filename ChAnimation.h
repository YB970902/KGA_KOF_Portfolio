#pragma once
#include "Character.h"
#include "ChAnimData.h"

//#include "Image.h"	// ������ ���谡 ����, ������ �ð��� ���� �ɸ�

using namespace std;

class Image;	// ���԰���
class ChAnimation : public Character	// ��Ӱ���
{
protected:
	Image* img;
	int frameX, frameY;
	int elapsedCount;

	ChAnimation* mpTarget = nullptr;

	ChAnimation* Player = nullptr;

public:
	virtual void Init() {};
	virtual void ImgUpdate(AnimStatus playerStatus) {};
	virtual void Update() {};
	virtual void Render(HDC hdc) {};
	virtual void Release() {};

	virtual FLOAT moveAfterAction(FLOAT pos) { return 0.0f; };
};

static int baseX;
static int baseY;