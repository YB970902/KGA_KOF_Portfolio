#include "AnimManager.h"
#include "Image.h"
#include "KeyManager.h"
#include "Bluemary.h"
#include "Leona.h"
#include "Ralf.h"
#include <map>

using namespace std;

//img->Init(mData.Path[i], mData.sizeX[i], mData.sizeY[i], mData.Animframe[i], 1, true, RGB(255, 0, 255));

//static ChAnimData::AnimStatus playerStatus; // 추후에 전역변수로 설정요망?

Bluemary RalfPlayer;
//static bool isAction = false;		// 추후에 아래 세개의 변수를 isAction으로 통합시킬수 있는지 판단필요 (조건문에 &&을 넣어야 하는건가;)
static bool isAttack = false;		// 공격은 액션인데 공격중 다른공격을 할수는 없다.
static bool isJump = false;			// 점프는 액션인데 점프중에는 공격을 할 수 있지만 자유로운 이동은 불가하다. 반드시 정해진 방향으로만 이동
static bool isSit = false;			// 앉은상태는 액션인데 공격을 할수 있다.
									// isAction이 켜진상태에서 이동을 할 수 없는것을 만들기위해 하나의 트리거로 조건을 거는것은 애매하다는 판단

static ChAnimData::Lookat playerLookat;
static ChAnimData::AnimStatus playerStatus;
static ChAnimData::Acting playerAct;

void AnimManager::Init()
{	
	RalfPlayer.init();
	
	playerAct = ChAnimData::Acting::Act_Idle;
	playerStatus = ChAnimData::AnimStatus::Idle;
	playerLookat = ChAnimData::Lookat::Left_Lookat;

	//RalfPlayer.selectedCharacter = ralf
	
	img = new Image;

	//"Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"
	//Waystring = PlayerCharacter1.Import_Image(PlayerCharacter1.m_Setcharacter,PlayerCharacter1.m_PlayerStatus);
	
	img->Init(RalfPlayer.mData.Path[playerStatus], (int)RalfPlayer.mData.sizeX[playerStatus], (int)RalfPlayer.mData.sizeY[playerStatus],
		(int)RalfPlayer.mData.Animframe[playerStatus], 1, true, RGB(255, 0, 255));

	//img->Init(RalfPlayer.mData.Path[playerStatus], (int)RalfPlayer.mData.sizeX[playerStatus], (int)RalfPlayer.mData.sizeY[playerStatus],
	//	(int)RalfPlayer.mData.Animframe[playerStatus], 1, true, RGB(255, 0, 255));

	frameX = frameY = 0;
	elapsedCount = 0;
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	moveSpeed = 10.0f;
}

void AnimManager::ImgUpdate(ChAnimData::AnimStatus playerStatus)
{
	img->Release();
	img->Init(RalfPlayer.mData.Path[playerStatus], (int)RalfPlayer.mData.sizeX[playerStatus], (int)RalfPlayer.mData.sizeY[playerStatus],
		(int)RalfPlayer.mData.Animframe[playerStatus], 1, true, RGB(255, 0, 255));
}

FLOAT moveAfterAction(FLOAT pos)
{
	if (playerLookat == ChAnimData::Lookat::Right_Lookat)
	{
		pos = pos + (FLOAT)(RalfPlayer.mData.moveAfteraction[playerStatus]);
	}
	else if (playerLookat == ChAnimData::Lookat::Left_Lookat)
	{
		pos = pos - (FLOAT)(RalfPlayer.mData.moveAfteraction[playerStatus]);;
	}
	return pos;
};

