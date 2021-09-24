#pragma once
#include "Config.h"
#include "GameEntity.h"


class ChAnimation;
class ChAnimData;

typedef void (*CallBack/*�Լ��̸�*/)(ChAnimation* ch);
typedef void (*AnimCallBack/*�Լ��̸�*/)(ChAnimation* ch,ChAnimData* an);

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

	inline ChAnimation* GetCharacter() { return mpChar; }

	void Init() override {}
	void Update() override {}
	void Render(HDC hdc) override {}
};

typedef void (*AnimCallBack/*�Լ��̸�*/)(ChAnimation* ch, ChAnimData* an);

class AnimCommand : public Command
{
protected:
	AnimCallBack mpAnimFunc = nullptr;
	ChAnimData* mpmData = nullptr;

public:
	AnimCommand() {};
	~AnimCommand() {};

	//���� ĳ���ִϸ��̼��� �ƴ϶� ĳ���Ϳ��� //
	void Init(ChAnimation* ch, ChAnimData* an, AnimCallBack func) { mpChar = ch; mpmData = an; mpAnimFunc = func; }

	void Release() override { mpChar = nullptr; mpAnimFunc = nullptr, mpmData = nullptr; }

	void Execute() { mpAnimFunc(mpChar, mpmData); }

	inline ChAnimation* GetCharacter() { return mpChar; }
	inline ChAnimData* GetmData() { return mpmData; }
};