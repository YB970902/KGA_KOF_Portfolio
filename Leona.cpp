#include "Leona.h"
using namespace std;

void Leona::init()
{
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Idle, "Image/Leona_Database_IMG/Leona_Idle.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Move_Front, "Image/Leona_Database_IMG/Leona_Walk_Front.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Move_Backward, "Image/Leona_Database_IMG/Leona_Walk_Back.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Damaged, "Image/Leona_Database_IMG/Leona_Damaged.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Weak_Punch, "Image/Leona_Database_IMG/Leona_Weak_Punch.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Weak_Kick, "Image/Leona_Database_IMG/Leona_Weak_kick.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Strong_Punch, "Image/Leona_Database_IMG/Leona_Strong_Punch.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Strong_Kick, "Image/Leona_Database_IMG/Leona_Strong_kick.bmp"));

	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 46));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 10));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 8));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 4));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 5));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 8));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 11));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 14));

	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 3680));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 800));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 640));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 568));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 1400));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 2240));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 3080));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 3920));

	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 140));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 140));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 140));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 140));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 140));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 140));

	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 81));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 37));

	mData.AnimSpeed.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 8));
	mData.AnimSpeed.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 7));
	mData.AnimSpeed.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 7));
	mData.AnimSpeed.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 0));
	mData.AnimSpeed.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 4));
	mData.AnimSpeed.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 4));
	mData.AnimSpeed.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 4));
	mData.AnimSpeed.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 4));

	notReverse = 1;
}
