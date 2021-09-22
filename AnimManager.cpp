#include "AnimManager.h"
#include "Image.h"
#include "KeyManager.h"
#include "Bluemary.h"
#include "Leona.h"
#include "Ralf.h"
#include <map>

using namespace std;

//img->Init(mData.Path[i], mData.sizeX[i], mData.sizeY[i], mData.Animframe[i], 1, true, RGB(255, 0, 255));

//static ChAnimData::AnimStatus Player.playerStatus; // ���Ŀ� ���������� �������?

Ralf Player;

void AnimManager::Init()
{	
	Player.init();
	
	Player.playerAct = ChAnimData::Acting::Act_Idle;
	Player.playerStatus = ChAnimData::AnimStatus::Idle;
	Player.playerLookat = ChAnimData::Lookat::Left_Lookat;

	//Player.selectedCharacter = ralf
	
	img = new Image;

	//"Image/Ralf_Database_IMG/Ralf_Walk_Cycle.bmp"
	//Waystring = PlayerCharacter1.Import_Image(PlayerCharacter1.m_Setcharacter,PlayerCharacter1.m_Player.playerStatus);
	
	img->Init(Player.mData.Path[Player.playerStatus], (int)Player.mData.sizeX[Player.playerStatus], (int)Player.mData.sizeY[Player.playerStatus],
		(int)Player.mData.Animframe[Player.playerStatus], 1, true, RGB(255, 0, 255));

	//img->Init(Player.mData.Path[playerStatus], (int)Player.mData.sizeX[playerStatus], (int)Player.mData.sizeY[playerStatus],
	//	(int)Player.mData.Animframe[playerStatus], 1, true, RGB(255, 0, 255));

	frameX = frameY = 0;
	elapsedCount = 0;
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	moveSpeed = 10.0f;
}

void AnimManager::ImgUpdate(ChAnimData::AnimStatus playerStatus)
{
	img->Release();
	img->Init(Player.mData.Path[playerStatus], (int)Player.mData.sizeX[playerStatus], (int)Player.mData.sizeY[playerStatus],
		(int)Player.mData.Animframe[playerStatus], 1, true, RGB(255, 0, 255));
}

FLOAT moveAfterAction(FLOAT pos)
{
	if (Player.playerLookat == ChAnimData::Lookat::Right_Lookat)
	{
		pos = pos + (FLOAT)(Player.mData.moveAfteraction[Player.playerStatus]);
	}
	else if (Player.playerLookat == ChAnimData::Lookat::Left_Lookat)
	{
		pos = pos - (FLOAT)(Player.mData.moveAfteraction[Player.playerStatus]);;
	}
	return pos;
};

