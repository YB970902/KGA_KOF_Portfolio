#pragma once
#include "Config.h"
#include "GameObject.h"
#include "CommonFunction.h"
#include <vector>

class Character : public GameObject
{
protected:
	RECT mWeakPunchHitBox = RECT();
	RECT mStrongPunchHitBox = RECT();
	RECT mWeakKickHitBox = RECT();
	RECT mStrongKickHitBox = RECT();

	int mFrame = 0;
	int mHP = 0;
	eMoveDir mDir = eMoveDir::Right;

	vector<Character*> mHitChar = {};

	Character* mpTarget = nullptr;

public:
	Character() {};
	~Character() {};

	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

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

	inline void SetHP(int hp) { this->mHP -= hp; }

	inline RECT GetShape() { return shape; }
	inline int GetHP() { return mHP; }
	inline RECT GetSmallHitBox() { return mWeakPunchHitBox; }
	inline int GetFrame() { return mFrame; }
	inline eMoveDir GetDir() { return mDir; }

	inline void SetTarget(Character* ch) { this->mpTarget = ch; }
	static void OnWeakPunchHitBox(Character* ch) { ch->OnWeakPunchHitBox((int)ch->GetDir()); }
	static void OnStrongPunchHitBox(Character* ch) { ch->OnStrongPunchHitBox((int)ch->GetDir()); }
	static void OnWeakKickHitBox(Character* ch) { ch->OnWeakKickHitBox((int)ch->GetDir()); }
	static void OnStrongKickHitBox(Character* ch) { ch->OnStrongKickHitBox((int)ch->GetDir()); }
};