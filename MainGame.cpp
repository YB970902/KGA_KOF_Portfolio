#include "MainGame.h"
#include "Singleton.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "Image.h"
#include "AnimManager.h"

//int MainGame::clickedMousePosX = 0;

/*
	�ǽ�1. 
	1) ȭ�� ��ܿ� �̿����� 8������ 3�ٷ� ���´�.
	2) Ȧ�� ���� �������� �̵��ϰ� ¦�� ���� ���������� �̵��Ѵ�.
	3) ȭ�� �¿����� ������ �ݴ�� �̵��Ѵ�.
	4) �÷��̾�� �̻����� �߻��ؼ� �̿����� �����.
	5) �̻��Ͽ� ���� �̿����� ���ڸ��� ���߰� �� ������ �Ͼ ���·� 2�� �Ŀ� �������.
	6) ��� �̿����� ���ָ� ���� Ŭ����
*/

void MainGame::Init()
{
	//Singleton<int> singleton1;
	//singleton1.ProcessInputKey();
	//Singleton<KeyManager>::GetSingleton()->Init();

	//KeyManager keyMgr;
	KeyManager::GetSingleton()->Init();
	SceneManager::GetSingleton();


	// Ÿ�̸� ����
	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);

	mousePosX = 0;
	mousePosY = 0;
	//clickedMousePosX = 0; 
	clickedMousePosY = 0; 

	playerTank.Init(TankType::Player);
	enemyTank.Init(TankType::Enemy);

	//playerTank.ammoPack[0].SetTarget(&enemyTank);
	//playerTank.ammo[1].SetTarget(&enemyTank);
	//playerTank.ammo[2].SetTarget(&enemyTank);

	// �����
	backBuffer = new Image;
	backBuffer->Init(WIN_SIZE_X, WIN_SIZE_Y);

	// ��� �̹���
	backGround = new Image;
	if (!SUCCEEDED(backGround->Init("Image/mapImage.bmp", 1400, 933)))
	{
		cout << "Image/bin.bmp ���� �ε忡 �����ߴ�." << endl;
	}

	// �̿���
	Player1_anim = new AnimManager;
	Player1_anim->Init();

}

void MainGame::Update()
{
	playerTank.Update();
	enemyTank.Update();

	if (Player1_anim)
	{
		Player1_anim->Update();
	}

	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = backBuffer->GetMemDC();

	wsprintf(text, "MousePosX : %d", mousePosX);
	TextOut(hBackBufferDC, 200, 10, text, strlen(text));

	wsprintf(text, "MousePosY : %d", mousePosY);
	TextOut(hBackBufferDC, 200, 40, text, strlen(text));

	backGround->Render(hBackBufferDC);

	playerTank.Render(hBackBufferDC);
	enemyTank.Render(hBackBufferDC);

	Player1_anim->Render(hBackBufferDC);

	backBuffer->Render(hdc);
}

void MainGame::Release()
{
	SAFE_RELEASE(backBuffer);
	//if (backBuffer)
	//{
	//	backBuffer->Release();
	//	delete backBuffer;
	//	backBuffer = nullptr;
	//}

	SAFE_RELEASE(backGround);
	SAFE_RELEASE(Player1_anim);

	playerTank.Release();
	enemyTank.Release();

	// Ÿ�̸� ��ü ����
	KillTimer(g_hWnd, 0);
}


LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE:
			//playerTank.Fire();
			break;
		case VK_UP:
			//playerTank.Move(MoveDir::Up);
			break;
		case VK_DOWN:
			//playerTank.Move(MoveDir::Down);
			break;
		case VK_LEFT:
			//playerTank.Move(MoveDir::Left);
			playerTank.RotateBarrelAngle(1.0f);
			break;
		case VK_RIGHT:
			//playerTank.Move(MoveDir::Right);
			playerTank.RotateBarrelAngle(-1.0f);
			break;
		}
		break;

	case WM_LBUTTONDOWN:
		clickedMousePosX = LOWORD(lParam);
		clickedMousePosY = HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_MOUSEMOVE:
		mousePosX = LOWORD(lParam);
		mousePosY = HIWORD(lParam);
		break;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
