#pragma once
#include "Config.h"
#include <map>

class ChAnimData
{
public:
	eLookat mPlayerLookat = {};
	eAnimStatus mPlayerStatus = {};
	eActing mPlayerAct = {};

	//static bool isAction = false;		// ���Ŀ� �Ʒ� ������ ������ isAction���� ���ս�ų�� �ִ��� �Ǵ��ʿ� (���ǹ��� &&�� �־�� �ϴ°ǰ�;)
	bool mIsAttack = false;				// ������ �׼��ε� ������ �ٸ������� �Ҽ��� ����.
	bool mIsJump = false;				// ������ �׼��ε� �����߿��� ������ �� �� ������ �����ο� �̵��� �Ұ��ϴ�. �ݵ�� ������ �������θ� �̵�
	bool mIsSit = false;					// �������´� �׼��ε� ������ �Ҽ� �ִ�.
										// isAction�� �������¿��� �̵��� �� �� ���°��� ��������� �ϳ��� Ʈ���ŷ� ������ �Ŵ°��� �ָ��ϴٴ� �Ǵ�
	bool mNotReverse = false;

	//���Ŀ� ��Ʈ��Ʈ�� ����.
	map<eAnimStatus, int> mAnimframe;
	map<eAnimStatus, int> mAnimSpeed;
	map<eAnimStatus, int> mSizeX;
	map<eAnimStatus, int> mSizeY;
	map<eAnimStatus, const char*> mPath;
	map<eAnimStatus, int> mMoveAfteraction;
	map<eAnimStatus, int> mHitboxShapeLeft;
	map<eAnimStatus, int> mHitboxShapeRight;
	map<eAnimStatus, int> mHitboxShapeTop;
	map<eAnimStatus, int> mHitboxShapeBottom;
	map<eAnimStatus, int> mHitboxOnFrame;
	map<eAnimStatus, int> mHitboxOffFrame;
	
};
