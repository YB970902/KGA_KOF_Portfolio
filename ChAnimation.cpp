#include "ChAnimation.h"
#include "ChAnimData.h"
#include "Image.h"
#include "KeyManager.h"
#include "ImageManager.h"
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
	if (MGR_KEY->IsOnceKeyDown('7'))
	{

		//Damaged(eAnimStatus::Damaged);
		if (mpData->mIsDamaged == false)
		{
			mFrameX = 0;
		}
		mpData->mIsDamaged = true;
		mpData->mPlayerAct = eActing::Damaged;
		mpData->mPlayerStatus = eAnimStatus::Damaged;
	}

	if (MGR_KEY->IsOnceKeyDown('8'))
	{
		if (mpData->mIsDead == false)
		{
			mFrameX = 0;
		}

		mpData->mIsDead = true;
		mpData->mPlayerAct = eActing::Dead;
		mpData->mPlayerStatus = eAnimStatus::Dead;
	}

	if (mpTarget && IsCollided(mWeakPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			HitTarget(5, 20.0f);

			if (mpTarget->GetHP() <= 0)
			{
				if (mpTarget->GetData()->mIsDead == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDead = true;
				mpTarget->GetData()->mPlayerAct = eActing::Dead;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Dead;
			}
			else
			{

				if (mpTarget->GetData()->mIsDamaged == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDamaged = true;
				mpTarget->GetData()->mPlayerAct = eActing::Damaged;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Damaged;

				if (mpData->mPlayerLookat == eLookat::Right_Lookat)
				{
					if (mpTarget->GetShape().right >= WIN_SIZE_X)
					{
						if ((pos.x + mpData->mHitboxShapeRight[mpData->mPlayerStatus]) > mpTarget->GetShape().left)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeRight[mpData->mPlayerStatus]) - (mpTarget->GetShape().left - shape.right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
				else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
				{
					if (mpTarget->GetShape().left <= 0)
					{
						if ((pos.x + mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) < mpTarget->GetShape().right)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) - (shape.left - mpTarget->GetShape().right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
			}
		}
	}
	else if (mpTarget && IsCollided(mStrongPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			HitTarget(10, 30.0f);

			if (mpTarget->GetHP() <= 0)
			{
				if (mpTarget->GetData()->mIsDead == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDead = true;
				mpTarget->GetData()->mPlayerAct = eActing::Dead;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Dead;
			}
			else
			{

				if (mpTarget->GetData()->mIsDamaged == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDamaged = true;
				mpTarget->GetData()->mPlayerAct = eActing::Damaged;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Damaged;

				if (mpData->mPlayerLookat == eLookat::Right_Lookat)
				{
					if (mpTarget->GetShape().right >= WIN_SIZE_X)
					{
						if ((pos.x + mpData->mHitboxShapeRight[mpData->mPlayerStatus]) > mpTarget->GetShape().left)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeRight[mpData->mPlayerStatus]) - (mpTarget->GetShape().left - shape.right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
				else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
				{
					if (mpTarget->GetShape().left <= 0)
					{
						if ((pos.x + mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) < mpTarget->GetShape().right)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) - (shape.left - mpTarget->GetShape().right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
			}
		}
	}
	else if (mpTarget && IsCollided(mWeakKickHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			HitTarget(8, 30.0f);

			if (mpTarget->GetHP() <= 0)
			{
				if (mpTarget->GetData()->mIsDead == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDead = true;
				mpTarget->GetData()->mPlayerAct = eActing::Dead;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Dead;
			}
			else
			{

				if (mpTarget->GetData()->mIsDamaged == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDamaged = true;
				mpTarget->GetData()->mPlayerAct = eActing::Damaged;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Damaged;

				if (mpData->mPlayerLookat == eLookat::Right_Lookat)
				{
					if (mpTarget->GetShape().right >= WIN_SIZE_X)
					{
						if ((pos.x + mpData->mHitboxShapeRight[mpData->mPlayerStatus]) > mpTarget->GetShape().left)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeRight[mpData->mPlayerStatus]) - (mpTarget->GetShape().left - shape.right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
				else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
				{
					if (mpTarget->GetShape().left <= 0)
					{
						if ((pos.x + mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) < mpTarget->GetShape().right)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) - (shape.left - mpTarget->GetShape().right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
			}
		}
	}
	else if (mpTarget && IsCollided(mStrongKickHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			HitTarget(16, 40.0f);

			if (mpTarget->GetHP() <= 0)
			{
				if (mpTarget->GetData()->mIsDead == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDead = true;
				mpTarget->GetData()->mPlayerAct = eActing::Dead;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Dead;
			}
			else
			{

				if (mpTarget->GetData()->mIsDamaged == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDamaged = true;
				mpTarget->GetData()->mPlayerAct = eActing::Damaged;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Damaged;

				if (mpData->mPlayerLookat == eLookat::Right_Lookat)
				{
					if (mpTarget->GetShape().right >= WIN_SIZE_X)
					{
						if ((pos.x + mpData->mHitboxShapeRight[mpData->mPlayerStatus]) > mpTarget->GetShape().left)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeRight[mpData->mPlayerStatus]) - (mpTarget->GetShape().left - shape.right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
				else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
				{
					if (mpTarget->GetShape().left <= 0)
					{
						if ((pos.x + mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) < mpTarget->GetShape().right)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) - (shape.left - mpTarget->GetShape().right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
			}
		}
	}
	else if (mpTarget && IsCollided(mNearWeakPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			HitTarget(5, 20.0f);

			if (mpTarget->GetHP() <= 0)
			{
				if (mpTarget->GetData()->mIsDead == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDead = true;
				mpTarget->GetData()->mPlayerAct = eActing::Dead;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Dead;
			}
			else
			{

				if (mpTarget->GetData()->mIsDamaged == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDamaged = true;
				mpTarget->GetData()->mPlayerAct = eActing::Damaged;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Damaged;

				if (mpData->mPlayerLookat == eLookat::Right_Lookat)
				{
					if (mpTarget->GetShape().right >= WIN_SIZE_X)
					{
						if ((pos.x + mpData->mHitboxShapeRight[mpData->mPlayerStatus]) > mpTarget->GetShape().left)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeRight[mpData->mPlayerStatus]) - (mpTarget->GetShape().left - shape.right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
				else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
				{
					if (mpTarget->GetShape().left <= 0)
					{
						if ((pos.x + mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) < mpTarget->GetShape().right)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) - (shape.left - mpTarget->GetShape().right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
			}
		}
	}
	else if (mpTarget && IsCollided(mNearStrongPunchHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			HitTarget(10, 30.0f);

			if (mpTarget->GetHP() <= 0)
			{
				if (mpTarget->GetData()->mIsDead == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDead = true;
				mpTarget->GetData()->mPlayerAct = eActing::Dead;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Dead;
			}
			else
			{

				if (mpTarget->GetData()->mIsDamaged == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDamaged = true;
				mpTarget->GetData()->mPlayerAct = eActing::Damaged;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Damaged;

				if (mpData->mPlayerLookat == eLookat::Right_Lookat)
				{
					if (mpTarget->GetShape().right >= WIN_SIZE_X)
					{
						if ((pos.x + mpData->mHitboxShapeRight[mpData->mPlayerStatus]) > mpTarget->GetShape().left)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeRight[mpData->mPlayerStatus]) - (mpTarget->GetShape().left - shape.right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
				else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
				{
					if (mpTarget->GetShape().left <= 0)
					{
						if ((pos.x + mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) < mpTarget->GetShape().right)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) - (shape.left - mpTarget->GetShape().right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
			}
		}
	}
	else if (mpTarget && IsCollided(mNearWeakKickHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			HitTarget(8, 40.0f);

			if (mpTarget->GetHP() <= 0)
			{
				if (mpTarget->GetData()->mIsDead == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDead = true;
				mpTarget->GetData()->mPlayerAct = eActing::Dead;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Dead;
			}
			else
			{

				if (mpTarget->GetData()->mIsDamaged == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDamaged = true;
				mpTarget->GetData()->mPlayerAct = eActing::Damaged;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Damaged;

				if (mpData->mPlayerLookat == eLookat::Right_Lookat)
				{
					if (mpTarget->GetShape().right >= WIN_SIZE_X)
					{
						if ((pos.x + mpData->mHitboxShapeRight[mpData->mPlayerStatus]) > mpTarget->GetShape().left)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeRight[mpData->mPlayerStatus]) - (mpTarget->GetShape().left - shape.right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
				else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
				{
					if (mpTarget->GetShape().left <= 0)
					{
						if ((pos.x + mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) < mpTarget->GetShape().right)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) - (shape.left - mpTarget->GetShape().right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
			}
		}
	}
	else if (mpTarget && IsCollided(mNearStrongKickHitBox, mpTarget->GetShape()))
	{
		if (!CheckHitChar())
		{
			HitTarget(16, 40.0f);

			if (mpTarget->GetHP() <= 0)
			{
				if (mpTarget->GetData()->mIsDead == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDead = true;
				mpTarget->GetData()->mPlayerAct = eActing::Dead;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Dead;
			}
			else
			{

				if (mpTarget->GetData()->mIsDamaged == false)
				{
					mpTarget->SetFrameX(0);
				}

				mpTarget->GetData()->mIsDamaged = true;
				mpTarget->GetData()->mPlayerAct = eActing::Damaged;
				mpTarget->GetData()->mPlayerStatus = eAnimStatus::Damaged;

				if (mpData->mPlayerLookat == eLookat::Right_Lookat)
				{
					if (mpTarget->GetShape().right >= WIN_SIZE_X)
					{
						if ((pos.x + mpData->mHitboxShapeRight[mpData->mPlayerStatus]) > mpTarget->GetShape().left)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeRight[mpData->mPlayerStatus]) - (mpTarget->GetShape().left - shape.right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
				else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
				{
					if (mpTarget->GetShape().left <= 0)
					{
						if ((pos.x + mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) < mpTarget->GetShape().right)
						{
							mAcceleration = CalculationAcceleration((float)((abs(mpData->mHitboxShapeLeft[mpData->mPlayerStatus]) - (shape.left - mpTarget->GetShape().right)) / 2));
							mResistance = mAcceleration / 15;
						}

						mbNotMove = true;

					}
				}
			}
		}
	}

	if (mpData->mPlayerAct == eActing::Dead)
	{
		ImgUpdate(mpData->mPlayerStatus);
		mElapsedCount++;
		if (mElapsedCount >= 1)
		{
			mFrameX++;

			if (mFrameX >= (int)mpData->mAnimframe[mpData->mPlayerStatus])
			{
				mFrameX = (int)mpData->mAnimframe[mpData->mPlayerStatus] - 1;
				mpData->mIsDead = false;
			}
			mElapsedCount = 0;
		}
	}
	else if (mpData->mPlayerAct == eActing::Damaged)
	{
		ImgUpdate(mpData->mPlayerStatus);
		mElapsedCount++;
		if (mElapsedCount >= 8)
		{
			mFrameX++;

			if (mFrameX >= (int)mpData->mAnimframe[mpData->mPlayerStatus])
			{
				mFrameX = 0;
				mpData->mIsDamaged = false;
				mpData->mPlayerAct = eActing::Act_Idle;
				mpData->mPlayerStatus = eAnimStatus::Idle;
			}
			mElapsedCount = 0;
		}
	}
	else if (mpData->mPlayerAct == eActing::Act_Attack)
	{
		if (mpData->mPlayerStatus == eAnimStatus::Weak_Punch)
		{
			ImgUpdate(mpData->mPlayerStatus);
			mElapsedCount++;
			if (mElapsedCount >= 4)
			{
				mFrameX++;

				if (mFrameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
				{
					OnWeakPunchHitBox((int)mpData->mPlayerLookat, mpData);
				}
				else if (mFrameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
				{
					OffWeakPunchHitBox();
				}

				if (mFrameX >= (int)mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 1;
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

				if (mFrameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
				{
					OnWeakKickHitBox((int)mpData->mPlayerLookat, mpData);
				}
				else if (mFrameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
				{
					OffWeakKickHitBox();
				}

				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 1;
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

				if (mFrameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
				{
					OnStrongPunchHitBox((int)mpData->mPlayerLookat, mpData);
				}
				else if (mFrameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
				{
					OffStrongPunchHitBox();
				}

				if (mFrameX >= (int)mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 1;
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

				if (mFrameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
				{
					OnStrongKickHitBox((int)mpData->mPlayerLookat, mpData);
				}
				else if (mFrameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
				{
					OffStrongKickHitBox();
				}

				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 1;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = eActing::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				mElapsedCount = 0;
			}
		}
		else if (mpData->mPlayerStatus == eAnimStatus::Near_Weak_Punch)
		{
			ImgUpdate(mpData->mPlayerStatus);
			mElapsedCount++;
			if (mElapsedCount >= 4)
			{
				mFrameX++;

				if (mFrameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
				{
					OnNearWeakPunchHitBox((int)mpData->mPlayerLookat, mpData);
				}
				else if (mFrameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
				{
					OffNearWeakPunchHitBox();
				}

				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 1;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = eActing::Act_Idle;
				}
				mElapsedCount = 0;
			}
		}
		else if (mpData->mPlayerStatus == eAnimStatus::Near_Strong_Punch)
		{
			ImgUpdate(mpData->mPlayerStatus);
			mElapsedCount++;
			if (mElapsedCount >= 4)
			{
				mFrameX++;

				if (mFrameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
				{
					OnNearStrongPunchHitBox((int)mpData->mPlayerLookat, mpData);
				}
				else if (mFrameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
				{
					OffNearStrongPunchHitBox();
				}

				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 1;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = eActing::Act_Idle;
				}
				mElapsedCount = 0;
			}
		}
		else if (mpData->mPlayerStatus == eAnimStatus::Near_Weak_Kick)
		{
			ImgUpdate(mpData->mPlayerStatus);
			mElapsedCount++;
			if (mElapsedCount >= 4)
			{
				mFrameX++;

				if (mFrameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
				{
					OnNearWeakKickHitBox((int)mpData->mPlayerLookat, mpData);
					cout << mNearWeakKickHitBox.right << endl;
					cout << shape.right << endl;
				}
				else if (mFrameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
				{
					OffNearWeakKickHitBox();
				}

				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 1;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = eActing::Act_Idle;
				}
				mElapsedCount = 0;
			}
		}
		else if (mpData->mPlayerStatus == eAnimStatus::Near_Strong_Kick)
		{
			ImgUpdate(mpData->mPlayerStatus);
			mElapsedCount++;
			if (mElapsedCount >= 4)
			{
				mFrameX++;

				if (mFrameX == (int)mpData->mHitboxOnFrame[mpData->mPlayerStatus])
				{
					OnNearStrongKickHitBox((int)mpData->mPlayerLookat, mpData);
				}
				else if (mFrameX == mpData->mHitboxOffFrame[mpData->mPlayerStatus])
				{
					OffNearStrongKickHitBox();
				}

				if (mFrameX >= mpData->mAnimframe[mpData->mPlayerStatus])
				{
					mFrameX = 1;
					mpData->mIsAttack = false;
					mpData->mPlayerAct = eActing::Act_Idle;
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

					if (!mbNotMove)
					{
						pos.x -= moveSpeed;
					}

					mbNotMove = false;
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

					if (!mbNotMove)
					{
						pos.x += moveSpeed;
					}

					mbNotMove = false;
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

	if (mbIsHit || mAcceleration > 0)
	{
		if (mpData->mPlayerLookat == eLookat::Left_Lookat)
		{
			if (mAcceleration > 0)
			{
				pos.x += mAcceleration;
				mAcceleration -= mResistance;
				mResistance += mResistance;
			}
			else
			{
				mbIsHit = false;
				mResistance = 0;
				mAcceleration = 0;
			}
		}
		else
		{
			if (mAcceleration > 0)
			{
				pos.x -= mAcceleration;
				mAcceleration -= mResistance;
				mResistance += mResistance;
			}
			else
			{
				mbIsHit = false;
				mResistance = 0;
				mAcceleration = 0;
			}
		}
	}

	SetShape();

	// �������� �̵����� �� �浹�� �ִٸ�
	if (mpData->mPlayerAct == eActing::Act_Left_Move)
	{
		if (shape.left < 0)
		{
			pos.x -= shape.left;

			SetShape();
		}
		else if (IsCollided(shape, mpTarget->GetShape()))
		{
			pos.x += mpTarget->GetShape().right - shape.left;

			SetShape();
		}
	}

	// ���������� �̵����� �� �浹�� �ִٸ�
	if (mpData->mPlayerAct == eActing::Act_Right_Move)
	{
		if (shape.right > WIN_SIZE_X)
		{
			pos.x += WIN_SIZE_X - shape.right;

			SetShape();
		}
		else if (IsCollided(shape, mpTarget->GetShape()))
		{
			pos.x += mpTarget->GetShape().left - shape.right;

			SetShape();
		}
	}

	// �˹��ϰ� ĳ���Ͱ� �浹�ϰ��ִٸ�
	if (mpData->mPlayerLookat == eLookat::Right_Lookat)
	{
		if (shape.left < 0)
		{
			pos.x -= shape.left;
			SetShape();
		}

		if (IsCollided(shape, mpTarget->GetShape()))
		{
			pos.x -= shape.right - mpTarget->GetShape().left;
			SetShape();
		}
	}
	else
	{
		if (shape.right > WIN_SIZE_X)
		{
			pos.x -= shape.right - WIN_SIZE_X;
			SetShape();
		}

		if (IsCollided(shape, mpTarget->GetShape()))
		{
			pos.x += mpTarget->GetShape().right - shape.left;
			SetShape();
		}
	}
	
	//	// �� ĳ���Ͱ� �پ� �ְ�, ��� ĳ���Ͱ� ȭ��󿡼� ���� �پ��ְų� �ٰԵɽ� ���� ĳ���Ͱ� �����Ҷ� ���� ĳ���Ͱ� �ڷ� �з����� ����
	//	if (mpData->mPlayerLookat == eLookat::Right_Lookat)
	//	{
	//		if (mpTarget->GetShape().right == WIN_SIZE_X)
	//		{
	//			if (((unsigned int)shape.right - (unsigned int)mpTarget->GetShape().left) < mpData->mHitboxShapeRight[mpData->mPlayerStatus])
	//			{
	//				// �˹����� �ҷ������
	//				// �˹��� ����� Ÿ�� ĳ���Ͱ� �ƴ� mpData�� ĳ���ͷ� �����ϸ��
	//				// �̰������� �˹��� �ִ� ���ϴ� ����
	//				// ���� ĳ������ ���ݹ�Ŀ� �ش��ϴ� Ÿ�� ��Ʈ�ڽ��� right �� - ((�ڿ���)'Ÿ��ĳ������ left ���ٰ�'- (�ڿ���)'�����ϴ� ĳ������ right ���ٰ�')
	//			}
	//		}
	//	}
	//	else if (mpData->mPlayerLookat == eLookat::Left_Lookat)
	//	{
	//		if (mpTarget->GetShape().left == 0)
	//		{
	//			if (((unsigned int)shape.left - (unsigned int)mpTarget->GetShape().right) < mpData->mHitboxShapeRight[mpData->mPlayerStatus])
	//			{
	//				// �˹����� �ҷ������
	//				// �˹��� ����� Ÿ�� ĳ���Ͱ� �ƴ� mpData�� ĳ���ͷ� �����ϸ��
	//				// �̰������� �˹��� �ִ� ���ϴ� ����
	//				// ���� ĳ������ ���ݹ�Ŀ� �ش��ϴ� Ÿ�� ��Ʈ�ڽ��� left �� - ((�ڿ���)'Ÿ��ĳ������ right ���ٰ�'- (�ڿ���)'�����ϴ� ĳ������ left ���ٰ�')
	//			}
	//		}
	//	}
}

void ChAnimation::Render(HDC hdc)
{
	if (mbPrintHitBox)
	{
		Rectangle(hdc, shape.left, shape.top, shape.right, shape.bottom);
		Rectangle(hdc, mWeakPunchHitBox.left, mWeakPunchHitBox.top, mWeakPunchHitBox.right, mWeakPunchHitBox.bottom);
		Rectangle(hdc, mStrongPunchHitBox.left, mStrongPunchHitBox.top, mStrongPunchHitBox.right, mStrongPunchHitBox.bottom);
		Rectangle(hdc, mWeakKickHitBox.left, mWeakKickHitBox.top, mWeakKickHitBox.right, mWeakKickHitBox.bottom);
		Rectangle(hdc, mStrongKickHitBox.left, mStrongKickHitBox.top, mStrongKickHitBox.right, mStrongKickHitBox.bottom);
		Rectangle(hdc, mNearWeakPunchHitBox.left, mNearWeakPunchHitBox.top, mNearWeakPunchHitBox.right, mNearWeakPunchHitBox.bottom);
		Rectangle(hdc, mNearWeakKickHitBox.left, mNearWeakKickHitBox.top, mNearWeakKickHitBox.right, mNearWeakKickHitBox.bottom);
		Rectangle(hdc, mNearStrongPunchHitBox.left, mNearStrongPunchHitBox.top, mNearStrongPunchHitBox.right, mNearStrongPunchHitBox.bottom);
		Rectangle(hdc, mNearStrongKickHitBox.left, mNearStrongKickHitBox.top, mNearStrongKickHitBox.right, mNearStrongKickHitBox.bottom);
	}

	if (img)
	{
		MGR_IMG->GetImage((eImageTag)((int)mpData->mPlayerStatus + (int)mpData->mPlayerLookat + (int)mpData->mCharTag))->Render(hdc, (int)pos.x, (int)pos.y, mFrameX, mFrameY, mpData->mPlayerLookat);
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

void ChAnimation::Damaged(eAnimStatus type)
{
	if (mpData->mPlayerStatus != type)
	{
		mFrameX = 0;
	}
	mpData->mIsDamaged = true;
	mpData->mPlayerAct = eActing::Damaged;
	mpData->mPlayerStatus = type;
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

void ChAnimation::HitTarget(int damage, float acceleration)
{
	mHitChar.push_back(mpTarget);
	mpTarget->SetHP(damage);

	mpTarget->SetIsHit(true);
	mpTarget->SetAcceleration(acceleration);
	mpTarget->SetResistance(acceleration / 15);

	cout << "HP - " << damage << " ��� ���� ü�� : " << mpTarget->GetHP() << endl;
}