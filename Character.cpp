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

void Character::OnWeakPunchHitBox(int dir, ChAnimData* an)
{
	mFrame = 0;

	if (dir > 0)
	{
		mWeakPunchHitBox.left = (int)pos.x;
		mWeakPunchHitBox.right = (int)pos.x + (int)an->mHitboxShapeRight[eAnimStatus::Weak_Punch];
	}
	else
	{
		mWeakPunchHitBox.left = (int)pos.x + (int)an->mHitboxShapeLeft[eAnimStatus::Weak_Punch];
		mWeakPunchHitBox.right = (int)pos.x;
	}
	mWeakPunchHitBox.top = (int)pos.y + (int)an->mHitboxShapeTop[eAnimStatus::Weak_Punch];
	mWeakPunchHitBox.bottom = (int)pos.y + (int)an->mHitboxShapeBottom[eAnimStatus::Weak_Punch];
}

void Character::OffWeakPunchHitBox()
{
	mWeakPunchHitBox = RECT();
	mHitChar.clear();
}

void Character::OnStrongPunchHitBox(int dir, ChAnimData* an)
{
	mFrame = 0;

	if (dir > 0)
	{
		mStrongPunchHitBox.left = (int)pos.x;
		mStrongPunchHitBox.right = (int)pos.x + (int)an->mHitboxShapeRight[eAnimStatus::Strong_Punch];
	}
	else
	{
		mStrongPunchHitBox.left = (int)pos.x + (int)an->mHitboxShapeLeft[eAnimStatus::Strong_Punch];
		mStrongPunchHitBox.right = (int)pos.x;
	}
	mStrongPunchHitBox.top = (int)pos.y + (int)an->mHitboxShapeTop[eAnimStatus::Strong_Punch];
	mStrongPunchHitBox.bottom = (int)pos.y + (int)an->mHitboxShapeBottom[eAnimStatus::Strong_Punch];
}

//void Character::OnStrongPunchHitBox(int dir, ChAnimData* an, eAnimStatus eAnimStatus)
//{
//	mFrame = 0;
//
//	if (dir > 0)
//	{
//		mCreateHitBox.left = (int)pos.x;
//		mCreateHitBox.right = (int)pos.x + (int)an->mHitboxShapeRight[eAnimStatus];
//	}
//	else
//	{
//		mCreateHitBox.left = (int)pos.x + an->mHitboxShapeLeft[eAnimStatus];
//		mCreateHitright = (int)pos.x;
//	}
//
//	mCreateHit.top = (int)pos.y + an->mHitboxShapeTop[eAnimStatus];
//	mCreateHit.bottom = (int)pos.y + an->mHitboxShapeBottom[eAnimStatus];
//}

void Character::OffStrongPunchHitBox()
{
	mStrongPunchHitBox = RECT();
	mHitChar.clear();
}

void Character::OnWeakKickHitBox(int dir, ChAnimData* an)
{
	mFrame = 0;

	if (dir > 0)
	{
		mWeakKickHitBox.left = (int)pos.x;
		mWeakKickHitBox.right = (int)pos.x + (int)an->mHitboxShapeRight[eAnimStatus::Weak_Kick];
	}
	else
	{
		mWeakKickHitBox.left = (int)pos.x + (int)an->mHitboxShapeLeft[eAnimStatus::Weak_Kick];
		mWeakKickHitBox.right = (int)pos.x;
	}
	mWeakKickHitBox.top = (int)pos.y + (int)an->mHitboxShapeTop[eAnimStatus::Weak_Kick];
	mWeakKickHitBox.bottom = (int)pos.y + (int)an->mHitboxShapeBottom[eAnimStatus::Weak_Kick];
}

void Character::OffWeakKickHitBox()
{
	mWeakKickHitBox = RECT();
	mHitChar.clear();
}

void Character::OnStrongKickHitBox(int dir, ChAnimData* an)
{
	mFrame = 0;

	if (dir > 0)
	{
		mStrongKickHitBox.left = (int)pos.x;
		mStrongKickHitBox.right = (int)pos.x + (int)an->mHitboxShapeRight[eAnimStatus::Strong_Kick];
	}
	else
	{
		mStrongKickHitBox.left = (int)pos.x + (int)an->mHitboxShapeLeft[eAnimStatus::Strong_Kick];
		mStrongKickHitBox.right = (int)pos.x;
	}
	mStrongKickHitBox.top = (int)pos.y + (int)an->mHitboxShapeTop[eAnimStatus::Strong_Kick];
	mStrongKickHitBox.bottom = (int)pos.y + (int)an->mHitboxShapeBottom[eAnimStatus::Strong_Kick];
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

		mDir = eMoveDir::Right;
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
		mDir = eMoveDir::Left;
	}
}

void Character::SetShape()
{
	shape.left = (int)pos.x - ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) * 4 / 2);
	shape.top = (int)pos.y - (mpData->mSizeY[eAnimStatus::Idle] * 4 / 2);
	shape.right = (int)pos.x + ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) * 4 / 2);
	shape.bottom = (int)pos.y + (mpData->mSizeY[eAnimStatus::Idle] * 4 / 2);
}