#include "AnimationScene.h"
#include "AnimManager.h"

void AnimationScene::Enter()
{
	Ralf = new AnimManager;
	Ralf->Init();
	//MainGame.cpp 에서 초기화하셨던것들
}

void AnimationScene::Update()
{
	//업데이트하셨던것들    
	if (Ralf)
	{
		Ralf->Update();
	}
}

void AnimationScene::Render(HDC hdc)
{
	Ralf->Render(hdc);
}

void AnimationScene::Exit()
{
	SAFE_RELEASE(Ralf);
	//릴리즈해주셨던것들
}
