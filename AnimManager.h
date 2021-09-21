#pragma once
#include "GameObject.h"
#include "Ralf.h"
//#include "Image.h"	// ������ ���谡 ����, ������ �ð��� ���� �ɸ�

using namespace std;

class Image;	// ���԰���
class AnimManager : public GameObject	// ��Ӱ���
{
private:
	Image* img;
	int frameX, frameY;
	int elapsedCount;

public:
	void Init();
	void ImgUpdate(ChAnimData::AnimStatus playerStatus);
	void Update();
	void Render(HDC hdc);
	void Release();
};
