#include "Image.h"

HRESULT Image::Init(int width, int height)
{
	HDC hdc = GetDC(g_hWnd);		// 권한이 굉장히 많은 총지배인

	// 빈 비트맵 생성
	if (imageInfo) { Release(); }
	imageInfo = new IMAGE_INFO;
	imageInfo->path = nullptr;
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = ImageLoadType::Empty;
	imageInfo->hBitmap = CreateCompatibleBitmap(hdc, width,height);
	imageInfo->hMemDc = CreateCompatibleDC(hdc);	// 새로 생성된 DC 
											// 기본적으로 Bitmap에 연결되어 있다.
	imageInfo->hOldBit =
		(HBITMAP)SelectObject(imageInfo->hMemDc, imageInfo->hBitmap);

	ReleaseDC(g_hWnd, hdc);

	//if (SUCCEEDED(E_FAIL))
	//{

	//}

	if (imageInfo->hBitmap == NULL)	// 비트맵 생성에 실패했을 때
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Image::Init(const char* fileName, int width, int height,
	bool isTrans/* = false*/, COLORREF transColor/* = NULL*/)
{
	HDC hdc = GetDC(g_hWnd);

	if (imageInfo) { Release(); }
	imageInfo = new IMAGE_INFO;
	imageInfo->path = fileName;
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = ImageLoadType::File;
	imageInfo->hBitmap = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height,
		LR_LOADFROMFILE);
	imageInfo->hMemDc = CreateCompatibleDC(hdc);	// 새로 생성된 DC 
											// 기본적으로 Bitmap에 연결되어 있다.
	imageInfo->hOldBit =
		(HBITMAP)SelectObject(imageInfo->hMemDc, imageInfo->hBitmap);

	ReleaseDC(g_hWnd, hdc);

	this->isTransparent = isTrans;
	this->transColor = transColor;

	if (imageInfo->hBitmap == NULL)
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Image::Init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY,
	bool isTrans, COLORREF transColor,bool bisFlat)
{
	HDC hdc = GetDC(g_hWnd);

	if (imageInfo) { Release(); }
	imageInfo = new IMAGE_INFO;
	
	imageInfo->path = fileName;
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = ImageLoadType::File;
	imageInfo->hBitmap = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height,
		LR_LOADFROMFILE);
	imageInfo->hMemDc = CreateCompatibleDC(hdc);	// 새로 생성된 DC 
									// 기본적으로 Bitmap에 연결되어 있다.
	imageInfo->hOldBit =
		(HBITMAP)SelectObject(imageInfo->hMemDc, imageInfo->hBitmap);

	ReleaseDC(g_hWnd, hdc);

	this->isTransparent = isTrans;
	this->transColor = transColor;

	imageInfo->maxFrameX = maxFrameX;
	imageInfo->maxFrameY = maxFrameY;
	imageInfo->currFrameX = 0;
	imageInfo->currFrameY = 0;
	imageInfo->frameWidth = width / maxFrameX;
	imageInfo->frameHeight = height / maxFrameY;

	if (bisFlat)
	{
		StretchBlt(
		imageInfo->hMemDc,
		width,//==66? 66 : imageInfo->frameWidth-(imageInfo->frameWidth-66)/2,
		0,
		-width,
		height,	// 전체 프레임 수

		imageInfo->hMemDc,
		0,
		0,
		width,
		height,
		SRCCOPY
	);
	}

	if (imageInfo->hBitmap == NULL)
	{
		cout << "비트맵 로드가 안됨" << endl;
		Release();
		return E_FAIL;
	}

	return S_OK;
}

void Image::Release()
{
	if (imageInfo)
	{
		SelectObject(imageInfo->hMemDc, imageInfo->hOldBit);
		DeleteObject(imageInfo->hBitmap);
		DeleteDC(imageInfo->hMemDc);

		delete imageInfo;
		imageInfo = nullptr;
	}
}

