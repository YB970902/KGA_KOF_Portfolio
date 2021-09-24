#pragma once
#include "Config.h"
#include "GameEntity.h"

class ChAnimation;

typedef void (*CallBack/*함수이름*/)(ChAnimation* ch);

// "실행할 함수"와
// 함수를 "호출시킬 객체"를 저장하고
// Execute를 실행하면 "호출시킬 객체"가 "실행할 함수"를 호출한다.

class Command : public GameEntity
{
private:
	CallBack mpFunc = nullptr;
	ChAnimation* mpChar = nullptr;
public:
	Command() { };
	~Command() { };
	void Init (ChAnimation* ch, CallBack func) { mpChar = ch; mpFunc = func; }
	void Release() override { mpChar = nullptr; mpFunc = nullptr;  }

	void Execute() { mpFunc(mpChar); }

	inline ChAnimation* GetCharacter() { return mpChar; }

	void Init() override {}
	void Update() override {}
	void Render(HDC hdc) override {}
};