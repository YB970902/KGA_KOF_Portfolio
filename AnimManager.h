#pragma once
#include "Character.h"
#include "ChAnimData.h"

//#include "Image.h"	// ������ ���谡 ����, ������ �ð��� ���� �ɸ�

using namespace std;

class Image;	// ���԰���
class AnimManager : public Character	// ��Ӱ���
{
private:
	Image* img;
	int frameX, frameY;
	int elapsedCount;

	AnimManager* mpTarget = nullptr;

public:
	void Init();
	void ImgUpdate(ChAnimData::AnimStatus playerStatus);
	void Update();
	void Render(HDC hdc);
	void Release();
};

static int baseX;
static int baseY;