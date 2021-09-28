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
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Damaged, "Image/Bluemary_Database_IMG/Bluemary_Damaged_2.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Dead, "Image/Bluemary_Database_IMG/Bluemary_Dead_2.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Weak_Punch, "Image/Bluemary_Database_IMG/Bluemary_Weak_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Weak_Kick, "Image/Bluemary_Database_IMG/Bluemary_Weak_Kick.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Strong_Punch, "Image/Bluemary_Database_IMG/Bluemary_Strong_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Strong_Kick, "Image/Bluemary_Database_IMG/Bluemary_Strong_Kick.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Weak_Punch, "Image/Bluemary_Database_IMG/Bluemary_Near_Weak_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Weak_Kick, "Image/Bluemary_Database_IMG/Bluemary_Near_Weak_Kick.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Strong_Punch, "Image/Bluemary_Database_IMG/Bluemary_Near_Strong_Punch.bmp"));
	mpData->mPath.insert(pair<eAnimStatus, const char*>(eAnimStatus::Near_Strong_Kick, "Image/Bluemary_Database_IMG/Bluemary_Near_Strong_Kick.bmp"));

	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 12));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 10));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 6));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 3));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Dead, 14));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 4));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 9));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 22));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 12));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 5));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 7));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 15));
	mpData->mAnimframe.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 13));

	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 720));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 600));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 360));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 270));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Dead, 2100));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 400));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 1080));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 4840));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 2160));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 300));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 1800));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 490));
	mpData->mSizeX.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 1300));

	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 100));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 100));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Dead, 130));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 100));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 120));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 130));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 104));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 140));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 130));
	mpData->mSizeY.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 150));

	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 88));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 96));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 0));
	mpData->mMoveAfteraction.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 0));

	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Idle, 8));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Forward, 6));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Move_Backward, 8));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Damaged, 3));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 4));
	mpData->mAnimSpeed.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 4));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, -200));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 200));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, -140));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, -100));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 2));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 3));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, -240));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 240));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, -120));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, -40));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 4));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 6));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, -420));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 420));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, -120));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, -40));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 9));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 14));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, -340));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 340));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, -100));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 0));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 4));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 6));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, -121));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 121));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, -149));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, -103));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 1));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Punch, 4));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, -237));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 237));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, -249));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 80));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 1));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Weak_Kick, 3));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, -132));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 132));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, -50));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 160));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 2));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Punch, 5));

	mpData->mHitboxShapeLeft.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, -193));
	mpData->mHitboxShapeRight.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 193));
	mpData->mHitboxShapeTop.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, -157));
	mpData->mHitboxShapeBottom.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, -30));
	mpData->mHitboxOnFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 7));
	mpData->mHitboxOffFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Near_Strong_Kick, 8));

	//mpData->mMoveAfteractionForwardVal.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	//mpData->mMoveAfteractionForwardStartFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	//mpData->mMoveAfteractionBackwardVal.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	//mpData->mMoveAfteractionBackwardStartFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	//mpData->mHitboxShapeBottomChangeUpVal.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	//mpData->mHitboxShapebottomChangeUpFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	//mpData->mHitboxShapeBottomChangeDownVal.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));
	//mpData->mHitboxShapebottomChangeDownFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Punch, 0));

	//mpData->mMoveAfteractionForwardVal.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	//mpData->mMoveAfteractionForwardStartFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	//mpData->mMoveAfteractionBackwardVal.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	//mpData->mMoveAfteractionBackwardStartFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	//mpData->mHitboxShapeBottomChangeUpVal.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	//mpData->mHitboxShapebottomChangeUpFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	//mpData->mHitboxShapeBottomChangeDownVal.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));
	//mpData->mHitboxShapebottomChangeDownFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Weak_Kick, 0));

	//mpData->mMoveAfteractionForwardVal.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 6));
	//mpData->mMoveAfteractionForwardStartFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 6));
	//mpData->mMoveAfteractionBackwardVal.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 6));
	//mpData->mMoveAfteractionBackwardStartFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 6));
	//mpData->mMoveAfteractionStopStartFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 0));
	//mpData->mMoveAfteractionStopEndFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 0));
	//mpData->mHitboxShapeBottomChangeUpVal.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 6));
	//mpData->mHitboxShapebottomChangeUpFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 6));
	//mpData->mHitboxShapeBottomChangeDownVal.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 6));
	//mpData->mHitboxShapebottomChangeDownFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Punch, 6));

	//mpData->mMoveAfteractionForwardVal.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 6));
	//mpData->mMoveAfteractionForwardStartFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 3));
	//mpData->mMoveAfteractionBackwardVal.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 0));
	//mpData->mMoveAfteractionBackwardStartFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 7));
	//mpData->mHitboxShapeBottomChangeUpVal.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 15));
	//mpData->mHitboxShapebottomChangeUpFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 3));
	//mpData->mHitboxShapeBottomChangeDownVal.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 15));
	//mpData->mHitboxShapebottomChangeDownFrame.insert(pair<eAnimStatus, int>(eAnimStatus::Strong_Kick, 7));

	// bottom 의 up상태랑 down상태를 bool UpShapeBottom를 선언하여 스위치를 켜고 끄며 해도 되긴함.
	// 그런데 그럴경우 '내려오는 프레임의 갯수나 올라오는 프레임의 갯수'가 '대비되는 상태의 프레임수'와 비교했을때 '차이가 있으면' 제대로된 값이 들어가지는 않을거같음.
	// 예시) 올라오는 상태의 프레임갯수 3개 y값 +20씩, 내려오는 상태의 프레임의 갯수 4개 y값 +15씩
	// 이번에 히트박스 하나로 작업하면서 느낀점 : 히트박스 두개하면 정해진 프레임에 켜고 끄기만 하면됨;

	mpData->mNotReverse = 1;

	mpData->mPlayerAct = eActing::Act_Idle;
	mpData->mPlayerStatus = eAnimStatus::Idle;
	mpData->mPlayerLookat = dir;
	mpData->mIsDamaged = false;

	//selectedCharacter = ralf

	//"Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"
	//Waystring = PlayerCharacter1.Import_Image(PlayerCharacter1.m_Setcharacter,PlayerCharacter1.m_Player.playerStatus);

	//img->Init(Player.mpData->mPath[playerStatus], (int)Player.mpData->sizeX[playerStatus], (int)Player.mpData->sizeY[playerStatus],
	//	(int)Player.mpData->Animframe[playerStatus], 1, true, RGB(255, 0, 255));

	mFrameX = mFrameY = 0;
	mElapsedCount = 0;
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	moveSpeed = 50.0f;

	mMaxHP = mHP = 100;

	shape.left = (int)pos.x - ((mpData->mSizeX[mpData->mPlayerStatus] / mpData->mAnimframe[mpData->mPlayerStatus]) / 2);
	shape.top = (int)pos.y - (mpData->mSizeX[mpData->mPlayerStatus] / 2);
	shape.right = (int)pos.x + ((mpData->mSizeX[mpData->mPlayerStatus] / mpData->mAnimframe[mpData->mPlayerStatus]) / 2);
	shape.bottom = (int)pos.y + (mpData->mSizeX[mpData->mPlayerStatus] / 2);

	mpData->mCharTag = eCharacterTag::Bluemary;
}