#pragma once
#include "Character.h"
#include "Config.h"

//#include "Image.h"	// ������ ���谡 ����, ������ �ð��� ���� �ɸ�

class ChAnimData;
class Image;	// ���԰���
class ChAnimation : public Character	// ��Ӱ���
{
protected:
	Image* img = nullptr;
	int mFrameX = 0, mFrameY = 0;
	int mElapsedCount = 0;

	ChAnimData* mpData = nullptr;

public:
	virtual void Init(eLookat dir) {};

	virtual void ImgUpdate(eAnimStatus playerStatus);
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual FLOAT moveAfterAction(FLOAT pos);

	void Attack(eAnimStatus type);
	void MoveLeft();
	void MoveRight();

	inline void SetFrameX(int frame) { this->mFrameX = frame; }

	inline ChAnimData* GetData() { return this->mpData; }
	inline int GetFrameX() { return this->mFrameX; }


	static void WeakPunchCommand(ChAnimation* character) { character->Attack(eAnimStatus::Weak_Punch); }
	static void StrongPunchCommand(ChAnimation* character) { character->Attack(eAnimStatus::Strong_Punch); }
	static void WeakKickCommand(ChAnimation* character) { character->Attack(eAnimStatus::Weak_Kick); }
	static void StrongKickCommand(ChAnimation* character) { character->Attack(eAnimStatus::Strong_Kick); }
	static void MoveLeftCommand(ChAnimation* character) { character->MoveLeft(); }
	static void MoveRightCommand(ChAnimation* character) { character->MoveRight(); }
};

static int baseX;
static int baseY;