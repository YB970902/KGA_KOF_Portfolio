#include "RalfAnimation.h"
#include "Image.h"
#include "KeyManager.h"
#include "ChAnimData.h"

// 지금은 랄프데이터만 받았지만
// 나중엔 다른 데이터도 불러올 예정
// 지금은 Idle, Move로 되어있지만
// 나중엔 Ralf_Idle, Mai_Move 등으로 캐릭터 이름을 앞에 붙일 예정
// enum을 통해 각 캐릭터마다 스테이터스 시작지점을 숫자로 지정할 예정
// 예) Ralf 0 Mai 8 ddd 15 ...
// 
//
using namespace std;

void RalfAnimation::Init(eLookat dir)
{
	mpData = new ChAnimData;

	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Idle, "Image/Ralf_Database_IMG/Ralf_Idle.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Move_Forward, "Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Move_Backward, "Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Damaged, "Image/Ralf_Database_IMG/Ralf_Damaged.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Dead, "Image/Ralf_Database_IMG/Ralf_Dead.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Weak_Punch, "Image/Ralf_Database_IMG/Ralf_Weak_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Weak_Kick, "Image/Ralf_Database_IMG/Ralf_Weak_kick.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Strong_Punch, "Image/Ralf_Database_IMG/Ralf_Strong_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Strong_Kick, "Image/Ralf_Database_IMG/Ralf_Strong_kick.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Weak_Punch, "Image/Ralf_Database_IMG/Ralf_Weak_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Weak_Kick, "Image/Ralf_Database_IMG/Ralf_Near_Weak_kick.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Strong_Punch, "Image/Ralf_Database_IMG/Ralf_Near_Strong_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Strong_Kick, "Image/Ralf_Database_IMG/Ralf_Near_Strong_kick.bmp"));

	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 35));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 8));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 8));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 4));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Dead, 19));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 4));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 6));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 8));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 12));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 4));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 4));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 14));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 8));

	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 2345));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 528));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 528));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 568));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Dead, 2850));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 488));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 768));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 1680));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 2352));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 488));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 600));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 2100));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 1200));

	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Dead, 190));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 140));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 130));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 130));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 130));

	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 0));

	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 8));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 7));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 7));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 0));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 4));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, -240));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 240));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, -140));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, -60));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 1));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 3));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, -260));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 260));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, -120));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, -40));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 3));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 5));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, -420));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 420));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, -120));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, -40));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 3));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 5));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, -392));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 392));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, -100));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 0));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 4));
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

	mpData->mNotReverse = 0;

	mpData->mPlayerAct = eActing::Act_Idle;
	mpData->mPlayerStatus = eAnimStatus::Idle;
	mpData->mPlayerLookat = dir;
	mpData->mIsDamaged = false;

	//Player.selectedCharacter = ralf

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
	moveSpeed = 50.0f;

	mHP = 100;

	shape.left = (int)pos.x - ((mpData->mSizeX[mpData->mPlayerStatus] / mpData->mAnimframe[mpData->mPlayerStatus]) / 2);
	shape.top = (int)pos.y - (mpData->mSizeX[mpData->mPlayerStatus] / 2);
	shape.right = (int)pos.x + ((mpData->mSizeX[mpData->mPlayerStatus] / mpData->mAnimframe[mpData->mPlayerStatus]) / 2);
	shape.bottom = (int)pos.y + (mpData->mSizeX[mpData->mPlayerStatus] / 2);

}