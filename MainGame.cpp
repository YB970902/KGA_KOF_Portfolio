#include "MainGame.h"
#include "Singleton.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "Image.h"
#include "Character.h"
#include "Command.h"

void MainGame::Init()
{
	MGR_KEY->Init();

	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 100 , NULL);

	mousePosX = 0;
	mousePosY = 0;
	clickedMousePosX = 0;
	clickedMousePosY = 0;

	mRect1 = new Character;
	mRect1->Init();
	POINTFLOAT pos;
	pos.x = 870;
	pos.y = WIN_SIZE_Y/2;
	mRect1->SetPos(pos);

	mRect2 = new Character;
	mRect2->Init();
	pos.x = 1000;
	mRect2->SetPos(pos);

	mRect1->SetTarget(mRect2);
	mRect2->SetTarget(mRect1);

	backBuffer = new Image;
	backBuffer->Init(WIN_SIZE_X, WIN_SIZE_Y);

	backGround = new Image;
	backGround->Init("Image/mapImage.bmp", WIN_SIZE_X, WIN_SIZE_Y);

	mLeftMoveCom = new Command;
	mLeftMoveCom->Init(mRect1, Character::LeftMove);
	mRightMoveCom = new Command;
	mRightMoveCom->Init(mRect1, Character::RightMove);
	mSmallAttack = new Command;
	mSmallAttack->Init(mRect1, Character::OnSmallHitBox);
	mBigAttack = new Command;
	mBigAttack->Init(mRect1, Character::OnBigHitBox);
}

void MainGame::Update()
{
	InvalidateRect(g_hWnd, NULL, false);
	
	if (mLeftMoveCom->GetCharacter()->GetFrame() > 5)
	{
		if (MGR_KEY->IsOnceKeyDown('G'))
		{
			mSmallAttack->Execute();
		}
		else if (MGR_KEY->IsOnceKeyDown('Y'))
		{
			mBigAttack->Execute();
		}
		else if (MGR_KEY->IsStayKeyDown('A'))
		{
			mLeftMoveCom->Execute();
		}
		else if (MGR_KEY->IsStayKeyDown('D'))
		{
			mRightMoveCom->Execute();
		}
	}

	mRect1->Update();
	mRect2->Update();

	if (MGR_KEY->IsOnceKeyDown(VK_SPACE))
	{
		if (mLeftMoveCom->GetCharacter() == mRect1)
		{
			mLeftMoveCom->Init(mRect2, Character::LeftMove);
			mRightMoveCom->Init(mRect2, Character::RightMove);
			mSmallAttack->Init(mRect2, Character::OnSmallHitBox);
			mBigAttack->Init(mRect2, Character::OnBigHitBox);
			mRect1->SetTarget(nullptr);
			mRect2->SetTarget(mRect1);
		}
		else
		{
			mLeftMoveCom->Init(mRect1, Character::LeftMove);
			mRightMoveCom->Init(mRect1, Character::RightMove);
			mSmallAttack->Init(mRect1, Character::OnSmallHitBox);
			mBigAttack->Init(mRect1, Character::OnBigHitBox);
			mRect2->SetTarget(nullptr);
			mRect1->SetTarget(mRect2);
		}
	}
}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = backBuffer->GetMemDC();

	backGround->Render(hBackBufferDC);

	// 이 부분에서 렌더링 작업
	mRect1->Render(hBackBufferDC);
	mRect2->Render(hBackBufferDC);

	backBuffer->Render(hdc);
}

void MainGame::Release()
{
	SAFE_RELEASE(mRect1);
	SAFE_RELEASE(mRect2);

	SAFE_RELEASE(mLeftMoveCom);
	SAFE_RELEASE(mRightMoveCom);
	SAFE_RELEASE(mSmallAttack);
	SAFE_RELEASE(mBigAttack);

	SAFE_RELEASE(backBuffer);
	SAFE_RELEASE(backGround);

	KillTimer(g_hWnd, 0);

	MGR_KEY->ReleaseSingleton();
}


LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_LBUTTONDOWN:
		clickedMousePosX = LOWORD(lParam);
		clickedMousePosY = HIWORD(lParam);
		break;
	case WM_MOUSEMOVE:
		mousePosX = LOWORD(lParam);
		mousePosY = HIWORD(lParam);
		break;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}