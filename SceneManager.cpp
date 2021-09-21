#include "SceneManager.h"
#include "HitBoxScene.h"

void SceneManager::Init()
{
	mpHitBoxScene = new HitBoxScene;
	mpCurScene = nullptr;
}

void SceneManager::Update()
{
	if (mpCurScene) { mpCurScene->Update(); }
}

void SceneManager::Render(HDC hdc)
{
	if (mpCurScene) { mpCurScene->Render(hdc); }
}

void SceneManager::Release()
{
	if (mpCurScene) { mpCurScene->Exit(); }

	delete mpHitBoxScene;
	mpHitBoxScene = nullptr;
}

void SceneManager::ChangeScene(eSceneTag tag)
{
	if (mpCurScene) { mpCurScene->Exit(); }

	switch (tag)
	{
	case eSceneTag::HitBoxSnene:
		mpCurScene = mpHitBoxScene;
		break;
	default:
		cout << "�� �Ŵ����� ü���� �Լ��� �� �����ž� ���ξ�" << endl;
		break;
	}

	if (mpCurScene) { mpCurScene->Enter(); }
}
