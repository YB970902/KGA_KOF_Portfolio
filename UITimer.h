#pragma once
#include <map>
#include "GameEntity.h"

using namespace std;

class Image;
class UITimer : public GameEntity
{
protected:
	const int TimeImageWidth = 68;
	const int TimeImageHeight = 100;
	const int TimeImageWidthHalf = 34;
	const int TimeImageHeightHalf = 50;
	map<int, Image*> mImgMap;
	int mElapseTime = 0;
	int mCurTime = 0;

public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	inline void SetTime(int time) { mCurTime = time; }
};

