#pragma once
#include "Config.h"
#include "GameEntity.h"

class Character;
class ChAnimData;

typedef void (*CallBack/*함수이름*/)(Character* ch);
typedef void (*AnimCallBack/*함수이름*/)(Character* ch,ChAnimData* an);

// "실행할 함수"와
// 함수를 "호출시킬 객체"를 저장하고
// Execute를 실행하면 "호출시킬 객체"가 "실행할 함수"를 호출한다.

class Command : public GameEntity
{
protected:
	CallBack mpFunc = nullptr;
	Character* mpChar = nullptr;

public:
	Command() { };
	~Command() { };

	virtual void Init (Character* ch, CallBack func) { mpChar = ch; mpFunc = func; }

	virtual void Release() override { mpChar = nullptr; mpFunc = nullptr;  }

	void Execute() { mpFunc(mpChar); }

	inline Character* GetCharacter() { return mpChar; }

	void Init() override {}
	void Update() override {}
	void Render(HDC hdc) override {}
};

typedef void (*AnimCallBack/*함수이름*/)(Character* ch, ChAnimData* an);

class AnimCommand : public Command
{
protected:
	AnimCallBack mpAnimFunc = nullptr;
	ChAnimData* mpmData = nullptr;

public:
	AnimCommand() {};
	~AnimCommand() {};

	void Init(Character* ch, ChAnimData* an, AnimCallBack func) { mpChar = ch; mpmData = an; mpAnimFunc = func; }

	void Release() override { mpChar = nullptr; mpAnimFunc = nullptr, mpmData = nullptr; }

	void Execute() { mpAnimFunc(mpChar, mpmData); }

	inline Character* GetCharacter() { return mpChar; }
	inline ChAnimData* GetmData() { return mpmData; }
};