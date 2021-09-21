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
	mpSmallAttack = new Command;
	mpSmallAttack->Init(mpRect1, Character::OnSmallHitBox);
	mpBigAttack = new Command;
	mpBigAttack->Init(mpRect1, Character::OnBigHitBox);
}

void HitBoxScene::Update()
{
	if (mpLeftMoveCom->GetCharacter()->GetFrame() > 5)
	{
		if (MGR_KEY->IsOnceKeyDown('G'))
		{
			mpSmallAttack->Execute();
		}
		else if (MGR_KEY->IsOnceKeyDown('Y'))
		{
			mpBigAttack->Execute();
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

	mpRect1->Update();
	mpRect2->Update();

	if (MGR_KEY->IsOnceKeyDown(VK_SPACE))
	{
		if (mpLeftMoveCom->GetCharacter() == mpRect1)
		{
			mpLeftMoveCom->Init(mpRect2, Character::LeftMove);
			mpRightMoveCom->Init(mpRect2, Character::RightMove);
			mpSmallAttack->Init(mpRect2, Character::OnSmallHitBox);
			mpBigAttack->Init(mpRect2, Character::OnBigHitBox);
			mpRect1->SetTarget(nullptr);
			mpRect2->SetTarget(mpRect1);
		}
		else
		{
			mpLeftMoveCom->Init(mpRect1, Character::LeftMove);
			mpRightMoveCom->Init(mpRect1, Character::RightMove);
			mpSmallAttack->Init(mpRect1, Character::OnSmallHitBox);
			mpBigAttack->Init(mpRect1, Character::OnBigHitBox);
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
	SAFE_RELEASE(mpSmallAttack);
	SAFE_RELEASE(mpBigAttack);
}
