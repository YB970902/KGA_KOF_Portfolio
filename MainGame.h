#pragma once
#include "Config.h"
#include "GameEntity.h"

class Image;
class Character;
class MainGame : public GameEntity
{
private:
	HANDLE hTimer;

	char text[128];

	int mousePosX;
	int mousePosY;
	int clickedMousePosX;
	int clickedMousePosY;

	Image* backBuffer;
	Image* backGround;

	Character* Rect1;
	Character* Rect2;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};