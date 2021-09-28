#include "EndingScene.h"
#include "Image.h"
#include "SceneManager.h"

void EndingScene::Enter()
{
	mWinnerImage = new Image;

	mEndingBackground = new Image;
	mEndingBackground->Init("Image/UI/Ending_Background.bmp", WIN_SIZE_X, WIN_SIZE_Y);

	const int MugSizeX = 1389;
	const int MugSizeY = 1042;

	if (g_bWinner)
	{
		switch (g_Player1)
		{
		case 1:
			mWinnerImage->Init("Image/UI/MaryWinImage.bmp", MugSizeX, MugSizeY, true, RGB(255, 0, 255));
			break;
		case 2:
			mWinnerImage->Init("Image/UI/RalfWinImage.bmp", MugSizeX, MugSizeY, true, RGB(255, 0, 255));
			break;
		case 3:
			mWinnerImage->Init("Image/UI/LeonaWinImage.bmp", MugSizeX, MugSizeY, true, RGB(255, 0, 255));
			break;
		default:
			cout << "여기 들어오면 안돼!!!!!!!!!!!" << endl;
			break;
		}
	}
	else
	{
		switch (g_Player2)
		{
		case 1:
			mWinnerImage->Init("Image/UI/MaryWinImage.bmp", MugSizeX, MugSizeY, true, RGB(255, 0, 255));
			break;
		case 2:
			mWinnerImage->Init("Image/UI/RalfWinImage.bmp", MugSizeX, MugSizeY, true, RGB(255, 0, 255));
			break;
		case 3:
			mWinnerImage->Init("Image/UI/LeonaWinImage.bmp", MugSizeX, MugSizeY, true, RGB(255, 0, 255));
			break;
		default:
			cout << "여기 들어오면 안돼!!!!!!!!!!!" << endl;
			break;
		}
	}

}

void EndingScene::Update()
{
	Sleep(7000);

	MGR_SCN->ChangeScene(eSceneTag::OpeningScene);
}

void EndingScene::Render(HDC hdc)
{

	mEndingBackground->Render(hdc);
	mWinnerImage->Render(hdc, (WIN_SIZE_X / 2) + 90, (WIN_SIZE_Y / 2));
}

void EndingScene::Exit()
{
	mEndingBackground->Release();
	mWinnerImage->Release();
}
