#include "ChAnimation.h"
#include "ChAnimData.h"
#include "Image.h"
#include "KeyManager.h"
#include <map>

using namespace std;

void ChAnimation::ImgUpdate(eAnimStatus playerStatus)
{
	img->Release();
	img->Init(mpData->mPath[mpData->mPlayerStatus], (int)mpData->mSizeX[mpData->mPlayerStatus], (int)mpData->mSizeY[mpData->mPlayerStatus],
		(int)mpData->mAnimframe[mpData->mPlayerStatus], 1, true, RGB(255, 0, 255));
}

void ChAnimation::Update()
{
	if (mpTarget && IsCollided(mWeakPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->SetHP(10);
			cout << "HP -10 ��� ���� ü�� : " << mpTarget->GetHP() << endl;

		}
	}
	else if (mpTarget && IsCollided(mStrongPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->SetHP(20);
			cout << "HP -20 ��� ���� ü�� : " << mpTarget->GetHP() << endl;
		}
	}
	else if (mpTarget && IsCollided(mWeakPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->SetHP(15);
			cout << "HP -15 ��� ���� ü�� : " << mpTarget->GetHP() << endl;
		}
	}
	else if (mpTarget && IsCollided(mStrongPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->SetHP(30);
			cout << "HP -30 ��� ���� ü�� : " << mpTarget->GetHP() << endl;
		}
	}

	if (mpData->mPlayerAct == eActing::Act_Attack)
	{
		if (mpData->mPlayerStatus == eAnimStatus::Weak_Punch)
		{
			ImgUpdate(mpData->mPlayerStatus);
			mElapsedCount++;
			if (mElapsedCount >= 4)
			{
				mFrameX++;

<<<<<<< HEAD
				if (mFrameX == 2)
=======
				if (frameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
				{
					OnWeakPunchHitBox((int)mpData->mPlayerLookat,mpData);
				}
<<<<<<< HEAD
				else if (mFrameX == 3)
=======
				else if (frameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
				{
					OffWeakPunchHitBox();
				}

<<<<<<< HEAD
				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
=======
				if (frameX >= (int)mpData->mAnimframe[mpData->mPlayerStatus])
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
				{
					mFrameX = 0;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = eActing::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				mElapsedCount = 0;
			}
		}
		else if (mpData->mPlayerStatus == eAnimStatus::Strong_Punch)
		{
			ImgUpdate(mpData->mPlayerStatus);
			mElapsedCount++;
			if (mElapsedCount >= 4)
			{
				mFrameX++;

<<<<<<< HEAD
				if (mFrameX == 4)
=======
				if (frameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
				{
					OnStrongPunchHitBox((int)mpData->mPlayerLookat, mpData);
				}
<<<<<<< HEAD
				else if (mFrameX == 9)
=======
				else if (frameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
				{
					OffStrongPunchHitBox();
				}

<<<<<<< HEAD
				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
=======
				if (frameX >= (int)mpData->mAnimframe[mpData->mPlayerStatus])
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
				{
					mFrameX = 0;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = eActing::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				mElapsedCount = 0;
			}
		}
		else if (mpData->mPlayerStatus == eAnimStatus::Weak_Kick)
		{
			ImgUpdate(mpData->mPlayerStatus);
			mElapsedCount++;
			if (mElapsedCount >= 4)
			{
				mFrameX++;

<<<<<<< HEAD
				if (mFrameX == 3)
=======
				if (frameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
				{
					OnWeakKickHitBox((int)mpData->mPlayerLookat, mpData);
				}
<<<<<<< HEAD
				else if (mFrameX == 5)
=======
				else if (frameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
				{
					OffWeakKickHitBox();
				}

				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 0;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = eActing::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				mElapsedCount = 0;
			}
		}
		else if (mpData->mPlayerStatus == eAnimStatus::Strong_Kick)
		{
			ImgUpdate(mpData->mPlayerStatus);
			mElapsedCount++;
			if (mElapsedCount >= 4)
			{
				mFrameX++;

<<<<<<< HEAD
				if (mFrameX == 5)
=======

				if (frameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
				{
					OnStrongKickHitBox((int)mpData->mPlayerLookat, mpData);
				}
<<<<<<< HEAD
				else if (mFrameX == 8)
=======
				else if (frameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
				{
					OffStrongKickHitBox();
				}

				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 0;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = eActing::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				mElapsedCount = 0;
			}
		}
	}

	else if (mpData->mPlayerAct != eActing::Act_Attack) // ���ݻ��¿����� Idle�� Move�� �۵��ϸ� �ȵǹǷ� ���ݻ������� �ƴ��� �Ǻ�
	{
		if (mpData->mPlayerStatus == eAnimStatus::Move_Forward || mpData->mPlayerStatus == eAnimStatus::Move_Backward) //Move�϶�
		{
			// �������� �����̱�
			if (mpData->mPlayerAct == eActing::Act_Left_Move)
			{
				ImgUpdate(mpData->mPlayerStatus);
				mElapsedCount++;
				if (mElapsedCount >= 8)
				{
					if (mpData->mPlayerLookat == eLookat::Right_Lookat)
					{
						if (mpData->mNotReverse == 1)
						{
							mFrameX++;
							if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus] - 1)
							{
								mFrameX = 0;
							}
						}
						else
						{
							mFrameX--;
							if (mFrameX < 0)
							{
								mFrameX = mpData->mAnimframe[mpData->mPlayerStatus] - 1;
							}
						}
					}
					else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
					{
						mFrameX++;
						if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus] - 1)
						{
							mFrameX = 0;
						}
					}

					pos.x -= moveSpeed;

					mElapsedCount = 0;
				}

			}
			// ���������� �����̱�
			else if (mpData->mPlayerAct == eActing::Act_Right_Move)
			{
				ImgUpdate(mpData->mPlayerStatus);

				mElapsedCount++;
				if (mElapsedCount >= 8)//(int)AnimSpeed[mpData->mPlayerStatus])
				{
					if (mpData->mPlayerLookat == eLookat::Right_Lookat)
					{
						mFrameX++;
						if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus] - 1)
						{
							mFrameX = 0;
						}
					}
					else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
					{
						if (mpData->mNotReverse == 1)
						{
							mFrameX++;
							if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus] - 1)
							{
								mFrameX = 0;
							}
						}
						else
						{
							mFrameX--;
							if (mFrameX < 0)
							{
								mFrameX = mpData->mAnimframe[mpData->mPlayerStatus] - 1;
							}
						}
					}
					pos.x += moveSpeed;
					mElapsedCount = 0;
				}
			}
		}

		else if (mpData->mPlayerAct == eActing::Act_Idle) // Idle �϶�
		{
			ImgUpdate(mpData->mPlayerStatus);

			mElapsedCount++;
			if (mElapsedCount >= 8)
			{
				mFrameX++;
				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 0;
				}
				mElapsedCount = 0;
			}
		}
	}

	baseX = mpData->mSizeX[mpData->mPlayerStatus] / (int)mpData->mAnimframe[eAnimStatus::Idle];
	baseY = (int)mpData->mSizeY[eAnimStatus::Idle];

	shape.left = (int)pos.x - ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) / 2);
	shape.top = (int)pos.y - (mpData->mSizeY[eAnimStatus::Idle] / 2);
	shape.right = (int)pos.x + ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) / 2);
	shape.bottom = (int)pos.y + (mpData->mSizeY[eAnimStatus::Idle] / 2);

	// �������� �̵����� �� �浹�� �ִٸ�
	if (mpData->mPlayerAct == eActing::Act_Left_Move)
	{
		if (shape.left < 0)
		{
			pos.x -= shape.left;

			shape.left = (int)pos.x - ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) / 2);
			shape.top = (int)pos.y - (mpData->mSizeY[eAnimStatus::Idle] / 2);
			shape.right = (int)pos.x + ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) / 2);
			shape.bottom = (int)pos.y + (mpData->mSizeY[eAnimStatus::Idle] / 2);
		}
		else if (IsCollided(shape, mpTarget->GetShape()))
		{
			pos.x += mpTarget->GetShape().right - shape.left;

			shape.left = (int)pos.x - ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) / 2);
			shape.top = (int)pos.y - (mpData->mSizeY[eAnimStatus::Idle] / 2);
			shape.right = (int)pos.x + ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) / 2);
			shape.bottom = (int)pos.y + (mpData->mSizeY[eAnimStatus::Idle] / 2);
		}
	}

	// ���������� �̵����� �� �浹�� �ִٸ�
	if (mpData->mPlayerAct == eActing::Act_Right_Move)
	{
		if (shape.right > WIN_SIZE_X)
		{
			pos.x += WIN_SIZE_X - shape.right;

			shape.left = (int)pos.x - ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) / 2);
			shape.top = (int)pos.y - (mpData->mSizeY[eAnimStatus::Idle] / 2);
			shape.right = (int)pos.x + ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) / 2);
			shape.bottom = (int)pos.y + (mpData->mSizeY[eAnimStatus::Idle] / 2);
		}
		else if (IsCollided(shape, mpTarget->GetShape()))
		{
			pos.x += mpTarget->GetShape().left - shape.right;

			shape.left = (int)pos.x - ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) / 2);
			shape.top = (int)pos.y - (mpData->mSizeY[eAnimStatus::Idle] / 2);
			shape.right = (int)pos.x + ((mpData->mSizeX[eAnimStatus::Idle] / mpData->mAnimframe[eAnimStatus::Idle]) / 2);
			shape.bottom = (int)pos.y + (mpData->mSizeY[eAnimStatus::Idle] / 2);
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
		img->Render(hdc, (int)pos.x, (int)pos.y, mFrameX, mFrameY, baseX, baseY, mpData->mPlayerStatus, mpData->mPlayerLookat);
	}
}