void Image::Render(HDC hdc)
{
	BitBlt(hdc,				// 복사 목적지 DC
		0,					// 복사될 비트맵의 시작 위치 x
		0,					// 복사될 비트맵의 시작 위치 y
		imageInfo->width,	// 원본 복사할 가로 크기
		imageInfo->height,	// 원본 복사할 세로 크기
		imageInfo->hMemDc,	// 원본 DC
		0,					// 원본 비트맵 복사 시작 위치 x
		0,					// 원본 비트맵 복사 시작 위치 y
		SRCCOPY);			// 복사 옵션
}

void Image::Render(HDC hdc, int destX, int destY)
{
	if (isTransparent)
	{
		GdiTransparentBlt(
			hdc,
			destX - (imageInfo->width / 2),
			destY - (imageInfo->height / 2),
			imageInfo->width, imageInfo->height,

			imageInfo->hMemDc,
			0, 0,
			imageInfo->width, imageInfo->height,
			transColor
		);
	}
	else
	{
		BitBlt(hdc,				// 복사 목적지 DC
			destX - (imageInfo->width / 2),				// 복사될 비트맵의 시작 위치 x
			destY - (imageInfo->height / 2),			// 복사될 비트맵의 시작 위치 y
			imageInfo->width,	// 원본 복사할 가로 크기
			imageInfo->height,	// 원본 복사할 세로 크기
			imageInfo->hMemDc,	// 원본 DC
			0,					// 원본 비트맵 복사 시작 위치 x
			0,					// 원본 비트맵 복사 시작 위치 y
			SRCCOPY);			// 복사 옵션
	}

}

