#pragma once
#include "GameEntity.h"
#include "Config.h"

class Image;
class HealthBar : public GameEntity
{
protected:
	Image* mpHealthBarFront = nullptr;
	Image* mpHealthBarBack = nullptr;

	POINTFLOAT mPos;
	int mBarFrontX = 0;

	int mWidth = 0;
	int mHeight = 0;

	float mCurValue = 1.0f;

	eHealthBarDir mBarDir = eHealthBarDir::Left;

public:
	virtual void Init() override;

	virtual void Update() override;

	virtual void Render(HDC hdc) override;

	virtual void Release() override;


	inline void SetHealthBarDir(eHealthBarDir dir) { mBarDir = dir; }
	inline void SetPosition(POINTFLOAT pos) { mPos = pos; }
	void SetValue(float val);
};

