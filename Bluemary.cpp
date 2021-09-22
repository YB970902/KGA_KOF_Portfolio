#include "Bluemary.h"
using namespace std;

void Bluemary::init()
{
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Idle, "Image/Bluemary_Database_IMG/Bluemary_Idle.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Move_Front, "Image/Bluemary_Database_IMG/Bluemary_Walk_Front.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Move_Backward, "Image/Bluemary_Database_IMG/Bluemary_Walk_Back.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Damaged, "Image/Bluemary_Database_IMG/Bluemary_Damaged.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Weak_Punch, "Image/Bluemary_Database_IMG/Bluemary_Weak_Punch.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Weak_Kick, "Image/Bluemary_Database_IMG/Bluemary_Weak_kick.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Strong_Punch, "Image/Bluemary_Database_IMG/Bluemary_Strong_Punch.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Strong_Kick, "Image/Bluemary_Database_IMG/Bluemary_Strong_kick.bmp"));

	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 12));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 10));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 6));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 4));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 4));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 9));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 22));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 12));

	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 720));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 600));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 360));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 568));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 400));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 1080));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 4840));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 2160));

	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 100));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 100));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 130));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 120));

	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 22));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 24));
}
