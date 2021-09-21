#pragma once
#include "Config.h"
#include "GameEntity.h"

/*

 ŷ���Ŀ���  ������ ���ְ� ��Ʈ�ڽ��� ����ŭ �ְ� �׿����� �Ѹ��� �ɾ�� �ְ� ��Ʈ�ڽ��� �Ӹ����� ������

 ĳ���ͳ��� �ε������� �������� ���ϰ� �غ���.

*/

class Command;
class Image;
class Character;
class MainGame : public GameEntity
{
private:
	HANDLE hTimer = nullptr;

	char text[128] = {} ;

	int mousePosX = 0;
	int mousePosY = 0;
	int clickedMousePosX = 0;
	int clickedMousePosY = 0;

	Image* backBuffer = nullptr;
	Image* backGround = nullptr;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};