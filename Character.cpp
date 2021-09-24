#include "Character.h"

void Character::Init()
{
}

void Character::Update()
{
}

void Character::Render(HDC hdc)
{
}

void Character::Release()
{
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