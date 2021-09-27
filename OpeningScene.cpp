#include "Image.h"
#include "KeyManager.h"
#include "OpeningScene.h"
#include "SceneManager.h"

OpeningScene::OpeningScene()
{
	mArrIntroAnim = new Image*[129];
	for (int i = 0; i < 129; i++)
	{
		mArrIntroAnim[i] = new Image();
	}
	mpDefaultBackground = new Image();
}

OpeningScene::~OpeningScene()
{
	for (int i = 0; i < 129; i++)
	{
		SAFE_RELEASE(mArrIntroAnim[i]);
	}

	delete[] mArrIntroAnim;

	SAFE_RELEASE(mpDefaultBackground);
}

void OpeningScene::Enter()
{
	char text[128];

	for (int i = 0; i < 129; i++)
	{
		wsprintf(text, "Image/Opening/IntroAnim%d.bmp", i);
		mArrIntroAnim[i]->Init(text, WIN_SIZE_X, WIN_SIZE_Y);
	}

	mpDefaultBackground->Init("Image/Opening/Main_Background.bmp", WIN_SIZE_X, WIN_SIZE_Y);
}

void OpeningScene::Update()
{
	if (mbIsOpening)
	{
		mCurElapseTime++;
		if (mCurElapseTime > 3)
		{
			mCurElapseTime = 0;
			mCurIntroAnimFrame++;
			if (mCurIntroAnimFrame >= 129) { mbIsOpening = false; }
		}
	}

	if (MGR_KEY->IsOnceKeyDown(VK_SPACE))
	{
		MGR_SCN->ChangeScene(eSceneTag::CharacterSelectScene);
	}
}

void OpeningScene::Render(HDC hdc)
{
	if (mbIsOpening) { mArrIntroAnim[mCurIntroAnimFrame]->Render(hdc); }
	else { mpDefaultBackground->Render(hdc); }
}

void OpeningScene::Exit()
{
	for (int i = 0; i < 129; i++)
	{
		mArrIntroAnim[i]->Release();
	}

	mpDefaultBackground->Release();
}
