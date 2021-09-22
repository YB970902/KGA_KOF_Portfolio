#pragma once
#include "Config.h"
#include "GameObject.h"
#include "CommonFunction.h"
#include <vector>

class Character : public GameObject
{
protected:
	Character* mpTarget = nullptr;

	RECT mWeakPunchHitBox = RECT();
	RECT mStrongPunchHitBox = RECT();
	RECT mWeakKickHitBox = RECT();
	RECT mStrongKickHitBox = RECT();

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

	void OnWeakPunchHitBox(int dir);
	void OffWeakPunchHitBox();
	void OnStrongPunchHitBox(int dir);
	void OffStrongPunchHitBox();	
	void OnWeakKickHitBox(int dir);
	void OffWeakKickHitBox();
	void OnStrongKickHitBox(int dir);
	void OffStrongKickHitBox();

	void AllOffHitBox();

	inline void SetTarget(Character* ch) { this->mpTarget = ch; }

	inline Character* GetTarget() { return mpTarget; }
	inline RECT GetShape() { return shape; }
	inline RECT GetSmallHitBox() { return mWeakPunchHitBox; }
	inline int GetFrame() { return mFrame; }
	inline MoveDir GetDir() { return mDir; }
	
	static void LeftMove(Character* ch) { ch->Move((int)MoveDir::Left); }
	static void RightMove(Character* ch) { ch->Move((int)MoveDir::Right); }
	static void OnWeakPunchHitBox(Character* ch) { ch->OnWeakPunchHitBox((int)ch->GetDir()); }
	static void OnStrongPunchHitBox(Character* ch) { ch->OnStrongPunchHitBox((int)ch->GetDir()); }
	static void OnWeakKickHitBox(Character* ch) { ch->OnWeakKickHitBox((int)ch->GetDir()); }
	static void OnStrongKickHitBox(Character* ch) { ch->OnStrongKickHitBox((int)ch->GetDir()); }
};