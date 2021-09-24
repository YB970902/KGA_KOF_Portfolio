#pragma once
#include "Config.h"
#include "GameEntity.h"


class ChAnimation;
class Character;
class ChAnimData;

typedef void (*CallBack/*함수이름*/)(ChAnimation* ch);
typedef void (*CharacterCallBack/*함수이름*/)(Character* ch);
typedef void (*AnimCallBack/*함수이름*/)(Character* ch, ChAnimData* an);

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


	void Init() override {}
	void Update() override {}
	void Render(HDC hdc) override {}
};

class AnimCommand : public Command
{
protected:
	AnimCallBack mpAnimFunc = nullptr;
	ChAnimData* mpmData = nullptr;
	Character* mpChar = nullptr;
public:
	AnimCommand() {};
	~AnimCommand() {};

	//원래 캐릭애니메이션이 아니라 캐릭터였음 //
	void Init(Character* ch, ChAnimData* an, AnimCallBack func) { mpChar = ch; mpmData = an; mpAnimFunc = func; }

	void Release() override { mpChar = nullptr; mpAnimFunc = nullptr, mpmData = nullptr; }

	void Execute() { mpAnimFunc(mpChar, mpmData); }

	inline Character* GetCharacter() { return mpChar; }
	inline ChAnimData* GetmData() { return mpmData; }
};

class CharacterCommand : public Command
{
protected:
	CharacterCallBack mpCharFunc = nullptr;
	Character* mpCharcter = nullptr;
public:
	CharacterCommand() { };
	~CharacterCommand() { };
	void Init(Character* ch, CharacterCallBack func) { mpCharcter = ch; mpCharFunc = func; }
	void Release() override { mpCharcter = nullptr; mpCharFunc = nullptr; }
	void Execute() { mpCharFunc(mpCharcter); }

	inline Character* GetCharacter() { return mpCharcter; }
};