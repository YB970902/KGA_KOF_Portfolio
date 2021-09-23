#include "BluemaryAnimation.h"
#include "ChAnimData.h"
#include "Image.h"
#include "KeyManager.h"

using namespace std;

void BluemaryAnimation::Init(Lookat dir)
{
	mpData = new ChAnimData;

	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Idle, "Image/Bluemary_Database_IMG/Bluemary_Idle.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Move_Forward, "Image/Bluemary_Database_IMG/Bluemary_Walk_Front.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Move_Backward, "Image/Bluemary_Database_IMG/Bluemary_Walk_Back.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Damaged, "Image/Bluemary_Database_IMG/Bluemary_Damaged.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Weak_Punch, "Image/Bluemary_Database_IMG/Bluemary_Weak_Punch.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Weak_Kick, "Image/Bluemary_Database_IMG/Bluemary_Weak_kick.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Strong_Punch, "Image/Bluemary_Database_IMG/Bluemary_Strong_Punch.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Strong_Kick, "Image/Bluemary_Database_IMG/Bluemary_Strong_kick.bmp"));

	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Idle, 12));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Move_Forward, 10));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 6));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 4));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 4));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 9));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 22));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 12));

	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Idle, 720));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Move_Forward, 600));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 360));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 568));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 400));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 1080));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 4840));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 2160));

	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Idle, 100));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Move_Forward, 120));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 120));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 120));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 120));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 100));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 130));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 120));

	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Idle, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Move_Forward, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 22));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 24));

	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Idle, 8));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Move_Forward, 6));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 8));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 0));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 4));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 4));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 4));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 4));

	mpData->mNotReverse = 1;

	mpData->mPlayerAct = Acting::Act_Idle;
	mpData->mPlayerStatus = AnimStatus::Idle;
	mpData->mPlayerLookat = dir;

	//selectedCharacter = ralf

	img = new Image;

	//"Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"
	//Waystring = PlayerCharacter1.Import_Image(PlayerCharacter1.m_Setcharacter,PlayerCharacter1.m_Player.playerStatus);

	img->Init(mpData->mPath[mpData->mPlayerStatus], (int)mpData->mSizeX[mpData->mPlayerStatus], (int)mpData->mSizeY[mpData->mPlayerStatus],
		(int)mpData->mAnimframe[mpData->mPlayerStatus], 1, true, RGB(255, 0, 255));

	//img->Init(Player.mpData->mPath[playerStatus], (int)Player.mpData->sizeX[playerStatus], (int)Player.mpData->sizeY[playerStatus],
	//	(int)Player.mpData->Animframe[playerStatus], 1, true, RGB(255, 0, 255));

	frameX = frameY = 0;
	elapsedCount = 0;
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	moveSpeed = 10.0f;

	mHP = 100;

	shape.left = (int)pos.x - ((mpData->mSizeX[mpData->mPlayerStatus] / mpData->mAnimframe[mpData->mPlayerStatus]) / 2);
	shape.top = (int)pos.y - (mpData->mSizeX[mpData->mPlayerStatus] / 2);
	shape.right = (int)pos.x + ((mpData->mSizeX[mpData->mPlayerStatus] / mpData->mAnimframe[mpData->mPlayerStatus]) / 2);
	shape.bottom = (int)pos.y + (mpData->mSizeX[mpData->mPlayerStatus] / 2);
}