void ChAnimation::Release()
{
	SAFE_RELEASE(img);
}

FLOAT ChAnimation::moveAfterAction(FLOAT pos)
{
	if (mpData->mPlayerLookat == eLookat::Right_Lookat)
	{
		pos = pos + (FLOAT)(mpData->mMoveAfteraction[mpData->mPlayerStatus]);
	}
	else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
	{
		pos = pos - (FLOAT)(mpData->mMoveAfteraction[mpData->mPlayerStatus]);
	}
	return pos;
}

void ChAnimation::Attack(eAnimStatus type)
{
	if (mpData->mPlayerStatus != type)
	{
		mFrameX = 0;
	}
	mpData->mIsAttack = true;
	mpData->mPlayerAct = eActing::Act_Attack;
	mpData->mPlayerStatus = type;
}

void ChAnimation::MoveLeft()
{
	if (mpData->mPlayerAct != eActing::Act_Left_Move)
	{
		mFrameX = 0;
	}

	if (mpData->mPlayerLookat == eLookat::Left_Lookat)
	{
		mpData->mPlayerStatus = eAnimStatus::Move_Forward;
	}
	else if (mpData->mPlayerLookat == eLookat::Right_Lookat)
	{
		mpData->mPlayerStatus = eAnimStatus::Move_Backward;
	}

	mpData->mPlayerAct = eActing::Act_Left_Move;
}

void ChAnimation::MoveRight()
{
	if (mpData->mPlayerAct != eActing::Act_Right_Move)
	{
		mFrameX = 0;
	}
	mpData->mPlayerAct = eActing::Act_Right_Move;

	if (mpData->mPlayerLookat == eLookat::Left_Lookat)
	{
		mpData->mPlayerStatus = eAnimStatus::Move_Backward;
	}
	else if (mpData->mPlayerLookat == eLookat::Right_Lookat)
	{
		mpData->mPlayerStatus = eAnimStatus::Move_Forward;
	}

}