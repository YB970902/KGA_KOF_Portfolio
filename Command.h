#pragma once
#include "Config.h"
#include "GameEntity.h"


class ChAnimation;
class Character;
class ChAnimData;

typedef void (*CallBack/*�Լ��̸�*/)(ChAnimation* ch);
typedef void (*CharacterCallBack/*�Լ��̸�*/)(Character* ch);
typedef void (*AnimCallBack/*�Լ��̸�*/)(Character* ch, ChAnimData* an);

// "������ �Լ�"��
// �Լ��� "ȣ���ų ��ü"�� �����ϰ�
// Execute�� �����ϸ� "ȣ���ų ��ü"�� "������ �Լ�"�� ȣ���Ѵ�.

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

	//���� ĳ���ִϸ��̼��� �ƴ϶� ĳ���Ϳ��� //
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