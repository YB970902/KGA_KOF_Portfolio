#pragma once
#include "Config.h"
#include "Scene.h"

class Image;
class OpeningScene : public Scene
{
private:
	Image** mArrIntroAnim = nullptr;
	Image* mpDefaultBackground = nullptr;
	int mCurIntroAnimFrame = 0;
	int mCurElapseTime = 0;

	bool mbIsOpening = true;

public:
	OpeningScene();
	~OpeningScene();

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;
};