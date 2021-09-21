#include "Character.h"

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
	if (mFrame == 5)
	{
		AllOffHitBox();
	}

	mFrame++;

	if (mpTarget && IsCollided(mSmallHitBox, mpTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->mHP -= 10;
			cout << "HP -10 상대 현재 체력 : " << mpTarget->mHP << endl;
		}
	}

	//if (mBigHitBox.right != 0)
	//{
	//	Move((int)mDir);

	//	if ((int)mDir > 0)
	//	{
	//		mBigHitBox.left = (int)pos.x;
	//		mBigHitBox.top = (int)pos.y - 50;
	//		mBigHitBox.right = (int)pos.x + 70;
	//		mBigHitBox.bottom = (int)pos.y + 50;
	//	}
	//	else
	//	{
	//		mBigHitBox.left = (int)pos.x - 70;
	//		mBigHitBox.top = (int)pos.y - 50;
	//		mBigHitBox.right = (int)pos.x;
	//		mBigHitBox.bottom = (int)pos.y + 50;
	//	}

		if (mpTarget && IsCollided(mBigHitBox, mpTarget->shape))
		{
			if (!CheckHitChar())
			{
				mHitChar.push_back(mpTarget);
				mpTarget->mHP -= 20;
				cout << "HP -20 상대 현재 체력 : " << mpTarget->mHP << endl;
			}
		}			
	//}


	shape.left = (int)pos.x - bodySize;
	shape.top = (int)pos.y - bodySize;
	shape.right = (int)pos.x + bodySize;
	shape.bottom = (int)pos.y + bodySize;
}

void Character::Render(HDC hdc)
{
	Rectangle(hdc, shape.left, shape.top, shape.right, shape.bottom);
	Rectangle(hdc, mSmallHitBox.left, mSmallHitBox.top, mSmallHitBox.right, mSmallHitBox.bottom);
	Rectangle(hdc, mBigHitBox.left, mBigHitBox.top, mBigHitBox.right, mBigHitBox.bottom);

	if (mFrame < 5)
	{
		if (mpTarget && IsCollided(mSmallHitBox, mpTarget->shape))
		{
			TextOut(hdc, (int)mpTarget->pos.x, (int)mpTarget->pos.y - 40, "HP -10", strlen("HP -10"));
		}
		if (mpTarget && IsCollided(mBigHitBox, mpTarget->shape))
		{
			TextOut(hdc, (int)mpTarget->pos.x, (int)mpTarget->pos.y - 40, "HP -20", strlen("HP -20"));
		}
	}
}

void Character::Release()
{
}

void Character::Move(int dir)
{
	if (dir > 0)
	{
		if (IsCollided(this->shape,mpTarget->shape))
		{
			if (mpTarget->pos.x < this->pos.x)
			{
				pos.x += moveSpeed * dir;
			}
		}
		else
		{
			pos.x += moveSpeed * dir;

			if (this->pos.x + bodySize > mpTarget->pos.x - bodySize && !(mpTarget->pos.x < this->pos.x))
			{
				this->pos.x -= (this->pos.x + bodySize) - (mpTarget->pos.x - bodySize);
			}
		}

		mDir = MoveDir::Right;
	}
	else
	{
		if (IsCollided(this->shape, mpTarget->shape))
		{
			if (mpTarget->pos.x > this->pos.x)
			{
				pos.x += moveSpeed * dir;
			}
		}
		else
		{
			pos.x += moveSpeed * dir;

			if (this->pos.x - bodySize < mpTarget->pos.x + bodySize && !(mpTarget->pos.x > this->pos.x))
			{
				this->pos.x -= (this->pos.x - bodySize) - (mpTarget->pos.x + bodySize);
			}
		}
		mDir = MoveDir::Left;
	}
}

bool Character::CheckHitChar()
{
	for (const auto& item : mHitChar)
	{
		if (item == mpTarget)
		{
			return true;
		}
	}
	return false;
}

void Character::OnSmallHitBox(int dir)
{
	mFrame = 0;

	if (dir > 0)
	{
		mSmallHitBox.left = (int)pos.x;
		mSmallHitBox.top = (int)pos.y - 20;
		mSmallHitBox.right = (int)pos.x + 100;
		mSmallHitBox.bottom = (int)pos.y;
	}
	else
	{
		mSmallHitBox.left = (int)pos.x - 100;
		mSmallHitBox.top = (int)pos.y - 20;
		mSmallHitBox.right = (int)pos.x;
		mSmallHitBox.bottom = (int)pos.y;
	}
}

void Character::OffSmallHitBox()
{
	mSmallHitBox = RECT();
}

void Character::OnBigHitBox(int dir)
{
	mFrame = 0;

	if (dir > 0)
	{
		mBigHitBox.left = (int)pos.x;
		mBigHitBox.top = (int)pos.y - 50;
		mBigHitBox.right = (int)pos.x + 70;
		mBigHitBox.bottom = (int)pos.y + 50;
	}
	else
	{
		mBigHitBox.left = (int)pos.x - 70;
		mBigHitBox.top = (int)pos.y - 50;
		mBigHitBox.right = (int)pos.x;
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
	mHitChar.clear();
}