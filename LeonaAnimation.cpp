#include "LeonaAnimation.h"
#include "Image.h"
#include "KeyManager.h"
#include "ChAnimData.h"
using namespace std;

void LeonaAnimation::Init()
{

	mData = new ChAnimData;


	mData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Idle, "Image/Leona_Database_IMG/Leona_Idle.bmp"));
	mData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Move_Front, "Image/Leona_Database_IMG/Leona_Walk_Front.bmp"));
	mData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Move_Backward, "Image/Leona_Database_IMG/Leona_Walk_Back.bmp"));
	mData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Damaged, "Image/Leona_Database_IMG/Leona_Damaged.bmp"));
	mData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Weak_Punch, "Image/Leona_Database_IMG/Leona_Weak_Punch.bmp"));
	mData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Weak_Kick, "Image/Leona_Database_IMG/Leona_Weak_kick.bmp"));
	mData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Strong_Punch, "Image/Leona_Database_IMG/Leona_Strong_Punch.bmp"));
	mData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Strong_Kick, "Image/Leona_Database_IMG/Leona_Strong_kick.bmp"));

	mData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Idle, 46));
	mData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Move_Front, 10));
	mData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 8));
	mData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 4));
	mData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 5));
	mData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 8));
	mData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 11));
	mData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 14));

	mData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Idle, 3680));
	mData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Move_Front, 800));
	mData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 640));
	mData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 568));
	mData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 1400));
	mData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 2240));
	mData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 3080));
	mData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 3920));

	mData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Idle, 120));
	mData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Move_Front, 120));
	mData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 140));
	mData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 140));
	mData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 140));
	mData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 140));
	mData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 140));
	mData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 140));

	mData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Idle, 0));
	mData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Move_Front, 0));
	mData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 0));
	mData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 0));
	mData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 0));
	mData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 0));
	mData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 81));
	mData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 37));

	mData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Idle, 8));
	mData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Move_Front, 7));
	mData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 7));
	mData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 0));
	mData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 4));
	mData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 4));
	mData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 4));
	mData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 4));

	mData->mNotReverse = 1;

	mData->mPlayerAct = Acting::Act_Idle;
	mData->mPlayerStatus = AnimStatus::Idle;
	mData->mPlayerLookat = Lookat::Left_Lookat;

	//Player.selectedCharacter = ralf

	img = new Image;

	//"Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"
	//Waystring = PlayerCharacter1.Import_Image(PlayerCharacter1.m_Setcharacter,PlayerCharacter1.m_Player.playerStatus);

	img->Init(mData->mPath[mData->mPlayerStatus], (int)mData->mSizeX[mData->mPlayerStatus], (int)mData->mSizeY[mData->mPlayerStatus],
		(int)mData->mAnimframe[mData->mPlayerStatus], 1, true, RGB(255, 0, 255));

	//img->Init(Player.mData->mPath[playerStatus], (int)Player.mData->sizeX[playerStatus], (int)Player.mData->sizeY[playerStatus],
	//	(int)Player.mData->Animframe[playerStatus], 1, true, RGB(255, 0, 255));

	frameX = frameY = 0;
	elapsedCount = 0;
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	moveSpeed = 10.0f;

	mHP = 100;

	shape.left = (int)pos.x - ((mData->mSizeX[mData->mPlayerStatus] / mData->mAnimframe[mData->mPlayerStatus]) / 2);
	shape.top = (int)pos.y - (mData->mSizeX[mData->mPlayerStatus] / 2);
	shape.right = (int)pos.x + ((mData->mSizeX[mData->mPlayerStatus] / mData->mAnimframe[mData->mPlayerStatus]) / 2);
	shape.bottom = (int)pos.y + (mData->mSizeX[mData->mPlayerStatus] / 2);
}

void LeonaAnimation::ImgUpdate(AnimStatus playerStatus)
{
	img->Release();
	img->Init(mData->mPath[mData->mPlayerStatus], (int)mData->mSizeX[mData->mPlayerStatus], (int)mData->mSizeY[mData->mPlayerStatus],
		(int)mData->mAnimframe[mData->mPlayerStatus], 1, true, RGB(255, 0, 255));
}

