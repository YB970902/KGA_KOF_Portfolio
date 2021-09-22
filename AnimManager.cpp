#include "AnimManager.h"
#include "Image.h"
#include "KeyManager.h"
#include "Bluemary.h"
#include "Leona.h"
#include "Ralf.h"
#include <map>

using namespace std;

//img->Init(mData.Path[i], mData.sizeX[i], mData.sizeY[i], mData.Animframe[i], 1, true, RGB(255, 0, 255));

//static ChAnimData::AnimStatus Player.playerStatus; // 추후에 전역변수로 설정요망?

Leona Player;

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



	mHP = 100;

	shape.left = (int)pos.x - ((Player.mData.sizeX[Player.playerStatus] / Player.mData.Animframe[Player.playerStatus]) / 2);
	shape.top = (int)pos.y - (Player.mData.sizeY[Player.playerStatus] / 2);
	shape.right = (int)pos.x + ((Player.mData.sizeX[Player.playerStatus] / Player.mData.Animframe[Player.playerStatus]) / 2);
	shape.bottom = (int)pos.y + (Player.mData.sizeY[Player.playerStatus] / 2);

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
	// 공격
	// 입력키 수정 용이하게 하려면 저 값안에 변수를 넣어야 할듯
	// 어디다 만들지...
	
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
			//Player.playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
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
			//Player.playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
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
			//Player.playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
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
			//Player.playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
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
			//Player.playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함

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
			//Player.playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
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
			//Player.playerLookat = ChAnimData::Lookat::Left; // 추후에 값 받아야함
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

				if (frameX == 2)
				{
					OnWeakPunchHitBox((int)Player.playerLookat);
				}
				else if (frameX == 3)
				{
					OffWeakPunchHitBox();
				}

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
				
				if (frameX == 4)
				{
					OnStrongPunchHitBox((int)Player.playerLookat);
				}
				else if (frameX == 9)
				{
					OffStrongPunchHitBox();
				}

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

				if (frameX == 3)
				{
					OnWeakKickHitBox((int)Player.playerLookat);
				}
				else if (frameX == 5)
				{
					OffWeakKickHitBox();
				}

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


				if (frameX == 5)
				{
					OnStrongKickHitBox((int)Player.playerLookat);
				}
				else if (frameX == 8)
				{
					OffStrongKickHitBox();
				}

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

	else if (Player.playerAct != ChAnimData::Acting::Act_Attack) // 공격상태에서는 Idle과 Move가 작동하면 안되므로 공격상태인지 아닌지 판별
	{
		if (Player.playerStatus == ChAnimData::AnimStatus::Move_Front || Player.playerStatus == ChAnimData::AnimStatus::Move_Backward) //Move일때
		{
			// 왼쪽으로 움직이기
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
			// 오른쪽으로 움직이기
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

		else if (Player.playerAct == ChAnimData::Acting::Act_Idle) // Idle 일때
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




	shape.left = (int)pos.x - ((Player.mData.sizeX[ChAnimData::AnimStatus::Idle] / Player.mData.Animframe[ChAnimData::AnimStatus::Idle]) / 2);
	shape.top = (int)pos.y - (Player.mData.sizeY[ChAnimData::AnimStatus::Idle] / 2);
	shape.right = (int)pos.x + ((Player.mData.sizeX[ChAnimData::AnimStatus::Idle] / Player.mData.Animframe[ChAnimData::AnimStatus::Idle]) / 2);
	shape.bottom = (int)pos.y + (Player.mData.sizeY[ChAnimData::AnimStatus::Idle] / 2);

	if (mpTarget && IsCollided(mWeakPunchHitBox, mpTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->mHP -= 10;
			cout << "HP -10 상대 현재 체력 : " << mpTarget->mHP << endl;
		}
	}
	else if (mpTarget && IsCollided(mStrongPunchHitBox, mpTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->mHP -= 20;
			cout << "HP -20 상대 현재 체력 : " << mpTarget->mHP << endl;
		}
	}
	else if (mpTarget && IsCollided(mWeakPunchHitBox, mpTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->mHP -= 15;
			cout << "HP -15 상대 현재 체력 : " << mpTarget->mHP << endl;
		}
	}
	else if (mpTarget && IsCollided(mStrongPunchHitBox, mpTarget->shape))
	{
		if (!CheckHitChar())
		{
			mHitChar.push_back(mpTarget);
			mpTarget->mHP -= 30;
			cout << "HP -30 상대 현재 체력 : " << mpTarget->mHP << endl;
		}
	}

}

	// 실습1. 뒤로 움직이기 + 실제 위치 이동
	// 과제. 팀작업 때 쓸 리소스 찾아보기
	// (제자리 서있기, 앞으로 이동, 뒤로 이동, 작은 손/발, 큰 손/발
	// , 피격(맞았을 때)

void AnimManager::Render(HDC hdc)
{
	Rectangle(hdc, shape.left, shape.top, shape.right, shape.bottom);

	Rectangle(hdc, mWeakPunchHitBox.left, mWeakPunchHitBox.top, mWeakPunchHitBox.right, mWeakPunchHitBox.bottom);
	Rectangle(hdc, mStrongPunchHitBox.left, mStrongPunchHitBox.top, mStrongPunchHitBox.right, mStrongPunchHitBox.bottom);
	Rectangle(hdc, mWeakKickHitBox.left, mWeakKickHitBox.top, mWeakKickHitBox.right, mWeakKickHitBox.bottom);
	Rectangle(hdc, mStrongKickHitBox.left, mStrongKickHitBox.top, mStrongKickHitBox.right, mStrongKickHitBox.bottom);

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
