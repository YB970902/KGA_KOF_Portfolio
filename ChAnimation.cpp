#include "ChAnimation.h"
#include "ChAnimData.h"
#include "Image.h"
#include "KeyManager.h"
#include <map>

using namespace std;

void ChAnimation::ImgUpdate(AnimStatus playerStatus)
{
	img->Release();
	img->Init(mpData->mPath[mpData->mPlayerStatus], (int)mpData->mSizeX[mpData->mPlayerStatus], (int)mpData->mSizeY[mpData->mPlayerStatus],
		(int)mpData->mAnimframe[mpData->mPlayerStatus], 1, true, RGB(255, 0, 255));
}

void ChAnimation::Update()
{
	if (mpData->mIsAttack == false)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown('Z'))
		{
			Attack(AnimStatus::Weak_Punch);
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('X'))
		{
			Attack(AnimStatus::Strong_Punch);
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('C'))
		{
			Attack(AnimStatus::Weak_Kick);
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('V'))
		{
			Attack(AnimStatus::Strong_Kick);
		}
	}

	if (mpData->mPlayerAct != Acting::Act_Attack)
	{
		if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
		{
			MoveLeft();
		}
		else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
		{
			MoveRight();
		}
		else
		{
			if (mpData->mPlayerAct != Acting::Act_Idle)
			{
				frameX = 0;
			}
			mpData->mPlayerAct = Acting::Act_Idle;
			mpData->mPlayerStatus = AnimStatus::Idle;
		}
	}

	if (mpData->mPlayerAct == Acting::Act_Attack)
	{
		if (mpData->mPlayerStatus == AnimStatus::Weak_Punch)
		{
			ImgUpdate(mpData->mPlayerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;

				if (frameX == 2)
				{
					OnWeakPunchHitBox((int)mpData->mPlayerLookat);
				}
				else if (frameX == 3)
				{
					OffWeakPunchHitBox();
				}

				if (frameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					frameX = 0;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (mpData->mPlayerStatus == AnimStatus::Strong_Punch)
		{
			ImgUpdate(mpData->mPlayerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;

				if (frameX == 4)
				{
					OnStrongPunchHitBox((int)mpData->mPlayerLookat);
				}
				else if (frameX == 9)
				{
					OffStrongPunchHitBox();
				}

				if (frameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					frameX = 0;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (mpData->mPlayerStatus == AnimStatus::Weak_Kick)
		{
			ImgUpdate(mpData->mPlayerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;

				if (frameX == 3)
				{
					OnWeakKickHitBox((int)mpData->mPlayerLookat);
				}
				else if (frameX == 5)
				{
					OffWeakKickHitBox();
				}

				if (frameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					frameX = 0;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (mpData->mPlayerStatus == AnimStatus::Strong_Kick)
		{
			ImgUpdate(mpData->mPlayerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;


				if (frameX == 5)
				{
					OnStrongKickHitBox((int)mpData->mPlayerLookat);
				}
				else if (frameX == 8)
				{
					OffStrongKickHitBox();
				}

				if (frameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					frameX = 0;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
	}

	else if (mpData->mPlayerAct != Acting::Act_Attack) // 공격상태에서는 Idle과 Move가 작동하면 안되므로 공격상태인지 아닌지 판별
	{
		if (mpData->mPlayerStatus == AnimStatus::Move_Forward || mpData->mPlayerStatus == AnimStatus::Move_Backward) //Move일때
		{
			// 왼쪽으로 움직이기
			if (mpData->mPlayerAct == Acting::Act_Left_Move)
			{
				ImgUpdate(mpData->mPlayerStatus);
				elapsedCount++;
				if (elapsedCount >= 8)
				{
					if (mpData->mPlayerLookat == Lookat::Right_Lookat)
					{
						if (mpData->mNotReverse == 1)
						{
							frameX++;
							if (frameX >= mpData->mAnimframe[mpData->mPlayerStatus] - 1)
							{
								frameX = 0;
							}
						}
						else
						{
							frameX--;
							if (frameX < 0)
							{
								frameX = mpData->mAnimframe[mpData->mPlayerStatus] - 1;
							}
						}
					}
					else if (mpData->mPlayerLookat == Lookat::Left_Lookat)
					{
						frameX++;
						if (frameX >= mpData->mAnimframe[mpData->mPlayerStatus] - 1)
						{
							frameX = 0;
						}
					}
					pos.x -= moveSpeed;
					elapsedCount = 0;
				}

			}
			// 오른쪽으로 움직이기
			else if (mpData->mPlayerAct == Acting::Act_Right_Move)
			{
				ImgUpdate(mpData->mPlayerStatus);

				elapsedCount++;
				if (elapsedCount >= 8)//(int)AnimSpeed[mpData->mPlayerStatus])
				{
					if (mpData->mPlayerLookat == Lookat::Right_Lookat)
					{
						frameX++;
						if (frameX >= mpData->mAnimframe[mpData->mPlayerStatus] - 1)
						{
							frameX = 0;
						}
					}
					else if (mpData->mPlayerLookat == Lookat::Left_Lookat)
					{
						if (mpData->mNotReverse == 1)
						{
							frameX++;
							if (frameX >= mpData->mAnimframe[mpData->mPlayerStatus] - 1)
							{
								frameX = 0;
							}
						}
						else
						{
							frameX--;
							if (frameX < 0)
							{
								frameX = mpData->mAnimframe[mpData->mPlayerStatus] - 1;
							}
						}
					}
					pos.x += moveSpeed;
					elapsedCount = 0;
				}
			}
		}

		else if (mpData->mPlayerAct == Acting::Act_Idle) // Idle 일때
		{
			ImgUpdate(mpData->mPlayerStatus);

			elapsedCount++;
			if (elapsedCount >= 8)
			{
				frameX++;
				if (frameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					frameX = 0;
				}
				elapsedCount = 0;
			}
		}
	}

	baseX = mpData->mSizeX[mpData->mPlayerStatus] / (int)mpData->mAnimframe[AnimStatus::Idle];
	baseY = (int)mpData->mSizeY[AnimStatus::Idle];

	shape.left = (int)pos.x - ((mpData->mSizeX[AnimStatus::Idle] / mpData->mAnimframe[AnimStatus::Idle]) / 2);
	shape.top = (int)pos.y - (mpData->mSizeY[AnimStatus::Idle] / 2);
	shape.right = (int)pos.x + ((mpData->mSizeX[AnimStatus::Idle] / mpData->mAnimframe[AnimStatus::Idle]) / 2);
	shape.bottom = (int)pos.y + (mpData->mSizeY[AnimStatus::Idle] / 2);

	if (mpTarget && IsCollided(mWeakPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->SetHP(10);
			cout << "HP -10 상대 현재 체력 : " << mpTarget->GetHP() << endl;
		}
	}
	else if (mpTarget && IsCollided(mStrongPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->SetHP(20);
			cout << "HP -20 상대 현재 체력 : " << mpTarget->GetHP() << endl;
		}
	}
	else if (mpTarget && IsCollided(mWeakPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->SetHP(15);
			cout << "HP -15 상대 현재 체력 : " << mpTarget->GetHP() << endl;
		}
	}
	else if (mpTarget && IsCollided(mStrongPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->SetHP(30);
			cout << "HP -30 상대 현재 체력 : " << mpTarget->GetHP() << endl;
		}
	}
}

void ChAnimation::Render(HDC hdc)
{
	Rectangle(hdc, shape.left, shape.top, shape.right, shape.bottom);

	Rectangle(hdc, mWeakPunchHitBox.left, mWeakPunchHitBox.top, mWeakPunchHitBox.right, mWeakPunchHitBox.bottom);
	Rectangle(hdc, mStrongPunchHitBox.left, mStrongPunchHitBox.top, mStrongPunchHitBox.right, mStrongPunchHitBox.bottom);
	Rectangle(hdc, mWeakKickHitBox.left, mWeakKickHitBox.top, mWeakKickHitBox.right, mWeakKickHitBox.bottom);
	Rectangle(hdc, mStrongKickHitBox.left, mStrongKickHitBox.top, mStrongKickHitBox.right, mStrongKickHitBox.bottom);

	if (img)
	{
		img->Render(hdc, (int)pos.x, (int)pos.y, frameX, frameY, baseX, baseY, mpData->mPlayerStatus, mpData->mPlayerLookat);
	}
}

void ChAnimation::Release()
{
	SAFE_RELEASE(img);
}

FLOAT ChAnimation::moveAfterAction(FLOAT pos)
{
	if (mpData->mPlayerLookat == Lookat::Right_Lookat)
	{
		pos = pos + (FLOAT)(mpData->mMoveAfteraction[mpData->mPlayerStatus]);
	}
	else if (mpData->mPlayerLookat == Lookat::Left_Lookat)
	{
		pos = pos - (FLOAT)(mpData->mMoveAfteraction[mpData->mPlayerStatus]);;
	}
	return pos;
}

void ChAnimation::Attack(AnimStatus type)
{
	if (mpData->mPlayerStatus != type)
	{
		frameX = 0;
	}
	mpData->mIsAttack = true;
	mpData->mPlayerAct = Acting::Act_Attack;
	mpData->mPlayerStatus = type;
}

void ChAnimation::MoveLeft()
{
	if (mpData->mPlayerAct != Acting::Act_Left_Move)
	{
		frameX = 0;
	}

	if (mpData->mPlayerLookat == Lookat::Left_Lookat)
	{
		mpData->mPlayerStatus = AnimStatus::Move_Forward;
	}
	else if (mpData->mPlayerLookat == Lookat::Right_Lookat)
	{
		mpData->mPlayerStatus = AnimStatus::Move_Backward;
	}

	mpData->mPlayerAct = Acting::Act_Left_Move;
}

void ChAnimation::MoveRight()
{
	if (mpData->mPlayerAct != Acting::Act_Right_Move)
	{
		frameX = 0;
	}
	mpData->mPlayerAct = Acting::Act_Right_Move;

	if (mpData->mPlayerLookat == Lookat::Left_Lookat)
	{
		mpData->mPlayerStatus = AnimStatus::Move_Backward;
	}
	else if (mpData->mPlayerLookat == Lookat::Right_Lookat)
	{
		mpData->mPlayerStatus = AnimStatus::Move_Forward;
	}
}
