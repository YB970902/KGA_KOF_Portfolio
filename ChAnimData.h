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
<<<<<<< HEAD
	map<eAnimStatus, int> mAnimframe = {};
	map<eAnimStatus, int> mAnimSpeed = {};
	map<eAnimStatus, int> mSizeX = {};
	map<eAnimStatus, int> mSizeY = {};
	map<eAnimStatus, const char*> mPath = {};
	map<eAnimStatus, int> mMoveAfteraction = {};
=======
	map<AnimStatus, int> mAnimframe;
	map<AnimStatus, int> mAnimSpeed;
	map<AnimStatus, int> mSizeX;
	map<AnimStatus, int> mSizeY;
	map<AnimStatus, const char*> mPath;
	map<AnimStatus, int> mMoveAfteraction;
	map<AnimStatus, int> mHitboxShapeLeft;
	map<AnimStatus, int> mHitboxShapeRight;
	map<AnimStatus, int> mHitboxShapeTop;
	map<AnimStatus, int> mHitboxShapeBottom;
	map<AnimStatus, int> mHitboxOnFrame;
	map<AnimStatus, int> mHitboxOffFrame;
	
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9
};
