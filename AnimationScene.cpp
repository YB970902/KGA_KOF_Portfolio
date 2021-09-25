#include "AnimationScene.h"
#include "BluemaryAnimation.h"
#include "ChAnimation.h"
#include "ChAnimData.h"
#include "Command.h"
#include "KeyManager.h"
#include "LeonaAnimation.h"
#include "RalfAnimation.h"
#include "Image.h"
#include "HealthBar.h"


void AnimationScene::Enter()
{
	switch (Player1)
	{
	case 1:
		mPlayer1 = new BluemaryAnimation;
		break;
	case 2:
		mPlayer1 = new RalfAnimation;
		break;
	case 3:
		mPlayer1 = new LeonaAnimation;
		break;
	}

	switch (Player2)
	{
	case 1:
		mPlayer2 = new BluemaryAnimation;
		break;
	case 2:
		mPlayer2 = new RalfAnimation;
		break;
	case 3:
		mPlayer2 = new LeonaAnimation;
		break;
	}

	mPlayer1->Init(eLookat::Right_Lookat);
	mPlayer2->Init(eLookat::Left_Lookat);

	POINTFLOAT pos;
	pos.x = 200;
	pos.y = 600;
	mPlayer1->SetPos(pos);
	pos.x = 1000;
	mPlayer2->SetPos(pos);

	mPlayer1->SetTarget(mPlayer2);
	mPlayer2->SetTarget(mPlayer1);

	mWeakPunch1 = new Command;
	mWeakPunch1->Init(mPlayer1, ChAnimation::WeakPunchCommand);

	mStrongPunch1 = new Command;
	mStrongPunch1->Init(mPlayer1, ChAnimation::StrongPunchCommand);

	mWeakKick1 = new Command;
	mWeakKick1->Init(mPlayer1, ChAnimation::WeakKickCommand);

	mStrongKick1 = new Command;
	mStrongKick1->Init(mPlayer1, ChAnimation::StrongKickCommand);

	mMoveLeft1 = new Command;
	mMoveLeft1->Init(mPlayer1, ChAnimation::MoveLeftCommand);

	mMoveRight1 = new Command;
	mMoveRight1->Init(mPlayer1, ChAnimation::MoveRightCommand);



	mWeakPunch2 = new Command;
	mWeakPunch2->Init(mPlayer2, ChAnimation::WeakPunchCommand);

	mStrongPunch2 = new Command;
	mStrongPunch2->Init(mPlayer2, ChAnimation::StrongPunchCommand);

	mWeakKick2 = new Command;
	mWeakKick2->Init(mPlayer2, ChAnimation::WeakKickCommand);

	mStrongKick2 = new Command;
	mStrongKick2->Init(mPlayer2, ChAnimation::StrongKickCommand);

	mMoveLeft2 = new Command;
	mMoveLeft2->Init(mPlayer2, ChAnimation::MoveLeftCommand);

	mMoveRight2 = new Command;
	mMoveRight2->Init(mPlayer2, ChAnimation::MoveRightCommand);

	mpArrBackground = new Image * [39];
	for (int i = 0; i < 39; i++)
	{
		mpArrBackground[i] = new Image();
	}

	char temp[128];
	for (int i = 0; i < 39; i++)
	{
		wsprintf(temp, "Image/BattleBackground/frame_%02d_delay.bmp", i);
		mpArrBackground[i]->Init(temp, WIN_SIZE_X * 2, WIN_SIZE_Y);
	}

	mPlayer1Bar = new HealthBar();
	mPlayer1Bar->Init();
	mPlayer1Bar->SetHealthBarDir(eHealthBarDir::Left);
	mPlayer2Bar = new HealthBar();
	mPlayer2Bar->Init();
	mPlayer2Bar->SetHealthBarDir(eHealthBarDir::Right);

	POINTFLOAT player1BarPos;
	player1BarPos.x = 300;
	player1BarPos.y = 100;
	mPlayer1Bar->SetPosition(player1BarPos);

	POINTFLOAT player2BarPos;
	player2BarPos.x = 900;
	player2BarPos.y = 100;
	mPlayer2Bar->SetPosition(player2BarPos);
}

