#include "HitBoxScene.h"
#include "Character.h"
#include "Command.h"
#include "KeyManager.h"

void HitBoxScene::Enter()
{
	mpRect1 = new Character;
	mpRect1->Init();
	POINTFLOAT pos;
	pos.x = 870;
	pos.y = WIN_SIZE_Y / 2;
	mpRect1->SetPos(pos);

	mpRect2 = new Character;
	mpRect2->Init();
	pos.x = 1000;
	mpRect2->SetPos(pos);

	mpRect1->SetTarget(mpRect2);
	mpRect2->SetTarget(mpRect1);

	mpLeftMoveCom = new Command;
	mpLeftMoveCom->Init(mpRect1, Character::LeftMove);


	mpRightMoveCom = new Command;
	mpRightMoveCom->Init(mpRect1, Character::RightMove);
	mpWeakPunchAttack = new Command;
	mpWeakPunchAttack->Init(mpRect1, Character::OnWeakPunchHitBox);
	mpStrongPunchAttack = new Command;
	mpStrongPunchAttack->Init(mpRect1, Character::OnStrongPunchHitBox);
	mpWeakKickAttack = new Command;
	mpWeakKickAttack->Init(mpRect1, Character::OnWeakKickHitBox);
	mpStrongKickAttack = new Command;
	mpStrongKickAttack->Init(mpRect1, Character::OnStrongKickHitBox);


	mpLeftMoveCom1 = new Command;
	mpLeftMoveCom1->Init(mpRect2, Character::LeftMove); 
	mpRightMoveCom1 = new Command;
	mpRightMoveCom1->Init(mpRect2, Character::RightMove);
	mpWeakPunchAttack1 = new Command;
	mpWeakPunchAttack1->Init(mpRect2, Character::OnWeakPunchHitBox);
	mpStrongPunchAttack1 = new Command;
	mpStrongPunchAttack1->Init(mpRect2, Character::OnStrongPunchHitBox);
	mpWeakKickAttack1 = new Command;
	mpWeakKickAttack1->Init(mpRect2, Character::OnWeakKickHitBox);
	mpStrongKickAttack1 = new Command;
	mpStrongKickAttack1->Init(mpRect2, Character::OnStrongKickHitBox);
}

void HitBoxScene::Update()
{
	if (mpLeftMoveCom->GetCharacter()->GetFrame() > 5)
	{
		if (MGR_KEY->IsOnceKeyDown('G'))
		{
			mpWeakPunchAttack->Execute();
		}
		else if (MGR_KEY->IsOnceKeyDown('Y'))
		{
			mpStrongPunchAttack->Execute();
		}
		else if (MGR_KEY->IsOnceKeyDown('H'))
		{
			mpWeakKickAttack->Execute();
		}
		else if (MGR_KEY->IsOnceKeyDown('U'))
		{
			mpStrongKickAttack->Execute();
		}
		else if (MGR_KEY->IsStayKeyDown('A'))
		{
			mpLeftMoveCom->Execute();
		}
		else if (MGR_KEY->IsStayKeyDown('D'))
		{
			mpRightMoveCom->Execute();
		}
	}

	if (mpLeftMoveCom1->GetCharacter()->GetFrame() > 5)
	{
		if (MGR_KEY->IsOnceKeyDown('N'))
		{
			mpWeakPunchAttack1->Execute();
		}
		else if (MGR_KEY->IsOnceKeyDown('J'))
		{
			mpStrongPunchAttack1->Execute();
		}
		else if (MGR_KEY->IsOnceKeyDown('M'))
		{
			mpWeakKickAttack1->Execute();
		}
		else if (MGR_KEY->IsOnceKeyDown('K'))
		{
			mpStrongKickAttack1->Execute();
		}
		else if (MGR_KEY->IsStayKeyDown(VK_LEFT))
		{
			mpLeftMoveCom1->Execute();
		}
		else if (MGR_KEY->IsStayKeyDown(VK_RIGHT))
		{
			mpRightMoveCom1->Execute();
		}
	}

	mpRect1->Update();
	mpRect2->Update();

	if (MGR_KEY->IsOnceKeyDown(VK_SPACE))
	{
		if (mpLeftMoveCom->GetCharacter() == mpRect1)
		{
			mpLeftMoveCom->Init(mpRect2, Character::LeftMove);
			mpRightMoveCom->Init(mpRect2, Character::RightMove);
			mpWeakPunchAttack->Init(mpRect2, Character::OnWeakPunchHitBox);
			mpStrongPunchAttack->Init(mpRect2, Character::OnStrongPunchHitBox);
			mpRect1->SetTarget(nullptr);
			mpRect2->SetTarget(mpRect1);
		}
		else
		{
			mpLeftMoveCom->Init(mpRect1, Character::LeftMove);
			mpRightMoveCom->Init(mpRect1, Character::RightMove);
			mpWeakPunchAttack->Init(mpRect1, Character::OnWeakPunchHitBox);
			mpStrongPunchAttack->Init(mpRect1, Character::OnStrongPunchHitBox);
			mpRect2->SetTarget(nullptr);
			mpRect1->SetTarget(mpRect2);
		}
	}
}

void HitBoxScene::Render(HDC hdc)
{
	// 이 부분에서 렌더링 작업
	mpRect1->Render(hdc);
	mpRect2->Render(hdc);
}

void HitBoxScene::Exit()
{
	SAFE_RELEASE(mpRect1);
	SAFE_RELEASE(mpRect2);

	SAFE_RELEASE(mpLeftMoveCom);
	SAFE_RELEASE(mpRightMoveCom);
	SAFE_RELEASE(mpWeakPunchAttack);
	SAFE_RELEASE(mpStrongPunchAttack);
}
