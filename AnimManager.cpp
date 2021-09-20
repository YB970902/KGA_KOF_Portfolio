#include "AnimManager.h"
#include "Image.h"
#include "KeyManager.h"
#include <map>


using namespace std;

//img->Init(mData.Path[i], mData.sizeX[i], mData.sizeY[i], mData.Animframe[i], 1, true, RGB(255, 0, 255));

//static ChAnimData::AnimStatus playerStatus; // ���Ŀ� ���������� �������?

Ralf RalfPlayer;
static bool isAttack = false;

void AnimManager::Init()
{	
	RalfPlayer.init();
	
	playerAct = ChAnimData::Acting::Act_Idle;
	playerStatus = ChAnimData::AnimStatus::Idle;
	playerLookat = ChAnimData::Lookat::Right;

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

void AnimManager::Update()
{
	// ����
	// �Է�Ű ���� �����ϰ� �Ϸ��� �� ���ȿ� ������ �־�� �ҵ�
	// ���� ������...
	
	if (KeyManager::GetSingleton()->IsOnceKeyDown('A'))
	{
		playerLookat = ChAnimData::Lookat::Left;
	}

	if (isAttack == false)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown('Z'))
		{
			//playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
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
			//playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
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
			//playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
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
			//playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
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
			//playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
			if (playerStatus != ChAnimData::AnimStatus::Move)
			{
				frameX = 0;
			}
			playerAct = ChAnimData::Acting::Act_Forward;
			playerStatus = ChAnimData::AnimStatus::Move;
		}
		else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
		{
			//playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
			if (playerStatus != ChAnimData::AnimStatus::Move)
			{
				frameX = 0;
			}
			playerAct = ChAnimData::Acting::Act_Backward;
			playerStatus = ChAnimData::AnimStatus::Move;
		}
		else
		{
			//playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
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
				}
				elapsedCount = 0;
			}
		}
	}

	else if (playerAct != ChAnimData::Acting::Act_Attack) // ���ݻ��¿����� Idle�� Move�� �۵��ϸ� �ȵǹǷ� ���ݻ������� �ƴ��� �Ǻ�
	{
		if (playerStatus == ChAnimData::AnimStatus::Move) //Move�϶�
		{
			// �������� �����̱�
			if (playerAct == ChAnimData::Acting::Act_Forward)
			{
				AnimManager::ImgUpdate(playerStatus);
				elapsedCount++;
				if (elapsedCount >= 8)
				{
					frameX++;
					pos.x -= moveSpeed;
					if (frameX >= 7)
					{
						frameX = 0;
					}
					elapsedCount = 0;
				}

			}
			// ���������� �����̱�
			else if (playerAct == ChAnimData::Acting::Act_Backward)
			{
				AnimManager::ImgUpdate(playerStatus);
				
				elapsedCount++;
				if (elapsedCount >= 9)
				{
					frameX--;
					pos.x += moveSpeed;
					if (frameX < 0)
					{
						frameX = 7;
					}
					elapsedCount = 0;
				}
			}
		}

		else if (playerAct == ChAnimData::Acting::Act_Idle) // Idle �϶�
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

}

	// �ǽ�1. �ڷ� �����̱� + ���� ��ġ �̵�
	// ����. ���۾� �� �� ���ҽ� ã�ƺ���
	// (���ڸ� ���ֱ�, ������ �̵�, �ڷ� �̵�, ���� ��/��, ū ��/��
	// , �ǰ�(�¾��� ��)

void AnimManager::Render(HDC hdc)
{
	if (img)
	{
		img->Render(hdc, pos.x, pos.y, frameX, frameY, RalfPlayer.mData.sizeX[playerStatus], RalfPlayer.mData.sizeY[playerStatus],playerLookat);
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
