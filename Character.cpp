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

	if (mpTarget && IsCollided(mWeakPunchHitBox, mpTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->mHP -= 10;
			cout << "HP -10 상대 현재 체력 : " << mpTarget->mHP << endl;
		}
	}
	else if (mpTarget && IsCollided(mStrongPunchHitBox, mpTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->mHP -= 20;
			cout << "HP -20 상대 현재 체력 : " << mpTarget->mHP << endl;
		}
	}
	else if (mpTarget && IsCollided(mWeakPunchHitBox, mpTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->mHP -= 15;
			cout << "HP -15 상대 현재 체력 : " << mpTarget->mHP << endl;
		}
	}
	else if (mpTarget && IsCollided(mStrongPunchHitBox, mpTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->mHP -= 30;
			cout << "HP -30 상대 현재 체력 : " << mpTarget->mHP << endl;
		}
	}

	shape.left = (int)pos.x - bodySize;
	shape.top = (int)pos.y - bodySize;
	shape.right = (int)pos.x + bodySize;
	shape.bottom = (int)pos.y + bodySize;
}

void Character::Render(HDC hdc)
{
	Rectangle(hdc, shape.left, shape.top, shape.right, shape.bottom);
	Rectangle(hdc, mWeakPunchHitBox.left, mWeakPunchHitBox.top, mWeakPunchHitBox.right, mWeakPunchHitBox.bottom);
	Rectangle(hdc, mStrongPunchHitBox.left, mStrongPunchHitBox.top, mStrongPunchHitBox.right, mStrongPunchHitBox.bottom);
	Rectangle(hdc, mWeakKickHitBox.left, mWeakKickHitBox.top, mWeakKickHitBox.right, mWeakKickHitBox.bottom);
	Rectangle(hdc, mStrongKickHitBox.left, mStrongKickHitBox.top, mStrongKickHitBox.right, mStrongKickHitBox.bottom);

	if (mFrame < 5)
	{
		if (mpTarget && IsCollided(mWeakPunchHitBox, mpTarget->shape))
		{
			TextOut(hdc, (int)mpTarget->pos.x, (int)mpTarget->pos.y - 40, "HP -10", strlen("HP -10"));
		}
		else if (mpTarget && IsCollided(mStrongPunchHitBox, mpTarget->shape))
		{
			TextOut(hdc, (int)mpTarget->pos.x, (int)mpTarget->pos.y - 40, "HP -20", strlen("HP -20"));
		}
		else if (mpTarget && IsCollided(mWeakKickHitBox, mpTarget->shape))
		{
			TextOut(hdc, (int)mpTarget->pos.x, (int)mpTarget->pos.y - 40, "HP -20", strlen("HP -20"));
		}
		else if (mpTarget && IsCollided(mStrongKickHitBox, mpTarget->shape))
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
		if (IsCollided(this->shape, mpTarget->shape))
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

void Character::OnWeakPunchHitBox(int dir)
{
	mFrame = 0;

	if (dir > 0)
	{
		mWeakPunchHitBox.left = (int)pos.x;
		mWeakPunchHitBox.right = (int)pos.x + 70;
	}
	else
	{
		mWeakPunchHitBox.left = (int)pos.x - 70;
		mWeakPunchHitBox.right = (int)pos.x;
	}
	mWeakPunchHitBox.top = (int)pos.y - 25;
	mWeakPunchHitBox.bottom = (int)pos.y - 15;
}

void Character::OffWeakPunchHitBox()
{
	mWeakPunchHitBox = RECT();
	mHitChar.clear();
}

void Character::OnStrongPunchHitBox(int dir)
{
	mFrame = 0;

	if (dir > 0)
	{
		mStrongPunchHitBox.left = (int)pos.x;
		mStrongPunchHitBox.right = (int)pos.x + 80;
	}
	else
	{
		mStrongPunchHitBox.left = (int)pos.x - 80;
		mStrongPunchHitBox.right = (int)pos.x;
	}

	mStrongPunchHitBox.top = (int)pos.y - 30;
	mStrongPunchHitBox.bottom = (int)pos.y - 10;
}

void Character::OffStrongPunchHitBox()
{
	mStrongPunchHitBox = RECT();
	mHitChar.clear();
}

void Character::OnWeakKickHitBox(int dir)
{
	mFrame = 0;

	if (dir > 0)
	{
		mWeakKickHitBox.left = (int)pos.x;
		mWeakKickHitBox.right = (int)pos.x + 78;
	}
	else
	{
		mWeakKickHitBox.left = (int)pos.x - 78;
		mWeakKickHitBox.right = (int)pos.x;
	}
	mWeakKickHitBox.top = (int)pos.y - 40;
	mWeakKickHitBox.bottom = (int)pos.y + 10;
}

void Character::OffWeakKickHitBox()
{
	mWeakKickHitBox = RECT();
	mHitChar.clear();
}

void Character::OnStrongKickHitBox(int dir)
{
	mFrame = 0;

	if (dir > 0)
	{
		mStrongKickHitBox.left = (int)pos.x;
		mStrongKickHitBox.right = (int)pos.x + 135;
	}
	else
	{
		mStrongKickHitBox.left = (int)pos.x - 135;
		mStrongKickHitBox.right = (int)pos.x;
	}
	mStrongKickHitBox.top = (int)pos.y - 45;
	mStrongKickHitBox.bottom = (int)pos.y;
}

void Character::OffStrongKickHitBox()
{
	mStrongKickHitBox = RECT();
	mHitChar.clear();
}

void Character::AllOffHitBox()
{
	mWeakPunchHitBox = RECT();
	mStrongPunchHitBox = RECT();
	mWeakKickHitBox = RECT();
	mStrongKickHitBox = RECT();
	mHitChar.clear();
}