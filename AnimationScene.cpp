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

	mNearWeakPunch1 = new Command;
	mNearWeakPunch1->Init(mPlayer1, ChAnimation::NearWeakPunchCommand);
	 
	mNearStrongPunch1 = new Command;
	mNearStrongPunch1->Init(mPlayer1, ChAnimation::NearStrongPunchCommand);
	 
	mNearWeakKick1 = new Command;
	mNearWeakKick1->Init(mPlayer1, ChAnimation::NearWeakKickCommand);
	 
	mNearStrongKick1 = new Command;
	mNearStrongKick1->Init(mPlayer1, ChAnimation::NearStrongKickCommand);

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

	mNearWeakPunch2 = new Command;
	mNearWeakPunch2->Init(mPlayer2, ChAnimation::NearWeakPunchCommand);

	mNearStrongPunch2 = new Command;
	mNearStrongPunch2->Init(mPlayer2, ChAnimation::NearStrongPunchCommand);

	mNearWeakKick2 = new Command;
	mNearWeakKick2->Init(mPlayer2, ChAnimation::NearWeakKickCommand);

	mNearStrongKick2 = new Command;
	mNearStrongKick2->Init(mPlayer2, ChAnimation::NearStrongKickCommand);

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
		if (mPlayer1->GetData()->mPlayerLookat == eLookat::Left_Lookat)
		{
			mDistance = abs(mPlayer2->GetShape().right) - abs(mPlayer1->GetShape().left);
		}
		else if (mPlayer1->GetData()->mPlayerLookat == eLookat::Right_Lookat)
		{
			mDistance = abs(mPlayer1->GetShape().left) - abs(mPlayer2->GetShape().right);
		}
		
		if (KeyManager::GetSingleton()->IsOnceKeyDown('G'))
		{
			if (abs(mPlayer1->GetData()->mHitboxShapeRight[eAnimStatus::Near_Weak_Punch]) > mDistance)
			{
				mNearWeakPunch1->Execute();
			}
			else
			{
				mWeakPunch1->Execute();
			}			
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('Y'))
		{
			if (abs(mPlayer1->GetData()->mHitboxShapeRight[eAnimStatus::Near_Strong_Punch]) > mDistance)
			{
				mNearStrongPunch1->Execute();
			}
			else
			{
				mStrongPunch1->Execute();
			}
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('H'))
		{
			if (abs(mPlayer1->GetData()->mHitboxShapeRight[eAnimStatus::Near_Weak_Kick]) > mDistance)
			{
				mNearWeakKick1->Execute();
			}
			else
			{
				mWeakKick1->Execute();
			}
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('U'))
		{
			if (abs(mPlayer1->GetData()->mHitboxShapeRight[eAnimStatus::Near_Strong_Kick]) > mDistance)
			{
				mNearStrongKick1->Execute();
			}
			else
			{
				mStrongKick1->Execute();
			}
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
		if (mPlayer2->GetData()->mPlayerLookat == eLookat::Left_Lookat)
		{
			mDistance = abs(mPlayer1->GetShape().right) - abs(mPlayer2->GetShape().left);
		}
		else if (mPlayer2->GetData()->mPlayerLookat == eLookat::Right_Lookat)
		{
			mDistance = abs(mPlayer2->GetShape().left) - abs(mPlayer1->GetShape().right);
		}

		if (KeyManager::GetSingleton()->IsOnceKeyDown('N'))
		{
			if (abs(mPlayer2->GetData()->mHitboxShapeRight[eAnimStatus::Near_Weak_Punch]) > mDistance) {mNearWeakPunch2->Execute();}
			else {mWeakPunch2->Execute();}
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('J'))
		{
			if (abs(mPlayer2->GetData()->mHitboxShapeRight[eAnimStatus::Near_Strong_Punch]) > mDistance) {mNearStrongPunch2->Execute();}
			else {mStrongPunch2->Execute();}
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('M'))
		{
			if (abs(mPlayer2->GetData()->mHitboxShapeRight[eAnimStatus::Near_Weak_Kick]) > mDistance) {mNearWeakKick2->Execute();}
			else{mWeakKick2->Execute();}
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('K'))
		{
			if (abs(mPlayer2->GetData()->mHitboxShapeRight[eAnimStatus::Near_Strong_Kick]) > mDistance) {mNearStrongKick2->Execute();}
			else {mStrongKick2->Execute();}
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

	cout << "Player1LookAt : " << (int)mPlayer1->GetLookAt() << endl;
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