void AnimManager::Update()
{
	// 공격
	// 입력키 수정 용이하게 하려면 저 값안에 변수를 넣어야 할듯
	// 어디다 만들지...
	
	if (KeyManager::GetSingleton()->IsOnceKeyDown('A'))
	{
		if (playerLookat == ChAnimData::Lookat::Right_Lookat)
		{
			playerLookat = ChAnimData::Lookat::Left_Lookat;
		}
		else if (playerLookat == ChAnimData::Lookat::Left_Lookat)
		{
			playerLookat = ChAnimData::Lookat::Right_Lookat;
		}
	}

	if (isAttack == false)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown('Z'))
		{
			//playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (playerStatus != ChAnimData::AnimStatus::Weak_Punch)
			{
				frameX = 0;
			}
			isAttack = true;
			playerAct = ChAnimData::Acting::Act_Attack;
			playerStatus = ChAnimData::AnimStatus::Weak_Punch;
			
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('X'))
		{
			//playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (playerStatus != ChAnimData::AnimStatus::Strong_Punch)
			{
				frameX = 0;
			}
			isAttack = true;
			playerAct = ChAnimData::Acting::Act_Attack;
			playerStatus = ChAnimData::AnimStatus::Strong_Punch;
			
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('C'))
		{
			//playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (playerStatus != ChAnimData::AnimStatus::Weak_Kick)
			{
				frameX = 0;
			}
			isAttack = true;
			playerAct = ChAnimData::Acting::Act_Attack;
			playerStatus = ChAnimData::AnimStatus::Weak_Kick;
			
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('V'))
		{
			//playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (playerStatus != ChAnimData::AnimStatus::Strong_Kick)
			{
				frameX = 0;
			}
			isAttack = true;
			playerAct = ChAnimData::Acting::Act_Attack;
			playerStatus = ChAnimData::AnimStatus::Strong_Kick;
			
		}
	}

	if (playerAct != ChAnimData::Acting::Act_Attack)
	{
		if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
		{
			//playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (playerAct != ChAnimData::Acting::Act_Left_Move)
			{
				frameX = 0;
			}
			playerAct = ChAnimData::Acting::Act_Left_Move;
			playerStatus = ChAnimData::AnimStatus::Move_Front;
		}
		else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
		{
			//playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (playerStatus != ChAnimData::AnimStatus::Move_Backward)
			{
				frameX = 0;
			}
			playerAct = ChAnimData::Acting::Act_Right_Move;
			playerStatus = ChAnimData::AnimStatus::Move_Backward;
		}
		else
		{
			//playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
			if (playerAct != ChAnimData::Acting::Act_Idle)
			{
				frameX = 0;
			}
			playerAct = ChAnimData::Acting::Act_Idle;
			playerStatus = ChAnimData::AnimStatus::Idle;
		}
	}
	
	if (playerAct == ChAnimData::Acting::Act_Attack)
		{
		if (playerStatus == ChAnimData::AnimStatus::Weak_Punch)
		{
			AnimManager::ImgUpdate(playerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;
				if (frameX >= RalfPlayer.mData.Animframe[playerStatus])
				{
					frameX = 0;
					isAttack = false;
					playerAct = ChAnimData::Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (playerStatus == ChAnimData::AnimStatus::Strong_Punch)
		{
			AnimManager::ImgUpdate(playerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;
				if (frameX >= RalfPlayer.mData.Animframe[playerStatus])
				{
					frameX = 0;
					isAttack = false;
					playerAct = ChAnimData::Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (playerStatus == ChAnimData::AnimStatus::Weak_Kick)
		{
			AnimManager::ImgUpdate(playerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;
				if (frameX >= RalfPlayer.mData.Animframe[playerStatus])
				{
					frameX = 0;
					isAttack = false;
					playerAct = ChAnimData::Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (playerStatus == ChAnimData::AnimStatus::Strong_Kick)
		{
			AnimManager::ImgUpdate(playerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;
				if (frameX >= RalfPlayer.mData.Animframe[playerStatus])
				{
					frameX = 0;
					isAttack = false;
					playerAct = ChAnimData::Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
	}

	else if (playerAct != ChAnimData::Acting::Act_Attack) // 공격상태에서는 Idle과 Move가 작동하면 안되므로 공격상태인지 아닌지 판별
	{
		if (playerStatus == ChAnimData::AnimStatus::Move_Front || playerStatus == ChAnimData::AnimStatus::Move_Backward) //Move일때
		{
			// 왼쪽으로 움직이기
			if (playerAct == ChAnimData::Acting::Act_Left_Move)
			{
				AnimManager::ImgUpdate(playerStatus);
				elapsedCount++;
				if (elapsedCount >= 8)
				{
					if (playerLookat == ChAnimData::Lookat::Right_Lookat)
					{
						frameX--;
						if (frameX < 0)
						{
							frameX = RalfPlayer.mData.Animframe[playerStatus] - 1;
						}
					}
					else if (playerLookat == ChAnimData::Lookat::Left_Lookat)
					{
						frameX++;
						if (frameX >= RalfPlayer.mData.Animframe[playerStatus] - 1)
						{
							frameX = 0;
						}
					}
					pos.x -= moveSpeed;
					elapsedCount = 0;
				}

			}
			// 오른쪽으로 움직이기
			else if (playerAct == ChAnimData::Acting::Act_Right_Move)
			{
				AnimManager::ImgUpdate(playerStatus);
				
				elapsedCount++;
				if (elapsedCount >= 8)
				{
					if (playerLookat == ChAnimData::Lookat::Right_Lookat)
					{
						frameX++;
						if (frameX >= RalfPlayer.mData.Animframe[playerStatus] - 1)
						{
							frameX = 0;
						}
					}
					else if (playerLookat == ChAnimData::Lookat::Left_Lookat)
					{
						frameX--;
						if (frameX < 0)
						{
							frameX = RalfPlayer.mData.Animframe[playerStatus] - 1;
						}
					}
					pos.x += moveSpeed;
					elapsedCount = 0;
				}
			}
		}

		else if (playerAct == ChAnimData::Acting::Act_Idle) // Idle 일때
		{
			AnimManager::ImgUpdate(playerStatus);
			
			elapsedCount++;
			if (elapsedCount >= 8)
			{
				frameX++;
				if (frameX >= RalfPlayer.mData.Animframe[playerStatus])
				{
					frameX = 0;
				}
				elapsedCount = 0;
			}
		} 
	}

	baseX = RalfPlayer.mData.sizeX[playerStatus] / (int)RalfPlayer.mData.Animframe[ChAnimData::AnimStatus::Idle];
	baseY = (int)RalfPlayer.mData.sizeY[ChAnimData::AnimStatus::Idle];

}

	// 실습1. 뒤로 움직이기 + 실제 위치 이동
	// 과제. 팀작업 때 쓸 리소스 찾아보기
	// (제자리 서있기, 앞으로 이동, 뒤로 이동, 작은 손/발, 큰 손/발
	// , 피격(맞았을 때)

void AnimManager::Render(HDC hdc)
{
	if (img)
	{
		img->Render(hdc, pos.x, pos.y, frameX, frameY, baseX, baseY, playerStatus, playerLookat);
	}
}

void AnimManager::Release()
{
	if (img)
	{
		delete img;
		img = nullptr;
	}
}
