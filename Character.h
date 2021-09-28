#pragma once
#include "Config.h"
#include "GameObject.h"
#include "CommonFunction.h"
#include "AnimationScene.h"
#include "Character.h"
#include "ChAnimData.h"
#include <vector>

class Character : public GameObject
{
protected:
	Character* mpTarget = nullptr;
	ChAnimData* mpmData = nullptr;

	ChAnimData* mpData = nullptr;

	RECT mWeakPunchHitBox = RECT();
	RECT mStrongPunchHitBox = RECT();
	RECT mWeakKickHitBox = RECT();
	RECT mStrongKickHitBox = RECT();

	RECT mNearWeakPunchHitBox = RECT();
	RECT mNearStrongPunchHitBox = RECT();
	RECT mNearWeakKickHitBox = RECT();
	RECT mNearStrongKickHitBox = RECT();

	int mFrame = 0;
	int mFrameX = 0, mFrameY = 0;
	int mMaxHP = 0;
	int mHP = 0;

	float mAcceleration = 0.0f;
	float mResistance = 0.0f;
	bool mbIsHit = false;
	bool mbPrintHitBox = false;

	eMoveDir mDir = eMoveDir::Right;

	vector<Character*> mHitChar = {};
public:
	Character() {};
	~Character() {};

	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	bool CheckHitChar();

	void OnWeakPunchHitBox(int dir, ChAnimData* charamData);
	void OffWeakPunchHitBox();
	void OnStrongPunchHitBox(int dir, ChAnimData* charamData);
	void OffStrongPunchHitBox();
	void OnWeakKickHitBox(int dir, ChAnimData* charamData);
	void OffWeakKickHitBox();
	void OnStrongKickHitBox(int dir, ChAnimData* charamData);
	void OffStrongKickHitBox();

	void OnNearWeakPunchHitBox(int dir, ChAnimData* charamData);
	void OffNearWeakPunchHitBox();
	void OnNearWeakKickHitBox(int dir, ChAnimData* charamData);
	void OffNearWeakKickHitBox();
	void OnNearStrongPunchHitBox(int dir, ChAnimData* charamData);
	void OffNearStrongPunchHitBox();
	void OnNearStrongKickHitBox(int dir, ChAnimData* charamData);
	void OffNearStrongKickHitBox();

	void AllOffHitBox();

	inline void SetHP(int hp) { this->mHP -= hp; }
	inline void SetPosX(int pixel) { this->pos.x -= pixel; }
	inline void SetAcceleration(float val) { this->mAcceleration = val; }
	inline void SetResistance(float val) { this->mResistance = val; }
	inline void SetPrintHitBox(bool b) { this->mbPrintHitBox = b; }
	inline void SetFrameX(int frame) { this->mFrameX = frame; }
	inline void SetIsHit(bool b) { this->mbIsHit = b; }

	inline int GetFrameX() { return this->mFrameX; }
	inline Character* GetTarget() { return mpTarget; }
	inline ChAnimData* GetmpmData() { return mpmData; }
	inline ChAnimData* GetData() { return mpData; }
	inline bool GetPrintHitBox() { return mbPrintHitBox; }

	inline RECT GetShape() { return shape; }
	inline int GetHP() { return mHP; }
	inline RECT GetSmallHitBox() { return mWeakPunchHitBox; }
	inline int GetFrame() { return mFrame; }
	inline eMoveDir GetDir() { return mDir; }
	inline float GetHPWeight() { return (float)mHP / (float)mMaxHP; }
	inline bool GetIsHit() { return mbIsHit; }
	inline void SetTarget(Character* ch) { this->mpTarget = ch; }

	void Move(int dir);
	void SetShape();

	static void LeftMove(Character* ch) { ch->Move((int)eMoveDir::Left); }
	static void RightMove(Character* ch) { ch->Move((int)eMoveDir::Right); }
	static void OnWeakPunchHitBox(Character* ch, ChAnimData* an) { ch->OnWeakPunchHitBox((int)ch->GetDir(), an); }
	static void OnStrongPunchHitBox(Character* ch, ChAnimData* an) { ch->OnStrongPunchHitBox((int)ch->GetDir(), an); }
	static void OnWeakKickHitBox(Character* ch, ChAnimData* an) { ch->OnWeakKickHitBox((int)ch->GetDir(), an); }
	static void OnStrongKickHitBox(Character* ch, ChAnimData* an) { ch->OnStrongKickHitBox((int)ch->GetDir(), an); }

	static void OnNearWeakPunchHitBox(Character* ch, ChAnimData* an) { ch->OnNearWeakPunchHitBox((int)ch->GetDir(), an); }
	static void OnNearWeakKickHitBox(Character* ch, ChAnimData* an) { ch->OnNearWeakKickHitBox((int)ch->GetDir(), an); }
	static void OnNearStrongPunchHitBox(Character* ch, ChAnimData* an) { ch->OnNearStrongPunchHitBox((int)ch->GetDir(), an); }
	static void OnNearStrongKickHitBox(Character* ch, ChAnimData* an) { ch->OnNearStrongKickHitBox((int)ch->GetDir(), an); }
};