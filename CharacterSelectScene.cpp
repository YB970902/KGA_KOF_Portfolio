#include "CharacterSelectScene.h"
#include "KeyManager.h"

void CharacterSelectScene::Enter()
{

}

void CharacterSelectScene::Update()
{
	if (MGR_KEY->IsOnceKeyDown('1'))
	{
		Player1 = 1;
		cout << "블루마리" << endl;
	}
	else if (MGR_KEY->IsOnceKeyDown('2'))
	{
		Player1 = 2;
		cout << "랄프" << endl;
	}
	else if (MGR_KEY->IsOnceKeyDown('3'))
	{
		Player1 = 3;
		cout << "레오나" << endl;
	}

	if (MGR_KEY->IsOnceKeyDown('4'))
	{
		Player2 = 1;
		cout << "블루마리" << endl;
	}
	else if (MGR_KEY->IsOnceKeyDown('5'))
	{
		Player2 = 2;
		cout << "랄프" << endl;
	}
	else if (MGR_KEY->IsOnceKeyDown('6'))
	{
		Player2 = 3;
		cout << "레오나" << endl;
	}
}

void CharacterSelectScene::Render(HDC hdc)
{
}

void CharacterSelectScene::Exit()
{
}
