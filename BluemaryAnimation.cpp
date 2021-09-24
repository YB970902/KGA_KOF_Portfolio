#include "BluemaryAnimation.h"
#include "ChAnimData.h"
#include "Image.h"
#include "KeyManager.h"

using namespace std;

void BluemaryAnimation::Init(eLookat dir)
{
	mpData = new ChAnimData;

	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Idle, "Image/Bluemary_Database_IMG/Bluemary_Idle.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Move_Forward, "Image/Bluemary_Database_IMG/Bluemary_Walk_Front.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Move_Backward, "Image/Bluemary_Database_IMG/Bluemary_Walk_Back.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Damaged, "Image/Bluemary_Database_IMG/Bluemary_Damaged.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Weak_Punch, "Image/Bluemary_Database_IMG/Bluemary_Weak_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Weak_Kick, "Image/Bluemary_Database_IMG/Bluemary_Weak_kick.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Strong_Punch, "Image/Bluemary_Database_IMG/Bluemary_Strong_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Strong_Kick, "Image/Bluemary_Database_IMG/Bluemary_Strong_kick.bmp"));

	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 12));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 10));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 6));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 4));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 4));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 9));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 22));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 12));

	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 720));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 600));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 360));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 568));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 400));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 1080));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 4840));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 2160));

	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 100));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 100));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 130));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 120));

	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 22));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 24));

	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 8));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 6));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 8));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 0));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 4));

	mpData->mHitboxShapeLeft.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, -50));
	mpData->mHitboxShapeRight.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 50));
	mpData->mHitboxShapeTop.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, -35));
	mpData->mHitboxShapeBottom.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, -25));
	mpData->mHitboxOnFrame.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 2));
	mpData->mHitboxOffFrame.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 3));

	mpData->mHitboxShapeLeft.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, -60));
	mpData->mHitboxShapeRight.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 60));
	mpData->mHitboxShapeTop.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, -30));
	mpData->mHitboxShapeBottom.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, -10));
	mpData->mHitboxOnFrame.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 4));
	mpData->mHitboxOffFrame.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 6));

	mpData->mHitboxShapeLeft.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, -105));
	mpData->mHitboxShapeRight.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 105));
	mpData->mHitboxShapeTop.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, -30));
	mpData->mHitboxShapeBottom.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, -10));
	mpData->mHitboxOnFrame.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 9));
	mpData->mHitboxOffFrame.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 14));

	mpData->mHitboxShapeLeft.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, -85));
	mpData->mHitboxShapeRight.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 85));
	mpData->mHitboxShapeTop.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, -25));
	mpData->mHitboxShapeBottom.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 0));
	mpData->mHitboxOnFrame.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 4));
	mpData->mHitboxOffFrame.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 6));

	mpData->mNotReverse = 1;

	mpData->mPlayerAct = eActing::Act_Idle;
	mpData->mPlayerStatus = eAnimStatus::Idle;
	mpData->mPlayerLookat = dir;

	//selectedCharacter = ralf

	img = new Image;

	//"Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"
	//Waystring = PlayerCharacter1.Import_Image(PlayerCharacter1.m_Setcharacter,PlayerCharacter1.m_Player.playerStatus);

	img->Init(mpData->mPath[mpData->mPlayerStatus], (int)mpData->mSizeX[mpData->mPlayerStatus], (int)mpData->mSizeY[mpData->mPlayerStatus],
		(int)mpData->mAnimframe[mpData->mPlayerStatus], 1, true, RGB(255, 0, 255));

	//img->Init(Player.mpData->mPath[playerStatus], (int)Player.mpData->sizeX[playerStatus], (int)Player.mpData->sizeY[playerStatus],
	//	(int)Player.mpData->Animframe[playerStatus], 1, true, RGB(255, 0, 255));

	mFrameX = mFrameY = 0;
	mElapsedCount = 0;
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	moveSpeed = 10.0f;

	mHP = 100;

	shape.left = (int)pos.x - ((mpData->mSizeX[mpData->mPlayerStatus] / mpData->mAnimframe[mpData->mPlayerStatus]) / 2);
	shape.top = (int)pos.y - (mpData->mSizeX[mpData->mPlayerStatus] / 2);
	shape.right = (int)pos.x + ((mpData->mSizeX[mpData->mPlayerStatus] / mpData->mAnimframe[mpData->mPlayerStatus]) / 2);
	shape.bottom = (int)pos.y + (mpData->mSizeX[mpData->mPlayerStatus] / 2);
}