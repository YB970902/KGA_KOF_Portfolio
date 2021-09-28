#pragma once
#include "Character.h"
#include "Config.h"

//#include "Image.h"	// 컴파일 관계가 복잡, 컴파일 시간이 오래 걸림

class ChAnimData;
class Image;	// 포함관계
class ChAnimation : public Character	// 상속관계
{
protected:
	Image* img = nullptr;
	int mElapsedCount = 0;

	bool mbNotMove = false;

	const int KnockBackPixel = 30;

public:
	virtual void Init(eLookat dir) {};

	virtual void ImgUpdate(eAnimStatus playerStatus);
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual FLOAT moveAfterAction(FLOAT pos);

	void Damaged(eAnimStatus type);
	void Attack(eAnimStatus type);
	void MoveLeft();
	void MoveRight();

	void HitTarget(int damage, float KnockBackPixel);

	inline void SetNotMove(bool b) { this->mbNotMove = b; }

	inline eLookat GetLookAt() { return mpData->mPlayerLookat; }
	inline float CalculationAcceleration(float knockbackpixel) { return knockbackpixel * 0.3f; }

	static void WeakPunchCommand(ChAnimation* character) { character->Attack(eAnimStatus::Weak_Punch); }
	static void StrongPunchCommand(ChAnimation* character) { character->Attack(eAnimStatus::Strong_Punch); }
	static void WeakKickCommand(ChAnimation* character) { character->Attack(eAnimStatus::Weak_Kick); }
	static void StrongKickCommand(ChAnimation* character) { character->Attack(eAnimStatus::Strong_Kick); }

	static void NearWeakPunchCommand(ChAnimation* character) { character->Attack(eAnimStatus::Near_Weak_Punch); }
	static void NearStrongPunchCommand(ChAnimation* character) { character->Attack(eAnimStatus::Near_Strong_Punch); }
	static void NearWeakKickCommand(ChAnimation* character) { character->Attack(eAnimStatus::Near_Weak_Kick); }
	static void NearStrongKickCommand(ChAnimation* character) { character->Attack(eAnimStatus::Near_Strong_Kick); }

	static void MoveLeftCommand(ChAnimation* character) { character->MoveLeft(); }
	static void MoveRightCommand(ChAnimation* character) { character->MoveRight(); }
};

static int baseX;
static int baseY;