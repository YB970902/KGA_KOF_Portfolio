#pragma once
#include "Config.h"
#include "GameObject.h"
#include "CommonFunction.h"

class Character : public GameObject
{
protected:
	Character* mTarget = nullptr;
	RECT mSmallHitBox = RECT();
	RECT mBigHitBox = RECT();
	int mFrame = 0;
	int mHP = 0;
public:
	Character() {};
	~Character() {};

	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void Move(int dir);
	void OnSmallHitBox();
	void OffSmallHitBox();
	void OnBigHitBox();
	void OffBigHitBox();

	void AllOffHitBox();

	inline void SetTarget(Character* ch) { this->mTarget = ch; }

	inline Character* GetTarget() { return mTarget; }
	inline RECT GetShape() { return shape; }
	inline RECT GetSmallHitBox() { return mSmallHitBox; }
	inline int GetFrame() { return mFrame; }
	
	static void LeftMove(Character* ch) { ch->Move(-1); }
	static void RightMove(Character* ch) { ch->Move(1); }
	static void OnSmallHitBox(Character* ch) { ch->OnSmallHitBox(); }
	static void OnBigHitBox(Character* ch) { ch->OnBigHitBox(); }
};


