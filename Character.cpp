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

void Character::OnWeakPunchHitBox(int dir, ChAnimData* an)
{
	mFrame = 0;

	if (dir > 0)
	{
		mWeakPunchHitBox.left = (int)pos.x;
		mWeakPunchHitBox.right = (int)pos.x + (int)an->mHitboxShapeRight[AnimStatus::Weak_Punch];
	}
	else
	{
		mWeakPunchHitBox.left = (int)pos.x + (int)an->mHitboxShapeLeft[AnimStatus::Weak_Punch];
		mWeakPunchHitBox.right = (int)pos.x;
	}
	mWeakPunchHitBox.top = (int)pos.y + (int)an->mHitboxShapeTop[AnimStatus::Weak_Punch];
	mWeakPunchHitBox.bottom = (int)pos.y + (int)an->mHitboxShapeBottom[AnimStatus::Weak_Punch];
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
		mStrongPunchHitBox.right = (int)pos.x + (int)an->mHitboxShapeRight[AnimStatus::Strong_Punch];
	}
	else
	{
		mStrongPunchHitBox.left = (int)pos.x + (int)an->mHitboxShapeLeft[AnimStatus::Strong_Punch];
		mStrongPunchHitBox.right = (int)pos.x;
	}
	mStrongPunchHitBox.top = (int)pos.y + (int)an->mHitboxShapeTop[AnimStatus::Strong_Punch];
	mStrongPunchHitBox.bottom = (int)pos.y + (int)an->mHitboxShapeBottom[AnimStatus::Strong_Punch];
}

//void Character::OnStrongPunchHitBox(int dir, ChAnimData* an, AnimStatus animstatus)
//{
//	mFrame = 0;
//
//	if (dir > 0)
//	{
//		mCreateHitBox.left = (int)pos.x;
//		mCreateHitBox.right = (int)pos.x + (int)an->mHitboxShapeRight[animstatus];
//	}
//	else
//	{
//		mCreateHitBox.left = (int)pos.x + an->mHitboxShapeLeft[animstatus];
//		mCreateHitright = (int)pos.x;
//	}
//
//	mCreateHit.top = (int)pos.y + an->mHitboxShapeTop[animstatus];
//	mCreateHit.bottom = (int)pos.y + an->mHitboxShapeBottom[animstatus];
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
		mWeakKickHitBox.right = (int)pos.x + (int)an->mHitboxShapeRight[AnimStatus::Weak_Kick];
	}
	else
	{
		mWeakKickHitBox.left = (int)pos.x + (int)an->mHitboxShapeLeft[AnimStatus::Weak_Kick];
		mWeakKickHitBox.right = (int)pos.x;
	}
	mWeakKickHitBox.top = (int)pos.y + (int)an->mHitboxShapeTop[AnimStatus::Weak_Kick];
	mWeakKickHitBox.bottom = (int)pos.y + (int)an->mHitboxShapeBottom[AnimStatus::Weak_Kick];
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
		mStrongKickHitBox.right = (int)pos.x + (int)an->mHitboxShapeRight[AnimStatus::Strong_Kick];
	}
	else
	{
		mStrongKickHitBox.left = (int)pos.x + (int)an->mHitboxShapeLeft[AnimStatus::Strong_Kick];
		mStrongKickHitBox.right = (int)pos.x;
	}
	mStrongKickHitBox.top = (int)pos.y + (int)an->mHitboxShapeTop[AnimStatus::Strong_Kick];
	mStrongKickHitBox.bottom = (int)pos.y + (int)an->mHitboxShapeBottom[AnimStatus::Strong_Kick];
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