void AnimationScene::Update()
{
	mCurElapseTime++;
	if (mCurElapseTime > 3)
	{
		mCurElapseTime = 0;
		mCurBackgroundFrame++;
		if (mCurBackgroundFrame >= MaxBackGroundFrame)
		{
			mCurBackgroundFrame = 0;
		}
	}

	if (MGR_KEY->IsStayKeyDown('A'))
	{
		mBackgroundPosX -= 5;
	}
	else if (MGR_KEY->IsStayKeyDown('D'))
	{
		mBackgroundPosX += 5;
	}

	if (mPlayer1->GetData()->mIsAttack == false)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown('G'))
		{
			mWeakPunch1->Execute();
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('Y'))
		{
			mStrongPunch1->Execute();
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('H'))
		{
			mWeakKick1->Execute();
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('U'))
		{
			mStrongKick1->Execute();
		}
	}

	if (mPlayer1->GetData()->mPlayerAct != eActing::Act_Attack)
	{
		if (KeyManager::GetSingleton()->IsStayKeyDown('A'))
		{
			mMoveLeft1->Execute();
		}
		else if (KeyManager::GetSingleton()->IsStayKeyDown('D'))
		{
			mMoveRight1->Execute();
		}
		else
		{
			if (mPlayer1->GetData()->mPlayerAct != eActing::Act_Idle)
			{
				mPlayer1->SetFrameX(0);
			}
			mPlayer1->GetData()->mPlayerAct = eActing::Act_Idle;
			mPlayer1->GetData()->mPlayerStatus = eAnimStatus::Idle;
		}
	}


	if (mPlayer2->GetData()->mIsAttack == false)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown('N'))
		{
			mWeakPunch2->Execute();
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('J'))
		{
			mStrongPunch2->Execute();
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('M'))
		{
			mWeakKick2->Execute();
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('K'))
		{
			mStrongKick2->Execute();
		}
	}

	if (mPlayer2->GetData()->mPlayerAct != eActing::Act_Attack)
	{
		if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
		{
			mMoveLeft2->Execute();
		}
		else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
		{
			mMoveRight2->Execute();
		}
		else
		{
			if (mPlayer2->GetData()->mPlayerAct != eActing::Act_Idle)
			{
				mPlayer2->SetFrameX(0);
			}
			mPlayer2->GetData()->mPlayerAct = eActing::Act_Idle;
			mPlayer2->GetData()->mPlayerStatus = eAnimStatus::Idle;
		}
	}

	if (MGR_KEY->IsOnceKeyDown('1')) { mPlayer2Bar->SetValue(1.0f); }
	if (MGR_KEY->IsOnceKeyDown('2')) { mPlayer2Bar->SetValue(0.5f); }
	if (MGR_KEY->IsOnceKeyDown('3')) { mPlayer2Bar->SetValue(0.25f); }
	if (MGR_KEY->IsOnceKeyDown('4')) { mPlayer2Bar->SetValue(0.0f); }

	mPlayer1->Update();

	mPlayer2->Update();
}

void AnimationScene::Render(HDC hdc)
{
	mpArrBackground[mCurBackgroundFrame]->Render(hdc, WIN_SIZE_X / 2 + mBackgroundPosX, WIN_SIZE_Y / 2);

	mPlayer1->Render(hdc);
	
	mPlayer2->Render(hdc);

	mPlayer1Bar->Render(hdc);
	mPlayer2Bar->Render(hdc);
}

void AnimationScene::Exit()
{
	SAFE_RELEASE(mPlayer1);

	SAFE_RELEASE(mPlayer2);

	for (int i = 0; i < 39; i++)
	{
		SAFE_RELEASE(mpArrBackground[i]);
	}
	delete[] mpArrBackground;
}
