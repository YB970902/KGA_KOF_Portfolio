#include "Character.h"
#include "Command.h"

/*
* 캐릭터를 두개를 만들어서
* 하나는 왼쪽에있고 하나는 오른쪽에있다.
* 제어권은 왼쪽에 있는 캐릭터가 가지고있다.
* 스페이스바를 누르면 다른캐릭터로 제어권이 넘어간다.
*/

void Character::Init()
{
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	bodySize = 25;
	
	shape.left = (LONG)pos.x - bodySize;
	shape.top = (LONG)pos.y - bodySize;
	shape.right = (LONG)pos.x + bodySize;
	shape.bottom = (LONG)pos.y + bodySize;

	moveSpeed = 10.0f;
	
	mLeftMove = new Command(this);
	mLeftMove->Init(Character::LeftMove);
	mRightMove = new Command(this);
	mRightMove->Init(Character::RightMove);

}

void Character::Update()
{
	shape.left = (LONG)pos.x - bodySize;
	shape.top = (LONG)pos.y - bodySize;
	shape.right = (LONG)pos.x + bodySize;
	shape.bottom = (LONG)pos.y + bodySize;

	ProcessInputKey();
}

void Character::Render(HDC hdc)
{
	Rectangle(hdc, shape.left, shape.top, shape.right, shape.bottom);
}

void Character::Release()
{
}

void Character::ProcessInputKey()
{
	if (MGR_KEY->IsStayKeyDown('A'))
	{
		mLeftMove->Execute();
	}
	if (MGR_KEY->IsStayKeyDown('D'))
	{
		mRightMove->Execute();
	}
}