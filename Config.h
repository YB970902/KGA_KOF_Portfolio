#pragma once
#include <Windows.h>
#include <math.h>
#include <iostream>
#include "KeyManager.h"

using namespace std;

#define WIN_START_POS_X	400
#define WIN_START_POS_Y	100
#define WIN_SIZE_X	1200
#define WIN_SIZE_Y	900

#define PI 3.141592653578979
#define PI2 (3.14159265358979 * 2)

#define MGR_KEY (KeyManager::GetSingleton())
#define MGR_SCN (SceneManager::GetSingleton())
#define MGR_IMG (ImageManager::GetSingleton())

#define DEGREE_TO_RADIAN(x)		(x * PI / 180.0f)

#define SAFE_RELEASE(p)	{ if (p) { p->Release(); delete p; p = nullptr; } }

enum class eMoveDir { Left = -1, Right = 1, Up, Down, };
enum class eSceneTag { OpeningScene,CharacterSelectScene, HitBoxSnene, AnimationScene, };
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
	Dead,
	Weak_Punch,
	Weak_Kick,
	Strong_Punch,
	Strong_Kick,
	Near_Weak_Punch,
	Near_Weak_Kick,
	Near_Strong_Punch,
	Near_Strong_Kick,
};

enum class eActing
{
	Act_Attack,
	Act_Left_Move,
	Act_Right_Move,
	Act_Idle,
	Damaged,
	Dead
};

enum class eLookat
{
	Left_Lookat = 0,
	Right_Lookat = 13,
};

enum class eHealthBarDir
{
	Left,
	Right,
};

enum class eCharacterTag
{
	Leona = 0,
	Ralf = 26,
	Bluemary = 52,
};

enum class eImageTag
{
	// 레오나 왼쪽 모션

	LeonaLeftIdle = 0,
	LeonaLeftForward,
	LeonaLeftBackward,
	LeonaLeftDamaged,
	LeonaLeftDead,
	LeonaLeftWeakPunch,
	LeonaLeftWeakKick,
	LeonaLeftStrongPunch,
	LeonaLeftStrongKick,
	LeonaLeftNearWeakPunch,
	LeonaLeftNearWeakKick,
	LeonaLeftNearStrongPunch,
	LeonaLeftNearStrongKick,

	// 레오나 오른쪽 모션

	LeonaRightIdle = 13,
	LeonaRightForward,
	LeonaRightBackward,
	LeonaRightDamaged,
	LeonaRightDead,
	LeonaRightWeakPunch,
	LeonaRightWeakKick,
	LeonaRightStrongPunch,
	LeonaRightStrongKick,
	LeonaRightNearWeakPunch,
	LeonaRightNearWeakKick,
	LeonaRightNearStrongPunch,
	LeonaRightNearStrongKick,

	// 랄프 왼쪽 모션

	RalfLeftIdle = 26,
	RalfLeftForward,
	RalfLeftBackward,
	RalfLeftDamaged,
	RalfLeftDead,
	RalfLeftWeakPunch,
	RalfLeftWeakKick,
	RalfLeftStrongPunch,
	RalfLeftStrongKick,
	RalfLeftNearWeakPunch,
	RalfLeftNearWeakKick,
	RalfLeftNearStrongPunch,
	RalfLeftNearStrongKick,

	// 랄프 오른쪽 모션

	RalfRightIdle = 39,
	RalfRightForward,
	RalfRightBackward,
	RalfRightDamaged,
	RalfRightDead,
	RalfRightWeakPunch,
	RalfRightWeakKick,
	RalfRightStrongPunch,
	RalfRightStrongKick,
	RalfRightNearWeakPunch,
	RalfRightNearWeakKick,
	RalfRightNearStrongPunch,
	RalfRightNearStrongKick,

	// 블루마리 왼쪽 모션

	BluemaryLeftIdle = 52,
	BluemaryLeftForward,
	BluemaryLeftBackward,
	BluemaryLeftDamaged,
	BluemaryLeftDead,
	BluemaryLeftWeakPunch,
	BluemaryLeftWeakKick,
	BluemaryLeftStrongPunch,
	BluemaryLeftStrongKick,
	BluemaryLeftNearWeakPunch,
	BluemaryLeftNearWeakKick,
	BluemaryLeftNearStrongPunch,
	BluemaryLeftNearStrongKick,

	// 블루마리 오른쪽 모션

	BluemaryRightIdle = 65,
	BluemaryRightForward,
	BluemaryRightBackward,
	BluemaryRightDamaged,
	BluemaryRightDead,
	BluemaryRightWeakPunch,
	BluemaryRightWeakKick,
	BluemaryRightStrongPunch,
	BluemaryRightStrongKick,
	BluemaryRightNearWeakPunch,
	BluemaryRightNearWeakKick,
	BluemaryRightNearStrongPunch,
	BluemaryRightNearStrongKick,
};