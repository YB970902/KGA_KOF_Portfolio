#pragma once
#include "Config.h"
#include "GameObject.h"
#include "Singleton.h"
#include "KeyManager.h"

class Command;
class Character : public GameObject
{
private:
	Command* mLeftMove = nullptr;
	Command* mRightMove = nullptr;
	Command* mChangeIsControl = nullptr;
public:
	Character() {};
	~Character() {};
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void Move(int dir);
	void ChangeIsControl();

	static void LeftMove(Character* ch) { ch->Move(-1); }
	static void RightMove(Character* ch) { ch->Move(1); }
	static void ChangeIsControl(Character* ch) { ch->ChangeIsControl(); }

	void ProcessInputKey();
};


