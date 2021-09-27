#include "LeonaAnimation.h"
#include "Image.h"
#include "KeyManager.h"
#include "ChAnimData.h"

using namespace std;

void LeonaAnimation::Init(eLookat dir)
{
	mpData = new ChAnimData;

	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Idle, "Image/Leona_Database_IMG/Leona_Idle.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Move_Forward, "Image/Leona_Database_IMG/Leona_Walk_Front.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Move_Backward, "Image/Leona_Database_IMG/Leona_Walk_Back.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Damaged, "Image/Leona_Database_IMG/Leona_Damaged.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Dead, "Image/Leona_Database_IMG/Leona_Dead.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Weak_Punch, "Image/Leona_Database_IMG/Leona_Weak_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Weak_Kick, "Image/Leona_Database_IMG/Leona_Weak_Kick.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Strong_Punch, "Image/Leona_Database_IMG/Leona_Strong_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Strong_Kick, "Image/Leona_Database_IMG/Leona_Strong_Kick.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Weak_Punch, "Image/Leona_Database_IMG/Leona_Near_Weak_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Weak_Kick, "Image/Leona_Database_IMG/Leona_Near_Weak_Kick.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Strong_Punch, "Image/Leona_Database_IMG/Leona_Near_Strong_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Strong_Kick, "Image/Leona_Database_IMG/Leona_Near_Strong_Kick.bmp"));

	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 46));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 10));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 8));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 3));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Dead, 20));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 5));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 8));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 11));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 14));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 4));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 5));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 12));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 9));

	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 3680));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 800));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 640));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 300));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Dead, 2480));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 1400));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 2240));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 3080));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 3920));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 680));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 850));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 2040));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 1530));

	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 140));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Dead, 190));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 140));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 140));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 140));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 140));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 170));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 170));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 170));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 170));

	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 324));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 148));

	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 8));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 7));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 7));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 0));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 4));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, -280));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 280));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, -100));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, -60));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 2));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 3));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, -312));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 312));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, -160));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, -80));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 3));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 5));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, -320));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 320));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, -120));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, -40));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 4));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 6));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, -540));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 540));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, -160));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, -60));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 6));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 8));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, -392));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 392));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, -100));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 0));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 4));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 8));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, -392));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 392));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, -100));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 0));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 4));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 8));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, -392));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 392));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, -100));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 0));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 4));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 8));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, -392));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 392));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, -100));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 0));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 4));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 8));

	mpData->mNotReverse = 1;

	mpData->mPlayerAct = eActing::Act_Idle;
	mpData->mPlayerStatus = eAnimStatus::Idle;
	mpData->mPlayerLookat = dir;
	mpData->mIsDamaged = false;

	//Player.selectedCharacter = ralf

	img = new Image;

	//"Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"
	//Waystring = PlayerCharacter1.Import_Image(PlayerCharacter1.m_Setcharacter,PlayerCharacter1.m_Player.playerStatus);

	//img->Init(mpData->mPath[mpData->mPlayerStatus], (int)mpData->mSizeX[mpData->mPlayerStatus], (int)mpData->mSizeY[mpData->mPlayerStatus],
	//	(int)mpData->mAnimframe[mpData->mPlayerStatus], 1, true, RGB(255, 0, 255));

	ImgUpdate(mpData->mPlayerStatus);

	//img->Init(Player.mpData->mPath[playerStatus], (int)Player.mpData->sizeX[playerStatus], (int)Player.mpData->sizeY[playerStatus],
	//	(int)Player.mpData->Animframe[playerStatus], 1, true, RGB(255, 0, 255));

	mFrameX = mFrameY = 0;
	mElapsedCount = 0;
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	moveSpeed = 50.0f;

	mHP = 100;

	shape.left = (int)pos.x - ((mpData->mSizeX[mpData->mPlayerStatus] / mpData->mAnimframe[mpData->mPlayerStatus]) / 2);
	shape.top = (int)pos.y - (mpData->mSizeX[mpData->mPlayerStatus] / 2);
	shape.right = (int)pos.x + ((mpData->mSizeX[mpData->mPlayerStatus] / mpData->mAnimframe[mpData->mPlayerStatus]) / 2);
	shape.bottom = (int)pos.y + (mpData->mSizeX[mpData->mPlayerStatus] / 2);
}