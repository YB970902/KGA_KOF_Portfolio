#pragma once
#include "Config.h"
#include "Character.h"
#include "Singleton.h"
#include <map>

enum class eImageTag
{
	// 레오나 왼쪽 모션

	LeonaLeft=0,
	LeonaLeftIdle,
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
	LeonaRight=14,
	LeonaRightIdle,
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
	RalfLeft=28,
	RalfLeftIdle,
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
	RalfRight=42,
	RalfRightIdle,
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
	BluemaryLeft=56,
	BluemaryLeftIdle,
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
	BluemaryRight=70,
	BluemaryRightIdle,
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

class ImageManager : public Singleton<ImageManager>
{
private:
	map<eImageTag, Image*> mimageList;

public:
	void init();

};

