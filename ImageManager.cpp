#include "ImageManager.h"
#include "Image.h"
#include "Character.h"
#include <map>

using namespace std;

void ImageManager::init()
{
	// 레오나 왼쪽

	mimageList[eImageTag::LeonaLeft] = nullptr;
	mimageList[eImageTag::LeonaLeftIdle] = new Image;
	mimageList[eImageTag::LeonaLeftForward] = new Image;
	mimageList[eImageTag::LeonaLeftBackward] = new Image;
	mimageList[eImageTag::LeonaLeftDamaged] = new Image;
	mimageList[eImageTag::LeonaLeftDead] = new Image;
	mimageList[eImageTag::LeonaLeftWeakPunch] = new Image;
	mimageList[eImageTag::LeonaLeftWeakKick] = new Image;
	mimageList[eImageTag::LeonaLeftStrongPunch] = new Image;
	mimageList[eImageTag::LeonaLeftStrongKick] = new Image;
	mimageList[eImageTag::LeonaLeftNearWeakPunch] = new Image;
	mimageList[eImageTag::LeonaLeftNearWeakKick] = new Image;
	mimageList[eImageTag::LeonaLeftNearStrongPunch] = new Image;
	mimageList[eImageTag::LeonaLeftNearStrongKick] = new Image;

	mimageList[eImageTag::LeonaLeftIdle]->Init("Image/Leona_Database_IMG/Leona_Idle.bmp", 3680, 120, 46, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftForward]->Init("Image/Leona_Database_IMG/Leona_Walk_Front.bmp", 800, 120, 10, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftBackward]->Init("Image/Leona_Database_IMG/Leona_Walf_Back.bmp", 640, 124, 8, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftDamaged]->Init("Image/Leona_Database_IMG/Leona_Damaged.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftDead]->Init("Image/Leona_Database_IMG/Leona_Dead.bmp", 2480, 190, 20, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftWeakPunch]->Init("Image/Leona_Database_IMG/Leona_Weak_Punch.bmp", 1400, 140, 5, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftWeakKick]->Init("Image/Leona_Database_IMG/Leona_Weak_Kick.bmp", 2240, 140, 8, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftStrongPunch]->Init("Image/Leona_Database_IMG/Leona_Strong_Punch.bmp", 3080, 140, 11, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftStrongKick]->Init("Image/Leona_Database_IMG/Leona_Strong_Kick.bmp", 3920, 140, 14, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftNearWeakPunch]->Init("Image/Leona_Database_IMG/Leona_Near_Weak_Punch.bmp", 680, 170, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftNearWeakKick]->Init("Image/Leona_Database_IMG/Leona_Near_Weak_Kick.bmp", 850, 170, 5, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftNearStrongPunch]->Init("Image/Leona_Database_IMG/Leona_Near_Strong_Punch.bmp", 2040, 170, 12, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaLeftNearStrongKick]->Init("Image/Leona_Database_IMG/Leona_Near_Strong_Kick.bmp", 1530, 170, 9, 1, true, RGB(255, 0, 255));

	// 레오나 오른쪽

	mimageList[eImageTag::LeonaRight] = nullptr;
	mimageList[eImageTag::LeonaRightIdle] = new Image;
	mimageList[eImageTag::LeonaRightForward] = new Image;
	mimageList[eImageTag::LeonaRightBackward] = new Image;
	mimageList[eImageTag::LeonaRightDamaged] = new Image;
	mimageList[eImageTag::LeonaRightDead] = new Image;
	mimageList[eImageTag::LeonaRightWeakPunch] = new Image;
	mimageList[eImageTag::LeonaRightWeakKick] = new Image;
	mimageList[eImageTag::LeonaRightStrongPunch] = new Image;
	mimageList[eImageTag::LeonaRightStrongKick] = new Image;
	mimageList[eImageTag::LeonaRightNearWeakPunch] = new Image;
	mimageList[eImageTag::LeonaRightNearWeakKick] = new Image;
	mimageList[eImageTag::LeonaRightNearStrongPunch] = new Image;
	mimageList[eImageTag::LeonaRightNearStrongKick] = new Image;
							   
	mimageList[eImageTag::LeonaRightIdle]->Init("Image/Leona_Database_IMG/Leona_Idle.bmp", 3680, 120, 46, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightForward]->Init("Image/Leona_Database_IMG/Leona_Walk_Front.bmp", 800, 120, 10, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightBackward]->Init("Image/Leona_Database_IMG/Leona_Walf_Back.bmp", 640, 124, 8, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightDamaged]->Init("Image/Leona_Database_IMG/Leona_Damaged.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightDead]->Init("Image/Leona_Database_IMG/Leona_Dead.bmp", 2480, 190, 20, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightWeakPunch]->Init("Image/Leona_Database_IMG/Leona_Weak_Punch.bmp", 1400, 140, 5, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightWeakKick]->Init("Image/Leona_Database_IMG/Leona_Weak_Kick.bmp", 2240, 140, 8, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightStrongPunch]->Init("Image/Leona_Database_IMG/Leona_Strong_Punch.bmp", 3080, 140, 11, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightStrongKick]->Init("Image/Leona_Database_IMG/Leona_Strong_Kick.bmp", 3920, 140, 14, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightNearWeakPunch]->Init("Image/Leona_Database_IMG/Leona_Near_Weak_Punch.bmp", 680, 170, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightNearWeakKick]->Init("Image/Leona_Database_IMG/Leona_Near_Weak_Kick.bmp", 850, 170, 5, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightNearStrongPunch]->Init("Image/Leona_Database_IMG/Leona_Near_Strong_Punch.bmp", 2040, 170, 12, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::LeonaRightNearStrongKick]->Init("Image/Leona_Database_IMG/Leona_Near_Strong_Kick.bmp", 1530, 170, 9, 1, true, RGB(255, 0, 255));
	
	// 랄프 왼쪽

	mimageList[eImageTag::RalfLeft] = nullptr;
	mimageList[eImageTag::RalfLeftIdle] = new Image;
	mimageList[eImageTag::RalfLeftForward] = new Image;
	mimageList[eImageTag::RalfLeftBackward] = new Image;
	mimageList[eImageTag::RalfLeftDamaged] = new Image;
	mimageList[eImageTag::RalfLeftDead] = new Image;
	mimageList[eImageTag::RalfLeftWeakPunch] = new Image;
	mimageList[eImageTag::RalfLeftWeakKick] = new Image;
	mimageList[eImageTag::RalfLeftStrongPunch] = new Image;
	mimageList[eImageTag::RalfLeftStrongKick] = new Image;
	mimageList[eImageTag::RalfLeftNearWeakPunch] = new Image;
	mimageList[eImageTag::RalfLeftNearWeakKick] = new Image;
	mimageList[eImageTag::RalfLeftNearStrongPunch] = new Image;
	mimageList[eImageTag::RalfLeftNearStrongKick] = new Image;

	mimageList[eImageTag::RalfLeftIdle]->Init("Image/Ralf_Database_IMG/Ralf_Idle.bmp", 2345, 120, 35, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftForward]->Init("Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp", 528, 120, 8, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftBackward]->Init("Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp", 528, 120, 8, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftDamaged]->Init("Image/Ralf_Database_IMG/Ralf_Damaged.bmp", 568, 120, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftDead]->Init("Image/Ralf_Database_IMG/Ralf_Dead.bmp", 2850, 190, 19, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftWeakPunch]->Init("Image/Ralf_Database_IMG/Ralf_Weak_Punch.bmp", 488, 120, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftWeakKick]->Init("Image/Ralf_Database_IMG/Ralf_Weak_Kick.bmp", 768, 120, 6, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftStrongPunch]->Init("Image/Ralf_Database_IMG/Ralf_Strong_Punch.bmp", 1680, 120, 8, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftStrongKick]->Init("Image/Ralf_Database_IMG/Ralf_Strong_Kick.bmp", 2352, 120, 12, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftNearWeakPunch]->Init("Image/Ralf_Database_IMG/Ralf_Near_Weak_Punch.bmp", 488, 120, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftNearWeakKick]->Init("Image/Ralf_Database_IMG/Ralf_Near_Weak_Kick.bmp", 600, 130, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftNearStrongPunch]->Init("Image/Ralf_Database_IMG/Ralf_Near_Strong_Punch.bmp", 2100, 130, 14, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfLeftNearStrongKick]->Init("Image/Ralf_Database_IMG/Ralf_Near_Strong_Kick.bmp", 1200, 130, 8, 1, true, RGB(255, 0, 255));

	// 랄프 오른쪽

	mimageList[eImageTag::RalfRight] = nullptr;
	mimageList[eImageTag::RalfRightIdle] = new Image;
	mimageList[eImageTag::RalfRightForward] = new Image;
	mimageList[eImageTag::RalfRightBackward] = new Image;
	mimageList[eImageTag::RalfRightDamaged] = new Image;
	mimageList[eImageTag::RalfRightDead] = new Image;
	mimageList[eImageTag::RalfRightWeakPunch] = new Image;
	mimageList[eImageTag::RalfRightWeakKick] = new Image;
	mimageList[eImageTag::RalfRightStrongPunch] = new Image;
	mimageList[eImageTag::RalfRightStrongKick] = new Image;
	mimageList[eImageTag::RalfRightNearWeakPunch] = new Image;
	mimageList[eImageTag::RalfRightNearWeakKick] = new Image;
	mimageList[eImageTag::RalfRightNearStrongPunch] = new Image;
	mimageList[eImageTag::RalfRightNearStrongKick] = new Image;

	mimageList[eImageTag::RalfRightIdle]->Init("Image/Ralf_Database_IMG/Ralf_Idle.bmp", 2345, 120, 35, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightForward]->Init("Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp", 528, 120, 8, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightBackward]->Init("Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp", 528, 120, 8, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightDamaged]->Init("Image/Ralf_Database_IMG/Ralf_Damaged.bmp", 568, 120, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightDead]->Init("Image/Ralf_Database_IMG/Ralf_Dead.bmp", 2850, 190, 19, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightWeakPunch]->Init("Image/Ralf_Database_IMG/Ralf_Weak_Punch.bmp", 488, 120, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightWeakKick]->Init("Image/Ralf_Database_IMG/Ralf_Weak_Kick.bmp", 768, 120, 6, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightStrongPunch]->Init("Image/Ralf_Database_IMG/Ralf_Strong_Punch.bmp", 1680, 120, 8, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightStrongKick]->Init("Image/Ralf_Database_IMG/Ralf_Strong_Kick.bmp", 2352, 120, 12, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightNearWeakPunch]->Init("Image/Ralf_Database_IMG/Ralf_Near_Weak_Punch.bmp", 488, 120, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightNearWeakKick]->Init("Image/Ralf_Database_IMG/Ralf_Near_Weak_Kick.bmp", 600, 130, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightNearStrongPunch]->Init("Image/Ralf_Database_IMG/Ralf_Near_Strong_Punch.bmp", 2100, 130, 14, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::RalfRightNearStrongKick]->Init("Image/Ralf_Database_IMG/Ralf_Near_Strong_Kick.bmp", 1200, 130, 8, 1, true, RGB(255, 0, 255));

	// 마리 왼쪽

	mimageList[eImageTag::BluemaryLeft] = nullptr;
	mimageList[eImageTag::BluemaryLeftIdle] = new Image;
	mimageList[eImageTag::BluemaryLeftForward] = new Image;
	mimageList[eImageTag::BluemaryLeftBackward] = new Image;
	mimageList[eImageTag::BluemaryLeftDamaged] = new Image;
	mimageList[eImageTag::BluemaryLeftDead] = new Image;
	mimageList[eImageTag::BluemaryLeftWeakPunch] = new Image;
	mimageList[eImageTag::BluemaryLeftWeakKick] = new Image;
	mimageList[eImageTag::BluemaryLeftStrongPunch] = new Image;
	mimageList[eImageTag::BluemaryLeftStrongKick] = new Image;
	mimageList[eImageTag::BluemaryLeftNearWeakPunch] = new Image;
	mimageList[eImageTag::BluemaryLeftNearWeakKick] = new Image;
	mimageList[eImageTag::BluemaryLeftNearStrongPunch] = new Image;
	mimageList[eImageTag::BluemaryLeftNearStrongKick] = new Image;

	mimageList[eImageTag::BluemaryLeftIdle]->Init("Image/Bluemary_Database_IMG/Bluemary_Idle.bmp", 720, 100, 12, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftForward]->Init("Image/Bluemary_Database_IMG/Bluemary_Walk_Front.bmp", 600, 120, 12, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftBackward]->Init("Image/Bluemary_Database_IMG/Bluemary_Walk_Back.bmp", 360, 120, 10, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftDamaged]->Init("Image/Bluemary_Database_IMG/Bluemary_Damaged_2.bmp", 270, 100, 3, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftDead]->Init("Image/Bluemary_Database_IMG/Bluemary_Dead_2.bmp", 2100, 130, 19, 14, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftWeakPunch]->Init("Image/Bluemary_Database_IMG/Bluemary_Weak_Punch.bmp", 400, 100, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftWeakKick]->Init("Image/Bluemary_Database_IMG/Bluemary_Weak_Kick.bmp", 1080, 120, 9, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftStrongPunch]->Init("Image/Bluemary_Database_IMG/Bluemary_Strong_Punch.bmp", 4840, 120, 22, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftStrongKick]->Init("Image/Bluemary_Database_IMG/Bluemary_Strong_Kick.bmp", 2160, 130, 12, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftNearWeakPunch]->Init("Image/Bluemary_Database_IMG/Bluemary_Near_Weak_Punch.bmp", 300, 104, 5, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftNearWeakKick]->Init("Image/Bluemary_Database_IMG/Bluemary_Near_Weak_Kick.bmp", 490, 130, 7, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftNearStrongPunch]->Init("Image/Bluemary_Database_IMG/Bluemary_Near_Strong_Punch.bmp", 1800, 150, 15, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryLeftNearStrongKick]->Init("Image/Bluemary_Database_IMG/Bluemary_Near_Strong_Kick.bmp", 1300, 140, 13, 1, true, RGB(255, 0, 255));

	// 마리 오른쪽

	mimageList[eImageTag::BluemaryRight] = nullptr;
	mimageList[eImageTag::BluemaryRightIdle] = new Image;
	mimageList[eImageTag::BluemaryRightForward] = new Image;
	mimageList[eImageTag::BluemaryRightBackward] = new Image;
	mimageList[eImageTag::BluemaryRightDamaged] = new Image;
	mimageList[eImageTag::BluemaryRightDead] = new Image;
	mimageList[eImageTag::BluemaryRightWeakPunch] = new Image;
	mimageList[eImageTag::BluemaryRightWeakKick] = new Image;
	mimageList[eImageTag::BluemaryRightStrongPunch] = new Image;
	mimageList[eImageTag::BluemaryRightStrongKick] = new Image;
	mimageList[eImageTag::BluemaryRightNearWeakPunch] = new Image;
	mimageList[eImageTag::BluemaryRightNearWeakKick] = new Image;
	mimageList[eImageTag::BluemaryRightNearStrongPunch] = new Image;
	mimageList[eImageTag::BluemaryRightNearStrongKick] = new Image;

	mimageList[eImageTag::BluemaryRightIdle]->Init("Image/Bluemary_Database_IMG/Bluemary_Idle.bmp", 720, 100, 12, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightForward]->Init("Image/Bluemary_Database_IMG/Bluemary_Walk_Front.bmp", 600, 120, 12, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightBackward]->Init("Image/Bluemary_Database_IMG/Bluemary_Walk_Back.bmp", 360, 120, 10, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightDamaged]->Init("Image/Bluemary_Database_IMG/Bluemary_Damaged_2.bmp", 270, 100, 3, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightDead]->Init("Image/Bluemary_Database_IMG/Bluemary_Dead_2.bmp", 2100, 130, 19, 14, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightWeakPunch]->Init("Image/Bluemary_Database_IMG/Bluemary_Weak_Punch.bmp", 400, 100, 4, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightWeakKick]->Init("Image/Bluemary_Database_IMG/Bluemary_Weak_Kick.bmp", 1080, 120, 9, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightStrongPunch]->Init("Image/Bluemary_Database_IMG/Bluemary_Strong_Punch.bmp", 4840, 120, 22, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightStrongKick]->Init("Image/Bluemary_Database_IMG/Bluemary_Strong_Kick.bmp", 2160, 130, 12, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightNearWeakPunch]->Init("Image/Bluemary_Database_IMG/Bluemary_Near_Weak_Punch.bmp", 300, 104, 5, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightNearWeakKick]->Init("Image/Bluemary_Database_IMG/Bluemary_Near_Weak_Kick.bmp", 490, 130, 7, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightNearStrongPunch]->Init("Image/Bluemary_Database_IMG/Bluemary_Near_Strong_Punch.bmp", 1800, 150, 15, 1, true, RGB(255, 0, 255));
	mimageList[eImageTag::BluemaryRightNearStrongKick]->Init("Image/Bluemary_Database_IMG/Bluemary_Near_Strong_Kick.bmp", 1300, 140, 13, 1, true, RGB(255, 0, 255));
}
