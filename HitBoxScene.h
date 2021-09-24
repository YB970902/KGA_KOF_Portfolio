<<<<<<< HEAD
//#pragma once
//#include "Config.h"
//#include "Scene.h"
//
//class Character;
//class Command;
//class HitBoxScene : public Scene
//{
//	Character* mpRect1 = nullptr;
//	Character* mpRect2 = nullptr;
//
//	Command* mpLeftMoveCom = nullptr;
//	Command* mpRightMoveCom = nullptr;
//	Command* mpWeakPunchAttack = nullptr;
//	Command* mpStrongPunchAttack = nullptr;
//	Command* mpWeakKickAttack = nullptr;
//	Command* mpStrongKickAttack = nullptr;
//
//
//	Command* mpLeftMoveCom1 = nullptr;
//	Command* mpRightMoveCom1 = nullptr;
//	Command* mpWeakPunchAttack1 = nullptr;
//	Command* mpStrongPunchAttack1 = nullptr;
//	Command* mpWeakKickAttack1 = nullptr;
//	Command* mpStrongKickAttack1 = nullptr;
//	
//	virtual void Enter() override;
//	virtual void Update() override;
//	virtual void Render(HDC hdc) override;
//	virtual void Exit() override;
//};
=======
#pragma once
#include "Config.h"
#include "Scene.h"

class Character;
class Command;
class AnimCommand;
class HitBoxScene : public Scene
{
	Character* mpRect1 = nullptr;
	Character* mpRect2 = nullptr;

	Command* mpLeftMoveCom = nullptr;
	Command* mpRightMoveCom = nullptr;
	AnimCommand* mpWeakPunchAttack = nullptr;
	AnimCommand* mpStrongPunchAttack = nullptr;
	AnimCommand* mpWeakKickAttack = nullptr;
	AnimCommand* mpStrongKickAttack = nullptr;


	Command* mpLeftMoveCom1 = nullptr;
	Command* mpRightMoveCom1 = nullptr;
	AnimCommand* mpWeakPunchAttack1 = nullptr;
	AnimCommand* mpStrongPunchAttack1 = nullptr;
	AnimCommand* mpWeakKickAttack1 = nullptr;
	AnimCommand* mpStrongKickAttack1 = nullptr;
	
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;
};
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9

