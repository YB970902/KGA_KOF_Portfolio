#include "AnimationScene.h"
#include "ChAnimation.h"
#include "BluemaryAnimation.h"
#include "RalfAnimation.h"
#include "LeonaAnimation.h"
#include "ChAnimData.h"

void AnimationScene::Enter()
{

	cout << Player1 << endl;
	cout << Player2 << endl;

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
	
	mPlayer1->Init(Lookat::Right_Lookat);
	mPlayer2->Init(Lookat::Left_Lookat);

	POINTFLOAT pos;
	pos.x = 200;
	pos.y = 450;
	mPlayer1->SetPos(pos);

	pos.x = 1000;
	mPlayer2->SetPos(pos);

}

void AnimationScene::Update()
{
	//업데이트하셨던것들    
	if (mPlayer1)
	{
		mPlayer1->Update();
	}

	if (mPlayer2)
	{
		mPlayer2->Update();
	}
}

void AnimationScene::Render(HDC hdc)
{
	if (mPlayer1)
	{
		mPlayer1->Render(hdc);
	}

	if (mPlayer2)
	{
		mPlayer2->Render(hdc);
	}
}

void AnimationScene::Exit()
{
	SAFE_RELEASE(mPlayer1);
	SAFE_RELEASE(mPlayer1);

	//릴리즈해주셨던것들
}
