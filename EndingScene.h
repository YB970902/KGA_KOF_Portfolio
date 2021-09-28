#pragma once
#include "Scene.h"

class Image;
class EndingScene : public Scene
{
private:
	Image* mWinnerImage = nullptr;
	Image* mEndingBackground = nullptr;

public:
	virtual void Enter() override;

	virtual void Update() override;

	virtual void Render(HDC hdc) override;

	virtual void Exit() override;

};

