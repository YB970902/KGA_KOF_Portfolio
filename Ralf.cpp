#include "Ralf.h"
using namespace std;
// ������ ���������͸� �޾�����
// ���߿� �ٸ� �����͵� �ҷ��� ����
// ������ Idle, Move�� �Ǿ�������
// ���߿� Ralf_Idle, Mai_Move ������ ĳ���� �̸��� �տ� ���� ����
// enum�� ���� �� ĳ���͸��� �������ͽ� ���������� ���ڷ� ������ ����
// ��) Ralf 0 Mai 8 ddd 15 ...
// 
//

void Ralf::init()
{
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Idle, "Image/Ralf_Database_IMG/Ralf_Idle.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Move, "Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Damaged, "Image/Ralf_Database_IMG/Ralf_Damaged.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Weak_Punch, "Image/Ralf_Database_IMG/Ralf_Weak_Punch.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Weak_Kick, "Image/Ralf_Database_IMG/Ralf_Weak_kick.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Strong_Punch, "Image/Ralf_Database_IMG/Ralf_Strong_Punch.bmp"));
	mData.Path.insert(pair<ChAnimData::AnimStatus, const char*>(ChAnimData::AnimStatus::Strong_Kick, "Image/Ralf_Database_IMG/Ralf_Strong_kick.bmp"));

	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 18));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move, 8));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 4));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 4));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 6));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 8));
	mData.Animframe.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 12));

	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 1188));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move, 528));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 568));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 488));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 768));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 1680));
	mData.sizeX.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 2352));

	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Idle, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Move, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Damaged, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Kick, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Weak_Punch, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Kick, 120));
	mData.sizeY.insert(pair<ChAnimData::AnimStatus, int>(ChAnimData::AnimStatus::Strong_Punch, 140));
}