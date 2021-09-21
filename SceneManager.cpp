#include "AnimationScene.h"
#include "HitBoxScene.h"
#include "SceneManager.h"

void SceneManager::Init()
{
	mScene[eSceneTag::HitBoxSnene] = new HitBoxScene;
	mScene[eSceneTag::ImageAnimationScene] = new AnimationScene;

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
}

void SceneManager::ChangeScene(eSceneTag tag)
{
	if (mpCurScene) { mpCurScene->Exit(); }

	mpCurScene = mScene[tag];

	if (mpCurScene) { mpCurScene->Enter(); }
}
