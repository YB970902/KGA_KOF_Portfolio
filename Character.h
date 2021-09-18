#pragma once
#include "Config.h"
#include "GameObject.h"
#include "Singleton.h"
#include "KeyManager.h"

class Command;
class Character : public GameObject
{
private:
	Command* mLeftMove;
	Command* mRightMove;
public:
	Character() {};
	~Character() {};
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	

	void Move(int dir) { pos.x += moveSpeed * dir; }

	static void LeftMove(Character* ch) { ch->Move(-1); }
	static void RightMove(Character* ch) { ch->Move(1); }

	void ProcessInputKey();

	inline float GetMoveSpeed() { return this->moveSpeed; }
	
};


