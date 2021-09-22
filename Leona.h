#pragma once
#include "ChAnimData.h"

class Leona : public ChAnimData
{
public:
	ChAnimData mData;

	Lookat playerLookat;
	AnimStatus playerStatus;
	Acting playerAct;

	//static bool isAction = false;		// 추후에 아래 세개의 변수를 isAction으로 통합시킬수 있는지 판단필요 (조건문에 &&을 넣어야 하는건가;)
	bool isAttack = false;				// 공격은 액션인데 공격중 다른공격을 할수는 없다.
	bool isJump = false;				// 점프는 액션인데 점프중에는 공격을 할 수 있지만 자유로운 이동은 불가하다. 반드시 정해진 방향으로만 이동
	bool isSit = false;					// 앉은상태는 액션인데 공격을 할수 있다.
										// isAction이 켜진상태에서 이동을 할 수 없는것을 만들기위해 하나의 트리거로 조건을 거는것은 애매하다는 판단
	bool notReverse;

	void init();
};
