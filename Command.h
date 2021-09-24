#pragma once
#include "Config.h"
#include "GameEntity.h"


class ChAnimation;
class ChAnimData;

typedef void (*CallBack/*함수이름*/)(ChAnimation* ch);
typedef void (*AnimCallBack/*함수이름*/)(ChAnimation* ch,ChAnimData* an);

// "실행할 함수"와
// 함수를 "호출시킬 객체"를 저장하고
// Execute를 실행하면 "호출시킬 객체"가 "실행할 함수"를 호출한다.

class Command : public GameEntity
{
protected:
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

typedef void (*AnimCallBack/*함수이름*/)(ChAnimation* ch, ChAnimData* an);

class AnimCommand : public Command
{
protected:
	AnimCallBack mpAnimFunc = nullptr;
	ChAnimData* mpmData = nullptr;

public:
	AnimCommand() {};
	~AnimCommand() {};

	//원래 캐릭애니메이션이 아니라 캐릭터였음 //
	void Init(ChAnimation* ch, ChAnimData* an, AnimCallBack func) { mpChar = ch; mpmData = an; mpAnimFunc = func; }

	void Release() override { mpChar = nullptr; mpAnimFunc = nullptr, mpmData = nullptr; }

	void Execute() { mpAnimFunc(mpChar, mpmData); }

	inline ChAnimation* GetCharacter() { return mpChar; }
	inline ChAnimData* GetmData() { return mpmData; }
};