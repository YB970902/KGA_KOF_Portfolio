#include "UITimer.h"
#include "Image.h"
#include "SceneManager.h"
#include "Config.h"

void UITimer::Init()
{
	char text[128];
	for (int i = 0; i < 10; i++)
	{
		mImgMap[i] = new Image();
		wsprintf(text, "Image/UI/%d.bmp", i);
		mImgMap[i]->Init(text, TimeImageWidth, TimeImageHeight);
	}
}

void UITimer::Release()
{
	for (int i = 0; i < 10; i++)
	{
		mImgMap[i]->Release();
		mImgMap[i] = nullptr;
	}
}

void UITimer::Update()
{
	mElapseTime++;
	if (mElapseTime > 100)
	{
		mElapseTime = 0;
		mCurTime--;
		if (mCurTime < 0)
		{
			MGR_SCN->ChangeScene(eSceneTag::OpeningScene);
		}
	}
}

void UITimer::Render(HDC hdc)
{
	if (mCurTime < 0)
	{
		mImgMap[0]->Render(hdc, WIN_SIZE_X / 2 - TimeImageWidthHalf, TimeImageHeight);
		mImgMap[0]->Render(hdc, WIN_SIZE_X / 2 + TimeImageWidthHalf, TimeImageHeight);
	}
	else
	{
		mImgMap[mCurTime / 10]->Render(hdc, WIN_SIZE_X / 2 - TimeImageWidthHalf, TimeImageHeight);
		mImgMap[mCurTime % 10]->Render(hdc, WIN_SIZE_X / 2 + TimeImageWidthHalf, TimeImageHeight);
	}
}
