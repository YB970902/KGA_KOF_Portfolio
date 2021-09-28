#include "CharacterSelectScene.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "Image.h"

CharacterSelectScene::CharacterSelectScene()
{
	mpBackground = new Image();
	mpBackground->Init("Image/UI/Select_Background.bmp", WIN_SIZE_X, WIN_SIZE_Y);

	mp1PMugshotBackground = new Image();
	mp2PMugshotBackground = new Image();
	mp1PMugshotBackground->Init("Image/UI/Select_MugshotBackground.bmp", 500, 350, true, RGB(255, 0, 255));
	mp2PMugshotBackground->Init("Image/UI/Select_MugshotBackground.bmp", 500, 350, true, RGB(255, 0, 255));

	mpLeonaMugshot = new Image();
	mpMaryMugshot = new Image();
	mpRalfMugshot = new Image();
	mpLeonaMugshot->Init("Image/UI/LeonaMugshot.bmp", 490, 340, true, RGB(255, 0, 255));
	mpMaryMugshot->Init("Image/UI/MaryMugshot.bmp", 490, 340, true, RGB(255, 0, 255));
	mpRalfMugshot->Init("Image/UI/RalfMugshot.bmp", 490, 340, true, RGB(255, 0, 255));

	mpRightSection = new Image();
	mpRightSection->Init("Image/UI/Select_RightSection.bmp", 600, 800);

	mp1PEdge = new Image();
	mp2PEdge = new Image();
	mp1PEdge->Init("Image/UI/Select_1P.bmp", 100, 114, true, RGB(255, 0, 255));
	mp2PEdge->Init("Image/UI/Select_2P.bmp", 100, 114, true, RGB(255, 0, 255));
}

CharacterSelectScene::~CharacterSelectScene()
{
	SAFE_RELEASE(mpBackground);

	SAFE_RELEASE(mp1PMugshotBackground);
	SAFE_RELEASE(mp2PMugshotBackground);

	SAFE_RELEASE(mpLeonaMugshot);
	SAFE_RELEASE(mpMaryMugshot);
	SAFE_RELEASE(mpRalfMugshot);

	SAFE_RELEASE(mpRightSection);

	SAFE_RELEASE(mp1PEdge);
	SAFE_RELEASE(mp2PEdge);
}

void CharacterSelectScene::Enter()
{
	g_Player1 = (int)eCharacterType::Null;
	g_Player2 = (int)eCharacterType::Null;
}

void CharacterSelectScene::Update()
{
	if (MGR_KEY->IsOnceKeyDown('1'))
	{
		g_Player1 = (int)eCharacterType::Bluemary;
		cout << "블루마리" << endl;
	}
	else if (MGR_KEY->IsOnceKeyDown('2'))
	{
		g_Player1 = (int)eCharacterType::Ralf;
		cout << "랄프" << endl;
	}
	else if (MGR_KEY->IsOnceKeyDown('3'))
	{
		g_Player1 = (int)eCharacterType::Leona;
		cout << "레오나" << endl;
	}

	if (MGR_KEY->IsOnceKeyDown('4'))
	{
		g_Player2 = (int)eCharacterType::Bluemary;
		cout << "블루마리" << endl;
	}
	else if (MGR_KEY->IsOnceKeyDown('5'))
	{
		g_Player2 = (int)eCharacterType::Ralf;
		cout << "랄프" << endl;
	}
	else if (MGR_KEY->IsOnceKeyDown('6'))
	{
		g_Player2 = (int)eCharacterType::Leona;
		cout << "레오나" << endl;
	}

	if (MGR_KEY->IsOnceKeyDown('P'))
	{
		MGR_SCN->ChangeScene(eSceneTag::AnimationScene);
	}

	if (MGR_KEY->IsOnceKeyDown(VK_LEFT))
	{
		mCurIndex++;
		if (mCurIndex > 3) { mCurIndex = 1; }
	}
	else if (MGR_KEY->IsOnceKeyDown(VK_RIGHT))
	{
		mCurIndex--;
		if (mCurIndex < 1) { mCurIndex = 3; }
	}

	if (!mbIsPlayer1Selected)
	{
		g_Player1 = mCurIndex;
	}
	else if (!mbIsPlayer2Selected)
	{
		g_Player2 = mCurIndex;
	}

	if (MGR_KEY->IsOnceKeyDown(VK_SPACE))
	{
		if (!mbIsPlayer1Selected)
		{
			mbIsPlayer1Selected = true;
			mCurIndex = 1;
		}
		else if (!mbIsPlayer2Selected) 
		{
			mbIsPlayer2Selected = true;
			mCurIndex = 1;
		}
		else { MGR_SCN->ChangeScene(eSceneTag::AnimationScene); }
	}
}

void CharacterSelectScene::Render(HDC hdc)
{
	mpBackground->Render(hdc);

	mp1PMugshotBackground->Render(hdc, 270, WIN_SIZE_Y - 650);
	mp2PMugshotBackground->Render(hdc, 270, WIN_SIZE_Y - 200);

	switch (g_Player1)
	{
	case (int)eCharacterType::Bluemary:
		mpMaryMugshot->Render(hdc, 270, WIN_SIZE_Y - 650);
		break;
	case (int)eCharacterType::Ralf:
		mpRalfMugshot->Render(hdc, 270, WIN_SIZE_Y - 650);
		break;
	case (int)eCharacterType::Leona:
		mpLeonaMugshot->Render(hdc, 270, WIN_SIZE_Y - 650);
		break;
	default:
		break;
	}

	switch (g_Player2)
	{
	case (int)eCharacterType::Bluemary:
		mpMaryMugshot->Render(hdc, 270, WIN_SIZE_Y - 200);
		break;
	case (int)eCharacterType::Ralf:
		mpRalfMugshot->Render(hdc, 270, WIN_SIZE_Y - 200);
		break;
	case (int)eCharacterType::Leona:
		mpLeonaMugshot->Render(hdc, 270, WIN_SIZE_Y - 200);
		break;
	default:
		break;
	}

	mpRightSection->Render(hdc, WIN_SIZE_X - 325, 475);

	if (!mbIsPlayer1Selected)
	{
		switch (mCurIndex)
		{
		case (int)eCharacterType::Bluemary:
			mp1PEdge->Render(hdc, 1025, 598);
			break;
		case (int)eCharacterType::Ralf:
			mp1PEdge->Render(hdc, 727, 710);
			break;
		case (int)eCharacterType::Leona:
			mp1PEdge->Render(hdc, 630, 710);
			break;
		default:
			break;
		}
	}
	else if (!mbIsPlayer2Selected)
	{
		switch (mCurIndex)
		{
		case (int)eCharacterType::Bluemary:
			mp2PEdge->Render(hdc, 1025, 598);
			break;
		case (int)eCharacterType::Ralf:
			mp2PEdge->Render(hdc, 727, 710);
			break;
		case (int)eCharacterType::Leona:
			mp2PEdge->Render(hdc, 630, 710);
			break;
		default:
			break;
		}
	}
}

void CharacterSelectScene::Exit()
{
	mbIsPlayer1Selected = false;
	mbIsPlayer2Selected = false;
}
