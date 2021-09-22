#pragma once
#include "ChAnimData.h"

class Leona : public ChAnimData
{
public:
	ChAnimData mData;

	Lookat playerLookat;
	AnimStatus playerStatus;
	Acting playerAct;

	//static bool isAction = false;		// ���Ŀ� �Ʒ� ������ ������ isAction���� ���ս�ų�� �ִ��� �Ǵ��ʿ� (���ǹ��� &&�� �־�� �ϴ°ǰ�;)
	bool isAttack = false;				// ������ �׼��ε� ������ �ٸ������� �Ҽ��� ����.
	bool isJump = false;				// ������ �׼��ε� �����߿��� ������ �� �� ������ �����ο� �̵��� �Ұ��ϴ�. �ݵ�� ������ �������θ� �̵�
	bool isSit = false;					// �������´� �׼��ε� ������ �Ҽ� �ִ�.
										// isAction�� �������¿��� �̵��� �� �� ���°��� ��������� �ϳ��� Ʈ���ŷ� ������ �Ŵ°��� �ָ��ϴٴ� �Ǵ�
	bool notReverse;

	void init();
};
