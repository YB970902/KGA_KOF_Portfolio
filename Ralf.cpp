#include "Ralf.h"
// 지금은 랄프데이터만 받았지만
// 나중엔 다른 데이터도 불러올 예정
// 지금은 Idle, Move로 되어있지만
// 나중엔 Ralf_Idle, Mai_Move 등으로 캐릭터 이름을 앞에 붙일 예정
// enum을 통해 각 캐릭터마다 스테이터스 시작지점을 숫자로 지정할 예정
// 예) Ralf 0 Mai 8 ddd 15 ...
// 
//
using namespace std;

void Ralf::init()
{
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Idle, "Image/Ralf_Database_IMG/Ralf_Idle.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Move_Front, "Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Move_Backward, "Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Damaged, "Image/Ralf_Database_IMG/Ralf_Damaged.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Weak_Punch, "Image/Ralf_Database_IMG/Ralf_Weak_Punch.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Weak_Kick, "Image/Ralf_Database_IMG/Ralf_Weak_kick.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Strong_Punch, "Image/Ralf_Database_IMG/Ralf_Strong_Punch.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Strong_Kick, "Image/Ralf_Database_IMG/Ralf_Strong_kick.bmp"));

	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 35));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 8));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 8));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 4));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 4));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 6));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 8));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 12));

	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 2345));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 528));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 528));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 568));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 488));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 768));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 1680));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 2352));

	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 140));

	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Front, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move_Backward, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 0));
	mData.moveAfteraction.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 0));
}
