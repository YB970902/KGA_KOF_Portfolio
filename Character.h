#pragma once
#include "Config.h"
#include "GameObject.h"
#include "CommonFunction.h"
#include <vector>

using namespace std;

class Character : public GameObject
{
protected:
	Character* mTarget = nullptr;
	RECT mSmallHitBox = RECT();
	RECT mBigHitBox = RECT();
	int mFrame = 0;
	int mHP = 0;
	MoveDir mDir = MoveDir::Right;

	vector<Character*> mHitChar = {};

public:
	Character() {};
	~Character() {};

	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void Move(int dir);
	bool CheckHitChar();

	void OnSmallHitBox(int dir);
	void OffSmallHitBox();
	void OnBigHitBox(int dir);
	void OffBigHitBox();

	void AllOffHitBox();

	inline void SetTarget(Character* ch) { this->mTarget = ch; }

	inline Character* GetTarget() { return mTarget; }
	inline RECT GetShape() { return shape; }
	inline RECT GetSmallHitBox() { return mSmallHitBox; }
	inline int GetFrame() { return mFrame; }
	inline MoveDir GetDir() { return mDir; }
	
	static void LeftMove(Character* ch) { ch->Move((int)MoveDir::Left); }
	static void RightMove(Character* ch) { ch->Move((int)MoveDir::Right); }
	static void OnSmallHitBox(Character* ch) { ch->OnSmallHitBox((int)ch->GetDir()); }
	static void OnBigHitBox(Character* ch) { ch->OnBigHitBox((int)ch->GetDir()); }
};

 
