#pragma once
#include "Character.h"

//#include "Image.h"	// 컴파일 관계가 복잡, 컴파일 시간이 오래 걸림

using namespace std;

class ChAnimData;
class Image;	// 포함관계
class ChAnimation : public Character	// 상속관계
{
protected:
	Image* img;
	int frameX, frameY;
	int elapsedCount;

	ChAnimation* mpTarget = nullptr;

	ChAnimation* Player = nullptr;

	ChAnimData* mpData = nullptr;

public:
	virtual void Init(Lookat dir) {};

	virtual void ImgUpdate(AnimStatus playerStatus);
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual FLOAT moveAfterAction(FLOAT pos);

	void Attack(AnimStatus type);
	void MoveLeft();
	void MoveRight();

	inline ChAnimData* GetData() { return mpData; }
	static void AttackCommand(ChAnimation* character) { character->Attack(AnimStatus::Weak_Punch); }
	static void MoveLeftCommand(ChAnimation* character) { character->MoveLeft(); }
	static void MoveRightCommand(ChAnimation* character) { character->MoveRight(); }
};

static int baseX;
static int baseY;