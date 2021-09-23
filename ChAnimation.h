#pragma once
#include "Character.h"
#include "ChAnimData.h"

//#include "Image.h"	// 컴파일 관계가 복잡, 컴파일 시간이 오래 걸림

using namespace std;

class Image;	// 포함관계
class ChAnimation : public Character	// 상속관계
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