void Image::Render(HDC hdc, int destX, int destY, int frameX, int frameY,eLookat playerLookat)
{
	// frameX : 0, frameY : 0 => 시작 (68 * 0, 0) (0,     0)	(68, 104)
	// frameX : 1, frameY : 0 => 시작 (68 * 1, 0) (68,  104)	(136, 104)
	// frameX : 2, frameY : 0 => 시작 (68 * 2, 0) (136, 104)	(204, 104)
	// frameX : 3, frameY : 0 => 시작 (68 * 3, 0) (204, 104)	(272, 104)
	//											  (68,	104)	(0,0)
	//Player.mpData.sizeX[playerStatus], Player.mpData.sizeY[playerStatus];

	if (isTransparent)
	{
		//if (playerLookat == eLookat::Right_Lookat)
		//{
		//	StretchBlt(
		//		imageInfo->hMemDc,
		//		imageInfo->frameWidth,//==66? 66 : imageInfo->frameWidth-(imageInfo->frameWidth-66)/2,
		//		0,
		//		-imageInfo->frameWidth,
		//		imageInfo->frameHeight,	// 전체 프레임 수

		//		imageInfo->hMemDc,
		//		imageInfo->frameWidth * frameX,
		//		imageInfo->frameHeight * frameY,
		//		imageInfo->frameWidth,
		//		imageInfo->frameHeight,
		//		SRCCOPY
		//	);

		//	GdiTransparentBlt(
		//		hdc,
		//		destX - (imageInfo->frameWidth*4 / 2),
		//		destY - (imageInfo->frameHeight*4 / 2),// - (imageInfo->frameHeight / 2),
		//		imageInfo->frameWidth*4,
		//		imageInfo->frameHeight*4,	// 전체 프레임 수

		//		imageInfo->hMemDc,
		//		0,
		//		0,
		//		imageInfo->frameWidth,
		//		imageInfo->frameHeight,
		//		RGB(255, 0, 255)
		//	);
		//}
		//else
		//if (playerLookat == eLookat::Left_Lookat)
		//{
			GdiTransparentBlt(
				hdc,
				destX - (imageInfo->frameWidth*4 / 2),	/*imageInfo->frameWidth <= baseX ? baseX : (imageInfo->frameWidth - (*/
				destY - (imageInfo->frameHeight*4 / 2), /*imageInfo->frameHeight <= baseY ? baseY : imageInfo->frameHeight - (*/
				imageInfo->frameWidth*4,
				imageInfo->frameHeight*4,	// 전체 프레임 수

				imageInfo->hMemDc,
				imageInfo->frameWidth * frameX,
				imageInfo->frameHeight * frameY,
				imageInfo->frameWidth,
				imageInfo->frameHeight,
				RGB(255,0,255)
			);
		/*}*/

		//GdiTransparentBlt(
		//	hdc,
		//	destX - (imageInfo->frameWidth / 2),// + imageInfo->frameWidth,
		//	destY - (imageInfo->frameHeight / 2),
		//	imageInfo->frameWidth,
		//	imageInfo->frameHeight,	// 전체 프레임 수

		//	imageInfo->hMemDc,
		//	imageInfo->frameWidth * frameX,
		//	imageInfo->frameHeight * frameY,
		//	imageInfo->frameWidth,
		//	imageInfo->frameHeight,
		//	RGB(255,0,255)
		//);

		//StretchBlt(
		//	hdc,
		//	imageInfo->frameWidth,
		//	0,
		//	-imageInfo->frameWidth,
		//	imageInfo->frameHeight,	// 전체 프레임 수

		//	imageInfo->hMemDc,
		//	0,
		//	0,
		//	imageInfo->frameWidth,
		//	imageInfo->frameHeight, SRCAND
		//);

		//GdiTransparentBlt(
		//	hdc,
		//	destX - (imageInfo->frameWidth / 2),
		//	destY - (imageInfo->frameHeight / 2),
		//	imageInfo->frameWidth,
		//	imageInfo->frameHeight,	// 전체 프레임 수

		//	imageInfo->hMemDc,
		//	imageInfo->frameWidth * frameX,
		//	imageInfo->frameHeight * frameY,
		//	imageInfo->frameWidth,
		//	imageInfo->frameHeight,
		//	RGB(255,0,255)
		//);


	//}
	//else
	//{
	//	BitBlt(hdc,				// 복사 목적지 DC
	//		destX - (imageInfo->width / 2),				// 복사될 비트맵의 시작 위치 x
	//		destY - (imageInfo->height / 2),			// 복사될 비트맵의 시작 위치 y
	//		imageInfo->width,	// 원본 복사할 가로 크기
	//		imageInfo->height,	// 원본 복사할 세로 크기
	//		imageInfo->hMemDc,	// 원본 DC
	//		0,					// 원본 비트맵 복사 시작 위치 x
	//		0,					// 원본 비트맵 복사 시작 위치 y
	//		SRCCOPY);			// 복사 옵션
	}
}

void Image::Render(HDC hdc, BLENDFUNCTION ftn)
{
		BitBlt(imageInfo->hMemDc,// 복사 목적지 DC
			0,					// 복사될 비트맵의 시작 위치 x
			0,					// 복사될 비트맵의 시작 위치 y
			imageInfo->width,	// 원본 복사할 가로 크기
			imageInfo->height,	// 원본 복사할 세로 크기
			imageInfo->hMemDc,	// 원본 DC
			0,					// 원본 비트맵 복사 시작 위치 x
			0,					// 원본 비트맵 복사 시작 위치 y
			SRCCOPY);			// 복사 옵션

		AlphaBlend(hdc, 0, 0, imageInfo->width, imageInfo->height, imageInfo->hMemDc, 0, 0, imageInfo->width, imageInfo->height, ftn);
}

void Image::ResizeWidth(int width)
{
	if (imageInfo->maxFrameX > 0 || imageInfo->maxFrameY > 0)
	{
		Init(imageInfo->path, width, imageInfo->height, imageInfo->maxFrameX, imageInfo->maxFrameY, isTransparent, transColor);
	}
	else
	{
		Init(imageInfo->path, width, imageInfo->height, isTransparent, transColor);
	}
}
