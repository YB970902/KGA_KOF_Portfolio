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
		cout << "씬 매니저의 체인지 함수에 뭘 넣은거야 영민아" << endl;
		break;
	}

	if (mpCurScene) { mpCurScene->Enter(); }
}
