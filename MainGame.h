#pragma once
#include "Config.h"
#include "GameEntity.h"

/*

 킹오파에서  상대방이 서있고 히트박스가 몸만큼 있고 그옆에서 한명이 걸어가고 있고 히트박스가 머리부터 몸까지

 캐릭터끼리 부딪혔을때 움직이지 못하게 해보자.

*/

class Command;
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

	Character* mRect1;
	Character* mRect2;

	Command* mLeftMoveCom;
	Command* mRightMoveCom;
	Command* mSmallAttack;
	Command* mBigAttack;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};