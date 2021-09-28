#include "AnimationScene.h"
#include "BluemaryAnimation.h"
#include "ChAnimation.h"
#include "ChAnimData.h"
#include "Command.h"
#include "HealthBar.h"
#include "Image.h"
#include "LeonaAnimation.h"
#include "RalfAnimation.h"
#include "SceneManager.h"
#include "UITimer.h"

void AnimationScene::Enter()
{
	switch (Player1)
	{
	case 1:
		mpPlayer1 = new BluemaryAnimation;
		break;
	case 2:
		mpPlayer1 = new RalfAnimation;
		break;
	case 3:
		mpPlayer1 = new LeonaAnimation;
		break;
	}

	switch (Player2)
	{
	case 1:
		mpPlayer2 = new BluemaryAnimation;
		break;
	case 2:
		mpPlayer2 = new RalfAnimation;
		break;
	case 3:
		mpPlayer2 = new LeonaAnimation;
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

	mpPlayer1->Init(eLookat::Right_Lookat);
	mpPlayer2->Init(eLookat::Left_Lookat);

	POINTFLOAT pos;
	pos.x = 200;
	pos.y = 600;
	mpPlayer1->SetPos(pos);
	pos.x = 1000;
	mpPlayer2->SetPos(pos);

	mpPlayer1->SetTarget(mpPlayer2);
	mpPlayer2->SetTarget(mpPlayer1);

	mpWeakPunch1 = new Command;
	mpWeakPunch1->Init(mpPlayer1, ChAnimation::WeakPunchCommand);

	mpStrongPunch1 = new Command;
	mpStrongPunch1->Init(mpPlayer1, ChAnimation::StrongPunchCommand);

	mpWeakKick1 = new Command;
	mpWeakKick1->Init(mpPlayer1, ChAnimation::WeakKickCommand);

	mpStrongKick1 = new Command;
	mpStrongKick1->Init(mpPlayer1, ChAnimation::StrongKickCommand);

	mpNearWeakPunch1 = new Command;
	mpNearWeakPunch1->Init(mpPlayer1, ChAnimation::NearWeakPunchCommand);

	mpNearStrongPunch1 = new Command;
	mpNearStrongPunch1->Init(mpPlayer1, ChAnimation::NearStrongPunchCommand);

	mpNearWeakKick1 = new Command;
	mpNearWeakKick1->Init(mpPlayer1, ChAnimation::NearWeakKickCommand);

	mpNearStrongKick1 = new Command;
	mpNearStrongKick1->Init(mpPlayer1, ChAnimation::NearStrongKickCommand);

	mpMoveLeft1 = new Command;
	mpMoveLeft1->Init(mpPlayer1, ChAnimation::MoveLeftCommand);

	mpMoveRight1 = new Command;
	mpMoveRight1->Init(mpPlayer1, ChAnimation::MoveRightCommand);



	mpWeakPunch2 = new Command;
	mpWeakPunch2->Init(mpPlayer2, ChAnimation::WeakPunchCommand);

	mpStrongPunch2 = new Command;
	mpStrongPunch2->Init(mpPlayer2, ChAnimation::StrongPunchCommand);

	mpWeakKick2 = new Command;
	mpWeakKick2->Init(mpPlayer2, ChAnimation::WeakKickCommand);

	mpStrongKick2 = new Command;
	mpStrongKick2->Init(mpPlayer2, ChAnimation::StrongKickCommand);

	mpNearWeakPunch2 = new Command;
	mpNearWeakPunch2->Init(mpPlayer2, ChAnimation::NearWeakPunchCommand);

	mpNearStrongPunch2 = new Command;
	mpNearStrongPunch2->Init(mpPlayer2, ChAnimation::NearStrongPunchCommand);

	mpNearWeakKick2 = new Command;
	mpNearWeakKick2->Init(mpPlayer2, ChAnimation::NearWeakKickCommand);

	mpNearStrongKick2 = new Command;
	mpNearStrongKick2->Init(mpPlayer2, ChAnimation::NearStrongKickCommand);

	mpMoveLeft2 = new Command;
	mpMoveLeft2->Init(mpPlayer2, ChAnimation::MoveLeftCommand);

	mpMoveRight2 = new Command;
	mpMoveRight2->Init(mpPlayer2, ChAnimation::MoveRightCommand);

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

	mpPlayer1Bar = new HealthBar();
	mpPlayer1Bar->Init();
	mpPlayer1Bar->SetHealthBarDir(eHealthBarDir::Left);
	mpPlayer2Bar = new HealthBar();
	mpPlayer2Bar->Init();
	mpPlayer2Bar->SetHealthBarDir(eHealthBarDir::Right);

	POINTFLOAT player1BarPos;
	player1BarPos.x = 300;
	player1BarPos.y = 100;
	mpPlayer1Bar->SetPosition(player1BarPos);

	POINTFLOAT player2BarPos;
	player2BarPos.x = 900;
	player2BarPos.y = 100;
	mpPlayer2Bar->SetPosition(player2BarPos);

	mpTimer = new UITimer;
	mpTimer->Init();
	mpTimer->SetTime(60);

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

	if (mpPlayer1->GetIsHit())
	{
		mbPrintEffect1 = true;
		Player1HitPos.x = mpPlayer1->GetPos().x + ((rand() % 61) - 30);
		Player1HitPos.y = mpPlayer1->GetPos().y + ((rand() % 61) - 110);
	}
	if (mpPlayer2->GetIsHit())
	{
		mbPrintEffect2 = true;
		Player2HitPos.x = mpPlayer2->GetPos().x + ((rand() % 61) - 30);
		Player2HitPos.y = mpPlayer2->GetPos().y + ((rand() % 61) - 110);
	}

	if (mbPrintEffect1 || mbPrintEffect2)
	{
		mCurEffectElapseTime++;
		if (mCurEffectElapseTime > 4)
		{
			mCurEffectElapseTime = 0;
			mCurEffectFrame++;
			if (mCurEffectFrame >= MaxEffectFrame - 1)
			{
				mCurEffectFrame = 0;
				mbPrintEffect1 = false;
				mbPrintEffect2 = false;
			}
		}
	}

	if (mBackgroundPosX < 600 && MGR_KEY->IsStayKeyDown('A') && MGR_KEY->IsStayKeyDown(VK_LEFT))
	{
		mBackgroundPosX += 6;
		mpPlayer1->SetNotMove(true);
		mpPlayer2->SetNotMove(true);
	}
	else if (mBackgroundPosX > -600 && MGR_KEY->IsStayKeyDown('D') && MGR_KEY->IsStayKeyDown(VK_RIGHT))
	{
		mBackgroundPosX -= 6;
		mpPlayer1->SetNotMove(true);
		mpPlayer2->SetNotMove(true);
	}
	else if (mBackgroundPosX < 600 && MGR_KEY->IsStayKeyDown('A') && mpPlayer1->GetShape().left == mCameraSize.left)
	{
		if (!(mpPlayer2->GetShape().right >= (mCameraSize.right)))
		{
			mpPlayer2->SetPosX(-6);
			mBackgroundPosX += 6;
		}
	}
	else if (mBackgroundPosX > -600 && MGR_KEY->IsStayKeyDown(VK_RIGHT) && mpPlayer2->GetShape().right == mCameraSize.right)
	{
		if (!(mpPlayer1->GetShape().left <= (mCameraSize.left)))
		{
			mpPlayer1->SetPosX(6);
			mBackgroundPosX -= 6;
		}
	}

	if (mpPlayer1->GetData()->mPlayerAct != eActing::Damaged && mpPlayer1->GetData()->mPlayerAct != eActing::Dead)
	{

		if (mpPlayer1->GetData()->mIsAttack == false)
		{
			if (mpPlayer1->GetData()->mPlayerLookat == eLookat::Left_Lookat)
			{
				mDistance = abs(mpPlayer1->GetShape().left) - abs(mpPlayer1->GetShape().right);
			}
			else if (mpPlayer1->GetData()->mPlayerLookat == eLookat::Right_Lookat)
			{
				mDistance = abs(mpPlayer2->GetShape().left) - abs(mpPlayer1->GetShape().right);
			}

			if (MGR_KEY->IsOnceKeyDown('G'))
			{
				if (NearMaxPixel > mDistance)
				{
					mpNearWeakPunch1->Execute();
				}
				else
				{
					mpWeakPunch1->Execute();
				}
			}
			else if (MGR_KEY->IsOnceKeyDown('Y'))
			{
				if (NearMaxPixel > mDistance)
				{
					mpNearStrongPunch1->Execute();
				}
				else
				{
					mpStrongPunch1->Execute();
				}
			}
			else if (MGR_KEY->IsOnceKeyDown('H'))
			{
				if (NearMaxPixel > mDistance)
				{
					mpNearWeakKick1->Execute();
				}
				else
				{
					mpWeakKick1->Execute();
				}
			}
			else if (MGR_KEY->IsOnceKeyDown('U'))
			{
				if (NearMaxPixel > mDistance)
				{
					mpNearStrongKick1->Execute();
				}
				else
				{
					mpStrongKick1->Execute();
				}
			}
		}

		if (mpPlayer1->GetData()->mPlayerAct != eActing::Act_Attack)
		{
			if (MGR_KEY->IsStayKeyDown('A'))
			{
				mpMoveLeft1->Execute();
			}
			else if (MGR_KEY->IsStayKeyDown('D'))
			{
				mpMoveRight1->Execute();
			}
			else
			{
				if (mpPlayer1->GetData()->mPlayerAct != eActing::Act_Idle)
				{
					mpPlayer1->SetFrameX(0);
				}
				mpPlayer1->GetData()->mPlayerAct = eActing::Act_Idle;
				mpPlayer1->GetData()->mPlayerStatus = eAnimStatus::Idle;
			}
		}
	}

	if (mpPlayer2->GetData()->mPlayerAct != eActing::Damaged && mpPlayer2->GetData()->mPlayerAct != eActing::Dead)
	{
		if (mpPlayer2->GetData()->mIsAttack == false)
		{
			if (mpPlayer2->GetData()->mPlayerLookat == eLookat::Left_Lookat)
			{
				mDistance = abs(mpPlayer2->GetShape().left) - abs(mpPlayer1->GetShape().right);
			}
			else if (mpPlayer2->GetData()->mPlayerLookat == eLookat::Right_Lookat)
			{
				mDistance = abs(mpPlayer2->GetShape().right) - abs(mpPlayer1->GetShape().left);
			}

			if (MGR_KEY->IsOnceKeyDown('N'))
			{
				if (NearMaxPixel > mDistance) { mpNearWeakPunch2->Execute(); }
				else { mpWeakPunch2->Execute(); }
			}
			else if (MGR_KEY->IsOnceKeyDown('J'))
			{
				if (NearMaxPixel > mDistance) { mpNearStrongPunch2->Execute(); }
				else { mpStrongPunch2->Execute(); }
			}
			else if (MGR_KEY->IsOnceKeyDown('M'))
			{
				if (NearMaxPixel > mDistance) { mpNearWeakKick2->Execute(); }
				else { mpWeakKick2->Execute(); }
			}
			else if (MGR_KEY->IsOnceKeyDown('K'))
			{
				if (NearMaxPixel > mDistance) { mpNearStrongKick2->Execute(); }
				else { mpStrongKick2->Execute(); }
			}
		}

		if (mpPlayer2->GetData()->mPlayerAct != eActing::Act_Attack)
		{
			if (MGR_KEY->IsStayKeyDown(VK_LEFT))
			{
				mpMoveLeft2->Execute();
			}
			else if (MGR_KEY->IsStayKeyDown(VK_RIGHT))
			{
				mpMoveRight2->Execute();
			}
			else
			{
				if (mpPlayer2->GetData()->mPlayerAct != eActing::Act_Idle)
				{
					mpPlayer2->SetFrameX(0);
				}
				mpPlayer2->GetData()->mPlayerAct = eActing::Act_Idle;
				mpPlayer2->GetData()->mPlayerStatus = eAnimStatus::Idle;
			}
		}
	}

	mpPlayer1Bar->SetValue(mpPlayer1->GetHPWeight());
	mpPlayer2Bar->SetValue(mpPlayer2->GetHPWeight());

	mpTimer->Update();

	mpPlayer1->Update();

	mpPlayer2->Update();

	if (mpPlayer1->GetHP() <= 0 || mpPlayer2->GetHP() <= 0)
	{
		SetTimer(g_hWnd, 0, 200, NULL);
		if (bf.SourceConstantAlpha >= 250)
		{
			bf.SourceConstantAlpha = 255;

			Sleep(2000);
			MGR_SCN->ChangeScene(eSceneTag::OpeningScene);
			SetTimer(g_hWnd, 0, 10, NULL);

			return;
		}
		else
		{
			bf.SourceConstantAlpha += 10;
		}
	}

	if (MGR_KEY->IsOnceKeyDown('1'))
	{
		if (mpPlayer1->GetPrintHitBox() == false)
		{
			mpPlayer1->SetPrintHitBox(true);
			mpPlayer2->SetPrintHitBox(true);
		}
		else
		{
			mpPlayer1->SetPrintHitBox(false);
			mpPlayer2->SetPrintHitBox(false);
		}
	}

}

void AnimationScene::Render(HDC hdc)
{
	mpArrBackground[mCurBackgroundFrame]->Render(hdc, WIN_SIZE_X / 2 + mBackgroundPosX, WIN_SIZE_Y / 2);

	mpPlayer1->Render(hdc);

	mpPlayer2->Render(hdc);

	mpPlayer1Bar->Render(hdc);
	mpPlayer2Bar->Render(hdc);

	mpTimer->Render(hdc);

	if (mbPrintEffect1) { mpArrEffect[mCurEffectFrame]->Render(hdc, (int)Player1HitPos.x, (int)Player1HitPos.y); }
	if (mbPrintEffect2) { mpArrEffect[mCurEffectFrame]->Render(hdc, (int)Player2HitPos.x, (int)Player2HitPos.y); }

	mpEndImage->Render(hdc, bf);
}

void AnimationScene::Exit()
{
	SAFE_RELEASE(mpPlayer1);
	SAFE_RELEASE(mpPlayer2);

	SAFE_RELEASE(mpPlayer1Bar);
	SAFE_RELEASE(mpPlayer2Bar);

	SAFE_RELEASE(mpTimer);

	for (int i = 0; i < 39; i++)
	{
		SAFE_RELEASE(mpArrBackground[i]);
	}
	delete[] mpArrBackground;
}
