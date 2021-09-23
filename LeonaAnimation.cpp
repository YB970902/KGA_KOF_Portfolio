#include "LeonaAnimation.h"
#include "Image.h"
#include "KeyManager.h"
#include "ChAnimData.h"
using namespace std;

void LeonaAnimation::Init(Lookat dir)
{

	mpData = new ChAnimData;


	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Idle, "Image/Leona_Database_IMG/Leona_Idle.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Move_Forward, "Image/Leona_Database_IMG/Leona_Walk_Front.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Move_Backward, "Image/Leona_Database_IMG/Leona_Walk_Back.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Damaged, "Image/Leona_Database_IMG/Leona_Damaged.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Weak_Punch, "Image/Leona_Database_IMG/Leona_Weak_Punch.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Weak_Kick, "Image/Leona_Database_IMG/Leona_Weak_kick.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Strong_Punch, "Image/Leona_Database_IMG/Leona_Strong_Punch.bmp"));
	mpData->mPath.insert(pair<AnimStatus, const char*>(AnimStatus::Strong_Kick, "Image/Leona_Database_IMG/Leona_Strong_kick.bmp"));

	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Idle, 46));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Move_Forward, 10));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 8));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 4));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 5));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 8));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 11));
	mpData->mAnimframe.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 14));

	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Idle, 3680));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Move_Forward, 800));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 640));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 568));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 1400));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 2240));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 3080));
	mpData->mSizeX.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 3920));

	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Idle, 120));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Move_Forward, 120));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 140));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 140));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 140));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 140));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 140));
	mpData->mSizeY.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 140));

	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Idle, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Move_Forward, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 0));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 81));
	mpData->mMoveAfteraction.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 37));

	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Idle, 8));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Move_Forward, 7));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Move_Backward, 7));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Damaged, 0));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Weak_Kick, 4));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Weak_Punch, 4));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Strong_Kick, 4));
	mpData->mAnimSpeed.insert(pair<AnimStatus, int>(AnimStatus::Strong_Punch, 4));

	mpData->mNotReverse = 1;

	mpData->mPlayerAct = Acting::Act_Idle;
	mpData->mPlayerStatus = AnimStatus::Idle;
	mpData->mPlayerLookat = dir;

	//Player.selectedCharacter = ralf

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