void LeonaAnimation::Update()
{
	if (mData->mIsAttack == false)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown('Z'))
		{
			//mData->mPlayerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (mData->mPlayerStatus != AnimStatus::Weak_Punch)
			{
				frameX = 0;
			}
			mData->mIsAttack = true;
			mData->mPlayerAct = Acting::Act_Attack;
			mData->mPlayerStatus = AnimStatus::Weak_Punch;

		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('X'))
		{
			//mData->mPlayerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (mData->mPlayerStatus != AnimStatus::Strong_Punch)
			{
				frameX = 0;
			}
			mData->mIsAttack = true;
			mData->mPlayerAct = Acting::Act_Attack;
			mData->mPlayerStatus = AnimStatus::Strong_Punch;

		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('C'))
		{
			//mData->mPlayerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (mData->mPlayerStatus != AnimStatus::Weak_Kick)
			{
				frameX = 0;
			}
			mData->mIsAttack = true;
			mData->mPlayerAct = Acting::Act_Attack;
			mData->mPlayerStatus = AnimStatus::Weak_Kick;

		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('V'))
		{
			//mData->mPlayerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (mData->mPlayerStatus != AnimStatus::Strong_Kick)
			{
				frameX = 0;
			}
			mData->mIsAttack = true;
			mData->mPlayerAct = Acting::Act_Attack;
			mData->mPlayerStatus = AnimStatus::Strong_Kick;

		}
	}

	if (mData->mPlayerAct != Acting::Act_Attack)
	{
		if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
		{
			//mData->mPlayerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함

			if (mData->mPlayerAct != Acting::Act_Left_Move)
			{
				frameX = 0;
			}

			if (mData->mPlayerLookat == Lookat::Left_Lookat)
			{
				mData->mPlayerStatus = AnimStatus::Move_Front;
			}
			else if (mData->mPlayerLookat == Lookat::Right_Lookat)
			{
				mData->mPlayerStatus = AnimStatus::Move_Backward;
			}

			mData->mPlayerAct = Acting::Act_Left_Move;
		}
		else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
		{
			//mData->mPlayerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (mData->mPlayerAct != Acting::Act_Right_Move)
			{
				frameX = 0;
			}
			mData->mPlayerAct = Acting::Act_Right_Move;

			if (mData->mPlayerLookat == Lookat::Left_Lookat)
			{
				mData->mPlayerStatus = AnimStatus::Move_Backward;
			}
			else if (mData->mPlayerLookat == Lookat::Right_Lookat)
			{
				mData->mPlayerStatus = AnimStatus::Move_Front;
			}
		}
		else
		{
			//mData->mPlayerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (mData->mPlayerAct != Acting::Act_Idle)
			{
				frameX = 0;
			}
			mData->mPlayerAct = Acting::Act_Idle;
			mData->mPlayerStatus = AnimStatus::Idle;
		}
	}

	if (mData->mPlayerAct == Acting::Act_Attack)
	{
		if (mData->mPlayerStatus == AnimStatus::Weak_Punch)
		{
			ImgUpdate(mData->mPlayerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;

				if (frameX == 2)
				{
					OnWeakPunchHitBox((int)mData->mPlayerLookat);
				}
				else if (frameX == 3)
				{
					OffWeakPunchHitBox();
				}

				if (frameX >= mData->mAnimframe[mData->mPlayerStatus])
				{
					frameX = 0;
					mData->mIsAttack = false;
					mData->mPlayerAct = Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (mData->mPlayerStatus == AnimStatus::Strong_Punch)
		{
			ImgUpdate(mData->mPlayerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;

				if (frameX == 4)
				{
					OnStrongPunchHitBox((int)mData->mPlayerLookat);
				}
				else if (frameX == 9)
				{
					OffStrongPunchHitBox();
				}

				if (frameX >= mData->mAnimframe[mData->mPlayerStatus])
				{
					frameX = 0;
					mData->mIsAttack = false;
					mData->mPlayerAct = Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (mData->mPlayerStatus == AnimStatus::Weak_Kick)
		{
			ImgUpdate(mData->mPlayerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;

				if (frameX == 3)
				{
					OnWeakKickHitBox((int)mData->mPlayerLookat);
				}
				else if (frameX == 5)
				{
					OffWeakKickHitBox();
				}

				if (frameX >= mData->mAnimframe[mData->mPlayerStatus])
				{
					frameX = 0;
					mData->mIsAttack = false;
					mData->mPlayerAct = Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (mData->mPlayerStatus == AnimStatus::Strong_Kick)
		{
			ImgUpdate(mData->mPlayerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;


				if (frameX == 5)
				{
					OnStrongKickHitBox((int)mData->mPlayerLookat);
				}
				else if (frameX == 8)
				{
					OffStrongKickHitBox();
				}

				if (frameX >= mData->mAnimframe[mData->mPlayerStatus])
				{
					frameX = 0;
					mData->mIsAttack = false;
					mData->mPlayerAct = Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
	}

	else if (mData->mPlayerAct != Acting::Act_Attack) // 공격상태에서는 Idle과 Move가 작동하면 안되므로 공격상태인지 아닌지 판별
	{
		if (mData->mPlayerStatus == AnimStatus::Move_Front || mData->mPlayerStatus == AnimStatus::Move_Backward) //Move일때
		{
			// 왼쪽으로 움직이기
			if (mData->mPlayerAct == Acting::Act_Left_Move)
			{
				ImgUpdate(mData->mPlayerStatus);
				elapsedCount++;
				if (elapsedCount >= 8)
				{
					if (mData->mPlayerLookat == Lookat::Right_Lookat)
					{
						if (mData->mNotReverse == 1)
						{
							frameX++;
							if (frameX >= mData->mAnimframe[mData->mPlayerStatus] - 1)
							{
								frameX = 0;
							}
						}
						else
						{
							frameX--;
							if (frameX < 0)
							{
								frameX = mData->mAnimframe[mData->mPlayerStatus] - 1;
							}
						}
					}
					else if (mData->mPlayerLookat == Lookat::Left_Lookat)
					{
						frameX++;
						if (frameX >= mData->mAnimframe[mData->mPlayerStatus] - 1)
						{
							frameX = 0;
						}
					}
					pos.x -= moveSpeed;
					elapsedCount = 0;
				}

			}
			// 오른쪽으로 움직이기
			else if (mData->mPlayerAct == Acting::Act_Right_Move)
			{
				ImgUpdate(mData->mPlayerStatus);

				elapsedCount++;
				if (elapsedCount >= 8)//(int)AnimSpeed[mData->mPlayerStatus])
				{
					if (mData->mPlayerLookat == Lookat::Right_Lookat)
					{
						frameX++;
						if (frameX >= mData->mAnimframe[mData->mPlayerStatus] - 1)
						{
							frameX = 0;
						}
					}
					else if (mData->mPlayerLookat == Lookat::Left_Lookat)
					{
						if (mData->mNotReverse == 1)
						{
							frameX++;
							if (frameX >= mData->mAnimframe[mData->mPlayerStatus] - 1)
							{
								frameX = 0;
							}
						}
						else
						{
							frameX--;
							if (frameX < 0)
							{
								frameX = mData->mAnimframe[mData->mPlayerStatus] - 1;
							}
						}
					}
					pos.x += moveSpeed;
					elapsedCount = 0;
				}
			}
		}

		else if (mData->mPlayerAct == Acting::Act_Idle) // Idle 일때
		{
			ImgUpdate(mData->mPlayerStatus);

			elapsedCount++;
			if (elapsedCount >= 8)
			{
				frameX++;
				if (frameX >= mData->mAnimframe[mData->mPlayerStatus])
				{
					frameX = 0;
				}
				elapsedCount = 0;
			}
		}
	}

	baseX = mData->mSizeX[mData->mPlayerStatus] / (int)mData->mAnimframe[AnimStatus::Idle];
	baseY = (int)mData->mSizeY[AnimStatus::Idle];

	shape.left = (int)pos.x - ((mData->mSizeX[AnimStatus::Idle] / mData->mAnimframe[AnimStatus::Idle]) / 2);
	shape.top = (int)pos.y - (mData->mSizeY[AnimStatus::Idle] / 2);
	shape.right = (int)pos.x + ((mData->mSizeX[AnimStatus::Idle] / mData->mAnimframe[AnimStatus::Idle]) / 2);
	shape.bottom = (int)pos.y + (mData->mSizeY[AnimStatus::Idle] / 2);

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

void LeonaAnimation::Render(HDC hdc)
{
	Rectangle(hdc, shape.left, shape.top, shape.right, shape.bottom);

	Rectangle(hdc, mWeakPunchHitBox.left, mWeakPunchHitBox.top, mWeakPunchHitBox.right, mWeakPunchHitBox.bottom);
	Rectangle(hdc, mStrongPunchHitBox.left, mStrongPunchHitBox.top, mStrongPunchHitBox.right, mStrongPunchHitBox.bottom);
	Rectangle(hdc, mWeakKickHitBox.left, mWeakKickHitBox.top, mWeakKickHitBox.right, mWeakKickHitBox.bottom);
	Rectangle(hdc, mStrongKickHitBox.left, mStrongKickHitBox.top, mStrongKickHitBox.right, mStrongKickHitBox.bottom);

	if (img)
	{
		img->Render(hdc, pos.x, pos.y, frameX, frameY, baseX, baseY, mData->mPlayerStatus, mData->mPlayerLookat);
	}
}

void LeonaAnimation::Release()
{
	if (img)
	{
		delete img;
		img = nullptr;
	}
}

FLOAT LeonaAnimation::moveAfterAction(FLOAT pos)
{
	if (mData->mPlayerLookat == Lookat::Right_Lookat)
	{
		pos = pos + (FLOAT)(mData->mMoveAfteraction[mData->mPlayerStatus]);
	}
	else if (mData->mPlayerLookat == Lookat::Left_Lookat)
	{
		pos = pos - (FLOAT)(mData->mMoveAfteraction[mData->mPlayerStatus]);;
	}
	return pos;
}
