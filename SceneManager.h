#pragma once
#include "Singleton.h"
#include "Config.h"

class Scene;
class SceneManager : public Singleton<SceneManager>
{
private:
	Scene* mpHitBoxScene = nullptr;

	Scene* mpCurScene = nullptr;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void ChangeScene(eSceneTag tag);
};