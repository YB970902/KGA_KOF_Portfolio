#include "MainGame.h"
#include "Singleton.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "Image.h"
#include "Character.h"


void MainGame::Init()
{
	MGR_KEY->Init();

	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);

	mousePosX = 0;
	mousePosY = 0;
	clickedMousePosX = 0;
	clickedMousePosY = 0;

	Rect1 = new Character;
	Rect1->Init();
	POINTFLOAT pos;
	pos.x = 200;
	pos.y = WIN_SIZE_Y/2;
	Rect1->SetPos(pos);
	Rect1->SetIsControl(true);

	Rect2 = new Character;
	Rect2->Init();
	pos.x = 1000;
	Rect2->SetPos(pos);

	backBuffer = new Image;
	backBuffer->Init(WIN_SIZE_X, WIN_SIZE_Y);

	backGround = new Image;
	backGround->Init("Image/mapImage.bmp", WIN_SIZE_X, WIN_SIZE_Y);

}

void MainGame::Update()
{
	InvalidateRect(g_hWnd, NULL, false);
	
	Rect1->Update();
	Rect2->Update();
	cout << "Rect1 : " << Rect1->GetIsControl() << endl;
	cout << "Rect2 : " << Rect2->GetIsControl() << endl;

}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = backBuffer->GetMemDC();

	backGround->Render(hBackBufferDC);

	// 이 부분에서 렌더링 작업
	Rect1->Render(hBackBufferDC);
	Rect2->Render(hBackBufferDC);

	backBuffer->Render(hdc);
}

void MainGame::Release()
{
	delete Rect1;
	delete Rect2;

	SAFE_RELEASE(backBuffer);
	SAFE_RELEASE(backGround);


	KillTimer(g_hWnd, 0);

	MGR_KEY->ReleaseSingleton();
}


LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE:
			//Rect1->ChangeIsControl();
			//Rect2->ChangeIsControl();
		default:
			break;
		}
	case WM_LBUTTONDOWN:
		clickedMousePosX = LOWORD(lParam);
		clickedMousePosY = HIWORD(lParam);
		break;
	case WM_MOUSEMOVE:
		mousePosX = LOWORD(lParam);
		mousePosY = HIWORD(lParam);
		break;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}