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

	if (mTarget && IsCollided(mSmallHitBox, mTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mTarget);
			mTarget->mHP -= SMALL_DAMAGE;
			cout << "HP -10 상대 현재 체력 : " << mTarget->mHP << endl;
		}
		cout << "작은 공격 프레임" << endl;
	}

	if (mTarget && IsCollided(mBigHitBox, mTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mTarget);
			mTarget->mHP -= BIG_DAMAGE;
			cout << "HP -20 상대 현재 체력 : " << mTarget->mHP << endl;
		}
		cout << "큰 공격 프레임" << endl;
	}

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
		if (mTarget && IsCollided(mSmallHitBox, mTarget->shape))
		{
			TextOut(hdc, (int)mTarget->pos.x, (int)mTarget->pos.y - 40, "HP -10", strlen("HP -10"));
		}
		if (mTarget && IsCollided(mBigHitBox, mTarget->shape))
		{
			TextOut(hdc, (int)mTarget->pos.x, (int)mTarget->pos.y - 40, "HP -20", strlen("HP -20"));
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

		mDir = MoveDir::Right;
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
		mDir = MoveDir::Left;
	}
}

bool Character::CheckHitChar()
{
	for (const auto& item : mHitChar)
	{
		if (item == mTarget)
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