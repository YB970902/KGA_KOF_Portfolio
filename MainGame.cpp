#include "MainGame.h"
#include "Singleton.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "Image.h"
#include "Character.h"
#include "Command.h"

void MainGame::Init()
{
	MGR_KEY->Init();
	MGR_SCN->Init();

	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 100 , NULL);

	mousePosX = 0;
	mousePosY = 0;
	clickedMousePosX = 0;
	clickedMousePosY = 0;

	backBuffer = new Image;
	backBuffer->Init(WIN_SIZE_X, WIN_SIZE_Y);

	backGround = new Image;
	backGround->Init("Image/mapImage.bmp", WIN_SIZE_X, WIN_SIZE_Y);
}

void MainGame::Update()
{
	InvalidateRect(g_hWnd, NULL, false);

	MGR_SCN->Update();

	if (MGR_KEY->IsOnceKeyDown('C'))
	{
	MGR_SCN->ChangeScene(eSceneTag::HitBoxSnene);
	}

}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = backBuffer->GetMemDC();

	backGround->Render(hBackBufferDC);

	MGR_SCN->Render(hBackBufferDC);

	backBuffer->Render(hdc);
}

void MainGame::Release()
{
	SAFE_RELEASE(backBuffer);
	SAFE_RELEASE(backGround);

	KillTimer(g_hWnd, 0);

	MGR_KEY->ReleaseSingleton();
}


LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
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