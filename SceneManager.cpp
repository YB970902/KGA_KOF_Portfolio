#include "AnimationScene.h"
#include "HitBoxScene.h"
#include "SceneManager.h"
#include "OpeningScene.h"
#include "EndingScene.h"
#include "CharacterSelectScene.h"

void SceneManager::Init()
{
	mScene[eSceneTag::OpeningScene] = new OpeningScene;
	mScene[eSceneTag::CharacterSelectScene] = new CharacterSelectScene;
	mScene[eSceneTag::AnimationScene] = new AnimationScene;
	mScene[eSceneTag::HitBoxSnene] = new HitBoxScene;
	mScene[eSceneTag::EndingScene] = new EndingScene;

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