#pragma once
#include "Config.h"
#include "Singleton.h"
#include <map>

class Scene;
class SceneManager : public Singleton<SceneManager>
{
private:
	map<eSceneTag, Scene*> mScene;

	Scene* mpCurScene = nullptr;
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void ChangeScene(eSceneTag tag);
};