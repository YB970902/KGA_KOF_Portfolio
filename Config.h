#pragma once
#include <Windows.h>
#include <math.h>
#include <iostream>

using namespace std;

#define WIN_START_POS_X	400
#define WIN_START_POS_Y	100
#define WIN_SIZE_X	1200
#define WIN_SIZE_Y	900

#define PI 3.141592653578979
#define PI2 (3.14159265358979 * 2)

#define MGR_KEY (KeyManager::GetSingleton())
#define MGR_SCN (SceneManager::GetSingleton())

#define DEGREE_TO_RADIAN(x)		(x * PI / 180.0f)

#define SAFE_RELEASE(p)	{ if (p) { p->Release(); delete p; p = nullptr; } }

enum class MoveDir { Left = -1, Right = 1, Up, Down };
enum class eSceneTag { HitBoxSnene, };

extern HWND g_hWnd;
extern HINSTANCE g_hInstance;