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