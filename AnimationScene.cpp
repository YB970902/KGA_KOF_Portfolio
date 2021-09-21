#include "AnimationScene.h"
#include "AnimManager.h"

void AnimationScene::Enter()
{
	Ralf = new AnimManager;
	Ralf->Init();
	//MainGame.cpp ���� �ʱ�ȭ�ϼ̴��͵�
}

void AnimationScene::Update()
{
	//������Ʈ�ϼ̴��͵�    
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
	//���������̴ּ��͵�
}
