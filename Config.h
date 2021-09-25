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

enum class eMoveDir { Left = -1, Right = 1, Up, Down, };
enum class eSceneTag { CharacterSelectScene, HitBoxSnene, AnimationScene, };
enum class eCharacterType { Null, Bluemary, Ralf, Leona, };

extern HWND g_hWnd;
extern HINSTANCE g_hInstance;

extern int Player1;
extern int Player2;

enum class eAnimStatus
{
	Idle,
	Move_Forward,
	Move_Backward,
	Damaged,
	Weak_Punch,
	Weak_Kick,
	Strong_Punch,
	Strong_Kick,
};

enum class eActing
{
	Act_Attack,
	Act_Left_Move,
	Act_Right_Move,
	Act_Idle,
};

enum class eLookat
{
	Left_Lookat = -1,
	Right_Lookat = 1
};

enum class eHealthBarDir
{
	Left,
	Right,
};