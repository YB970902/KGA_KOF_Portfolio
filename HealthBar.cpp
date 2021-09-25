#include "HealthBar.h"
#include "Image.h"

void HealthBar::Init()
{
	mpHealthBarFront = new Image();
	mpHealthBarBack = new Image();

	mWidth = 400;
	mHeight = 40;

	mpHealthBarFront->Init("Image/UI/HPBarFront.bmp", mWidth, mHeight);
	mpHealthBarBack->Init("Image/UI/HPBarBack.bmp", mWidth + 5, mHeight + 10, true, RGB(255, 0, 255));
}

void HealthBar::Update()
{
}

void HealthBar::Render(HDC hdc)
{
	mpHealthBarBack->Render(hdc, (int)mPos.x, (int)mPos.y);
	mpHealthBarFront->Render(hdc, (int)mPos.x + mBarFrontX, (int)mPos.y);
}

void HealthBar::Release()
{
	SAFE_RELEASE(mpHealthBarFront);
	SAFE_RELEASE(mpHealthBarBack);
}

void HealthBar::SetValue(float val)
{
	mpHealthBarFront->ResizeWidth((int)(mWidth * val));
	if (mBarDir == eHealthBarDir::Left)
	{
		mBarFrontX = -(int)((mWidth - mWidth * val) * 0.5f);
	}
	else
	{
		mBarFrontX = (int)((mWidth - mWidth * val) * 0.5f);
	}
}
