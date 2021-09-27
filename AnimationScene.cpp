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

	mCameraSize.left = 0;
	mCameraSize.top = 0;
	mCameraSize.right = WIN_SIZE_X;
	mCameraSize.bottom = WIN_SIZE_Y;

	mBackgroundSize.left = -WIN_SIZE_X;
	mBackgroundSize.top = 0;
	mBackgroundSize.right = WIN_SIZE_X;
	mBackgroundSize.bottom = WIN_SIZE_Y;

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

	mpArrEffect = new Image * [8];
	for (int i = 0; i < 8; i++)
	{
		mpArrEffect[i] = new Image();
	}

	for (int i = 0; i < 8; i++)
	{
		wsprintf(temp, "Image/Effect/frame_%d.bmp", i);
		mpArrEffect[i]->Init(temp, 220, 213, true, RGB(255, 0, 255));
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

	mpEndImage = new Image;
	mpEndImage->Init("Image/mapImage.bmp", WIN_SIZE_X, WIN_SIZE_Y);

	bf.AlphaFormat = 0;
	bf.BlendFlags = 0;
	bf.BlendOp = AC_SRC_OVER;
	bf.SourceConstantAlpha = 0;
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

	if (mPlayer1->GetIsHit())
	{
		mPrintEffect1 = true;
		Player1HitPos.x = mPlayer1->GetPos().x + ((rand() % 61) - 30);
		Player1HitPos.y = mPlayer1->GetPos().y + ((rand() % 61) - 110);
	}
	if (mPlayer2->GetIsHit())
	{
		mPrintEffect2 = true;
		Player2HitPos.x = mPlayer2->GetPos().x + ((rand() % 61) - 30);
		Player2HitPos.y = mPlayer2->GetPos().y + ((rand() % 61) - 110);
	}

	if (mPrintEffect1 || mPrintEffect2)
	{
		mCurEffectElapseTime++;
		if (mCurEffectElapseTime > 4)
		{
			mCurEffectElapseTime = 0;
			mCurEffectFrame++;
			if (mCurEffectFrame >= MaxEffectFrame - 1)
			{
				mCurEffectFrame = 0;
				mPrintEffect1 = false;
				mPrintEffect2 = false;
			}
		}
	}

	if (mBackgroundPosX < 600 && MGR_KEY->IsStayKeyDown('A') && MGR_KEY->IsStayKeyDown(VK_LEFT))
	{
		mBackgroundPosX += 6;
		mPlayer1->SetNotMove(true);
		mPlayer2->SetNotMove(true);
	}
	else if (mBackgroundPosX > -600 && MGR_KEY->IsStayKeyDown('D') && MGR_KEY->IsStayKeyDown(VK_RIGHT))
	{
		mBackgroundPosX -= 6;
		mPlayer1->SetNotMove(true);
		mPlayer2->SetNotMove(true);
	}
	else if (mBackgroundPosX < 600 && MGR_KEY->IsStayKeyDown('A') && mPlayer1->GetShape().left == mCameraSize.left)
	{
		if (!(mPlayer2->GetShape().right >= (mCameraSize.right)))
		{
			mPlayer2->SetPosX(-6);
			mBackgroundPosX += 6;
		}
	}
	else if (mBackgroundPosX > -600 && MGR_KEY->IsStayKeyDown(VK_RIGHT) && mPlayer2->GetShape().right == mCameraSize.right)
	{
		if (!(mPlayer1->GetShape().left <= (mCameraSize.left)))
		{
			mPlayer1->SetPosX(6);
			mBackgroundPosX -= 6;
		}
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

	mPlayer1->Update();

	mPlayer2->Update();

 	mPlayer1Bar->SetValue(mPlayer1->GetHPWeight());
	mPlayer2Bar->SetValue(mPlayer2->GetHPWeight());

	if (mPlayer1->GetHP() <= 0 || mPlayer2->GetHP() <= 0)
	{
		SetTimer(g_hWnd, 0, 100, NULL);
		if (bf.SourceConstantAlpha >= 250)
		{
			bf.SourceConstantAlpha = 255;
		}
		else
		{
			bf.SourceConstantAlpha += 10;
		}
	}
}

void AnimationScene::Render(HDC hdc)
{
	mpArrBackground[mCurBackgroundFrame]->Render(hdc, WIN_SIZE_X / 2 + mBackgroundPosX, WIN_SIZE_Y / 2);

	mPlayer1->Render(hdc);
	
	mPlayer2->Render(hdc);

	mPlayer1Bar->Render(hdc);
	mPlayer2Bar->Render(hdc);

	if (mPrintEffect1) { mpArrEffect[mCurEffectFrame]->Render(hdc, (int)Player1HitPos.x, (int)Player1HitPos.y); }
	if (mPrintEffect2) { mpArrEffect[mCurEffectFrame]->Render(hdc, (int)Player2HitPos.x, (int)Player2HitPos.y); }

	mpEndImage->Render(hdc, bf);
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

	for (int i = 0; i < 8; i++)
	{
		SAFE_RELEASE(mpArrEffect[i]);
	}
	delete[] mpArrEffect;

	SAFE_RELEASE(mpEndImage);
}