void AnimManager::Update()
{
	// ����
	// �Է�Ű ���� �����ϰ� �Ϸ��� �� ���ȿ� ������ �־�� �ҵ�
	// ���� ������...
	
	if (KeyManager::GetSingleton()->IsOnceKeyDown('A'))
	{
		if (Player.playerLookat == ChAnimData::Lookat::Right_Lookat)
		{
			Player.playerLookat = ChAnimData::Lookat::Left_Lookat;
		}
		else if (Player.playerLookat == ChAnimData::Lookat::Left_Lookat)
		{
			Player.playerLookat = ChAnimData::Lookat::Right_Lookat;
		}
	}

	if (Player.isAttack == false)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown('Z'))
		{
			//Player.playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
			if (Player.playerStatus != ChAnimData::AnimStatus::Weak_Punch)
			{
				frameX = 0;
			}
			Player.isAttack = true;
			Player.playerAct = ChAnimData::Acting::Act_Attack;
			Player.playerStatus = ChAnimData::AnimStatus::Weak_Punch;
			
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('X'))
		{
			//Player.playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
			if (Player.playerStatus != ChAnimData::AnimStatus::Strong_Punch)
			{
				frameX = 0;
			}
			Player.isAttack = true;
			Player.playerAct = ChAnimData::Acting::Act_Attack;
			Player.playerStatus = ChAnimData::AnimStatus::Strong_Punch;
			
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('C'))
		{
			//Player.playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
			if (Player.playerStatus != ChAnimData::AnimStatus::Weak_Kick)
			{
				frameX = 0;
			}
			Player.isAttack = true;
			Player.playerAct = ChAnimData::Acting::Act_Attack;
			Player.playerStatus = ChAnimData::AnimStatus::Weak_Kick;
			
		}
		else if (KeyManager::GetSingleton()->IsOnceKeyDown('V'))
		{
			//Player.playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
			if (Player.playerStatus != ChAnimData::AnimStatus::Strong_Kick)
			{
				frameX = 0;
			}
			Player.isAttack = true;
			Player.playerAct = ChAnimData::Acting::Act_Attack;
			Player.playerStatus = ChAnimData::AnimStatus::Strong_Kick;
			
		}
	}

	if (Player.playerAct != ChAnimData::Acting::Act_Attack)
	{
		if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
		{
			//Player.playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���

			if (Player.playerAct != ChAnimData::Acting::Act_Left_Move)
			{
				frameX = 0;
			}

			if (Player.playerLookat == ChAnimData::Lookat::Left_Lookat)
			{
				Player.playerStatus = ChAnimData::AnimStatus::Move_Front;
			}
			else if (Player.playerLookat == ChAnimData::Lookat::Right_Lookat)
			{
				Player.playerStatus = ChAnimData::AnimStatus::Move_Backward;
			}

			Player.playerAct = ChAnimData::Acting::Act_Left_Move;
		}
		else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
		{
			//Player.playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
			if (Player.playerAct != ChAnimData::Acting::Act_Right_Move)
			{
				frameX = 0;
			}
			Player.playerAct = ChAnimData::Acting::Act_Right_Move;

			if (Player.playerLookat == ChAnimData::Lookat::Left_Lookat)
			{
				Player.playerStatus = ChAnimData::AnimStatus::Move_Backward;
			}
			else if (Player.playerLookat == ChAnimData::Lookat::Right_Lookat)
			{
				Player.playerStatus = ChAnimData::AnimStatus::Move_Front;
			}
		}
		else
		{
			//Player.playerLookat = ChAnimData::Lookat::Left; // ���Ŀ� �� �޾ƾ���
			if (Player.playerAct != ChAnimData::Acting::Act_Idle)
			{
				frameX = 0;
			}
			Player.playerAct = ChAnimData::Acting::Act_Idle;
			Player.playerStatus = ChAnimData::AnimStatus::Idle;
		}
	}
	
	if (Player.playerAct == ChAnimData::Acting::Act_Attack)
		{
		if (Player.playerStatus == ChAnimData::AnimStatus::Weak_Punch)
		{
			AnimManager::ImgUpdate(Player.playerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;
				if (frameX >= Player.mData.Animframe[Player.playerStatus])
				{
					frameX = 0;
					Player.isAttack = false;
					Player.playerAct = ChAnimData::Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (Player.playerStatus == ChAnimData::AnimStatus::Strong_Punch)
		{
			AnimManager::ImgUpdate(Player.playerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;
				if (frameX >= Player.mData.Animframe[Player.playerStatus])
				{
					frameX = 0;
					Player.isAttack = false;
					Player.playerAct = ChAnimData::Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (Player.playerStatus == ChAnimData::AnimStatus::Weak_Kick)
		{
			AnimManager::ImgUpdate(Player.playerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;
				if (frameX >= Player.mData.Animframe[Player.playerStatus])
				{
					frameX = 0;
					Player.isAttack = false;
					Player.playerAct = ChAnimData::Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
		else if (Player.playerStatus == ChAnimData::AnimStatus::Strong_Kick)
		{
			AnimManager::ImgUpdate(Player.playerStatus);
			elapsedCount++;
			if (elapsedCount >= 4)
			{
				frameX++;
				if (frameX >= Player.mData.Animframe[Player.playerStatus])
				{
					frameX = 0;
					Player.isAttack = false;
					Player.playerAct = ChAnimData::Acting::Act_Idle;
					pos.x = moveAfterAction(pos.x);
				}
				elapsedCount = 0;
			}
		}
	}

	else if (Player.playerAct != ChAnimData::Acting::Act_Attack) // ���ݻ��¿����� Idle�� Move�� �۵��ϸ� �ȵǹǷ� ���ݻ������� �ƴ��� �Ǻ�
	{
		if (Player.playerStatus == ChAnimData::AnimStatus::Move_Front || Player.playerStatus == ChAnimData::AnimStatus::Move_Backward) //Move�϶�
		{
			// �������� �����̱�
			if (Player.playerAct == ChAnimData::Acting::Act_Left_Move)
			{
				AnimManager::ImgUpdate(Player.playerStatus);
				elapsedCount++;
				if (elapsedCount >= 8)
				{
					if (Player.playerLookat == ChAnimData::Lookat::Right_Lookat)
					{
						if (Player.notReverse == 1)
						{
							frameX++;
							if (frameX >= Player.mData.Animframe[Player.playerStatus] - 1)
							{
								frameX = 0;
							}
						}
						else
						{
							frameX--;
							if (frameX < 0)
							{
								frameX = Player.mData.Animframe[Player.playerStatus] - 1;
							}
						}
					}
					else if (Player.playerLookat == ChAnimData::Lookat::Left_Lookat)
					{
						frameX++;
						if (frameX >= Player.mData.Animframe[Player.playerStatus] - 1)
						{
							frameX = 0;
						}
					}
					pos.x -= moveSpeed;
					elapsedCount = 0;
				}

			}
			// ���������� �����̱�
			else if (Player.playerAct == ChAnimData::Acting::Act_Right_Move)
			{
				AnimManager::ImgUpdate(Player.playerStatus);

				elapsedCount++;
				if (elapsedCount >= 8)//(int)Player.AnimSpeed[Player.playerStatus])
				{
					if (Player.playerLookat == ChAnimData::Lookat::Right_Lookat)
					{
						frameX++;
						if (frameX >= Player.mData.Animframe[Player.playerStatus] - 1)
						{
							frameX = 0;
						}
					}
					else if (Player.playerLookat == ChAnimData::Lookat::Left_Lookat)
					{
						if (Player.notReverse == 1)
						{
							frameX++;
							if (frameX >= Player.mData.Animframe[Player.playerStatus] - 1)
							{
								frameX = 0;
							}
						}
						else
						{
							frameX--;
							if (frameX < 0)
							{
								frameX = Player.mData.Animframe[Player.playerStatus] - 1;
							}
						}						
					}
					pos.x += moveSpeed;
					elapsedCount = 0;
				}
			}
		}

		else if (Player.playerAct == ChAnimData::Acting::Act_Idle) // Idle �϶�
		{
			AnimManager::ImgUpdate(Player.playerStatus);

			elapsedCount++;
			if (elapsedCount >= 8)
			{
				frameX++;
				if (frameX >= Player.mData.Animframe[Player.playerStatus])
				{
					frameX = 0;
				}
				elapsedCount = 0;
			}
		}
	}

	baseX = Player.mData.sizeX[Player.playerStatus] / (int)Player.mData.Animframe[ChAnimData::AnimStatus::Idle];
	baseY = (int)Player.mData.sizeY[ChAnimData::AnimStatus::Idle];

}

	// �ǽ�1. �ڷ� �����̱� + ���� ��ġ �̵�
	// ����. ���۾� �� �� ���ҽ� ã�ƺ���
	// (���ڸ� ���ֱ�, ������ �̵�, �ڷ� �̵�, ���� ��/��, ū ��/��
	// , �ǰ�(�¾��� ��)

void AnimManager::Render(HDC hdc)
{
	if (img)
	{
		img->Render(hdc, pos.x, pos.y, frameX, frameY, baseX, baseY, Player.playerStatus, Player.playerLookat);
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
