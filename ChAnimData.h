#pragma once
#include "Config.h"
#include <map>

class ChAnimData
{
public:

	Lookat mPlayerLookat = {};
	AnimStatus mPlayerStatus = {};
	Acting mPlayerAct = {};

	//static bool isAction = false;		// ���Ŀ� �Ʒ� ������ ������ isAction���� ���ս�ų�� �ִ��� �Ǵ��ʿ� (���ǹ��� &&�� �־�� �ϴ°ǰ�;)
	bool mIsAttack = false;				// ������ �׼��ε� ������ �ٸ������� �Ҽ��� ����.
	bool mIsJump = false;				// ������ �׼��ε� �����߿��� ������ �� �� ������ �����ο� �̵��� �Ұ��ϴ�. �ݵ�� ������ �������θ� �̵�
	bool mIsSit = false;					// �������´� �׼��ε� ������ �Ҽ� �ִ�.
										// isAction�� �������¿��� �̵��� �� �� ���°��� ��������� �ϳ��� Ʈ���ŷ� ������ �Ŵ°��� �ָ��ϴٴ� �Ǵ�
	bool mNotReverse = false;

	//���Ŀ� ��Ʈ��Ʈ�� ����.
	map<AnimStatus, int> mAnimframe;
	map<AnimStatus, int> mAnimSpeed;
	map<AnimStatus, int> mSizeX;
	map<AnimStatus, int> mSizeY;
	map<AnimStatus, const char*> mPath;
	map<AnimStatus, int> mMoveAfteraction;
	
};
