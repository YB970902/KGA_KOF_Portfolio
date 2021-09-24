#pragma once
#include "Scene.h"
#include "Config.h"

class Image;
class CharacterSelectScene : public Scene
{
private:
	Image* mpBackground = nullptr;

	Image* mp1PMugshotBackground = nullptr;
	Image* mp2PMugshotBackground = nullptr;

	Image* mpLeonaMugshot = nullptr;
	Image* mpMaryMugshot = nullptr;
	Image* mpRalfMugshot = nullptr;

	Image* mpRightSection = nullptr;

	Image* mp1PEdge = nullptr;
	Image* mp2PEdge = nullptr;

public:
	CharacterSelectScene();
	~CharacterSelectScene();
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Exit() override;
};

