#include "Character.h"


/*
	공격키를 누르면 빨간색히트박스가 켜짐

	데미지는 100으로 텍스트아웃으로 표시
	히트박스는 5프레임동안 유지
	5프레임동안 키를 입력해도 움직이지 않음

	상대방은 5프레임동안 영역안에 들어가면 데미지 10을 입음

	힌트 : 

	히트박스를 켜고 끄는 함수를 만들어야함

	turnOnHitBox ();
	turnOffHitBox();

	공격키를 두개할것.
	한개는 넓고 짧지만
	한개는 짧고 길다.

	두개의 히트박스 온오프는 따로따로 만들것

	turnOn스몰HitBox ();
	turnOff스몰HitBox();
	turnOn빅HitBox ();
	turnOff빅HitBox();
	allhitboxoff();

	캐릭터포인터가 들어가는 배열을 만들자 (벡터를 이용해보자) 

	반복문 상대의 캐릭터 주소가 있는지 여부확인 후 없으면 삽입
	삽입과 동시에 데미지 

	히트박스 가시화

	캐릭터의 방향전환까지

*/

void Character::Init()
{
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	bodySize = 25;
	mHP = 100;
	
	shape.left = (int)pos.x - bodySize;
	shape.top = (int)pos.y - bodySize;
	shape.right = (int)pos.x + bodySize;
	shape.bottom = (int)pos.y + bodySize;

	moveSpeed = 10.0f;
}

void Character::Update()
{
	mFrame++;
	cout << mFrame << endl;

	if (mFrame >= 5)
	{
		AllOffHitBox();
	}

	shape.left = (int)pos.x - bodySize;
	shape.top = (int)pos.y - bodySize;
	shape.right = (int)pos.x + bodySize;
	shape.bottom = (int)pos.y + bodySize;
}

void Character::Render(HDC hdc)
{
	Rectangle(hdc, shape.left, shape.top, shape.right, shape.bottom);

	if (mTarget && IsCollided(mSmallHitBox, mTarget->shape))
	{	
		TextOut(hdc,(int) mTarget->pos.x, (int)mTarget->pos.y + 100 , "작은 공격 히트!!!!!!!!!!!!", strlen("작은 공격 히트!!!!!!!!!!!!"));
	}

	if (mTarget && IsCollided(mBigHitBox, mTarget->shape))
	{

		TextOut(hdc, (int)mTarget->pos.x, (int)mTarget->pos.y + 100 , "큰 공격 히트!!!!!!!!!!!!", strlen("큰 공격 히트!!!!!!!!!!!!"));
	}
}

void Character::Release()
{
}

void Character::Move(int dir)
{
	if (dir > 0)
	{
		if (IsCollided(this->shape,mTarget->shape))
		{
			if (mTarget->pos.x < this->pos.x)
			{
				pos.x += moveSpeed * dir;
			}
		}
		else
		{
			pos.x += moveSpeed * dir;

			if (this->pos.x + bodySize > mTarget->pos.x - bodySize && !(mTarget->pos.x < this->pos.x))
			{
				this->pos.x -= (this->pos.x + bodySize) - (mTarget->pos.x - bodySize);
			}
		}
	}
	else
	{
		if (IsCollided(this->shape, mTarget->shape))
		{
			if (mTarget->pos.x > this->pos.x)
			{
				pos.x += moveSpeed * dir;
			}
		}
		else
		{
			pos.x += moveSpeed * dir;

			if (this->pos.x - bodySize < mTarget->pos.x + bodySize && !(mTarget->pos.x > this->pos.x))
			{
				this->pos.x -= (this->pos.x - bodySize) - (mTarget->pos.x + bodySize);
			}
		}
	}
}

void Character::OffSmallHitBox()
{
	mSmallHitBox = RECT();
}

void Character::OnBigHitBox()
{
	if (mFrame >= 5)
	{
		mFrame = 0;

		mBigHitBox.left = (int)pos.x;
		mBigHitBox.top = (int)pos.y - 50;
		mBigHitBox.right = (int)pos.x + 70;
		mBigHitBox.bottom = (int)pos.y + 50;
	}
}

void Character::OffBigHitBox()
{
	mBigHitBox = RECT();
}

void Character::AllOffHitBox()
{
	mSmallHitBox = RECT();
	mBigHitBox = RECT();
}

void Character::OnSmallHitBox()
{
	if (mFrame >= 5)
	{
		mFrame = 0;

		mSmallHitBox.left = (int)pos.x;
		mSmallHitBox.top = (int)pos.y - 20;
		mSmallHitBox.right = (int)pos.x + 100;
		mSmallHitBox.bottom = (int)pos.y;
	}
}