#pragma once
#include "GameObject.h"
#include "Ralf.h"
//#include "Image.h"	// 컴파일 관계가 복잡, 컴파일 시간이 오래 걸림

using namespace std;

class Image;	// 포함관계
class AnimManager : public GameObject	// 상속관계
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
