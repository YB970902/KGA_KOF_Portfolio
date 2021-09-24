#pragma once
#include "Config.h"
#include "GameEntity.h"

<<<<<<< HEAD
class ChAnimation;

typedef void (*CallBack/*�Լ��̸�*/)(ChAnimation* ch);
=======
class Character;
class ChAnimData;

typedef void (*CallBack/*�Լ��̸�*/)(Character* ch);
typedef void (*AnimCallBack/*�Լ��̸�*/)(Character* ch,ChAnimData* an);
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9

// "������ �Լ�"��
// �Լ��� "ȣ���ų ��ü"�� �����ϰ�
// Execute�� �����ϸ� "ȣ���ų ��ü"�� "������ �Լ�"�� ȣ���Ѵ�.

class Command : public GameEntity
{
protected:
	CallBack mpFunc = nullptr;
<<<<<<< HEAD
	ChAnimation* mpChar = nullptr;
public:
	Command() { };
	~Command() { };
	void Init (ChAnimation* ch, CallBack func) { mpChar = ch; mpFunc = func; }
	void Release() override { mpChar = nullptr; mpFunc = nullptr;  }
=======
	Character* mpChar = nullptr;

public:
	Command() { };
	~Command() { };

	virtual void Init (Character* ch, CallBack func) { mpChar = ch; mpFunc = func; }

	virtual void Release() override { mpChar = nullptr; mpFunc = nullptr;  }
>>>>>>> bdc06b383e470c785a137bd4e512c814c26237b9

	void Execute() { mpFunc(mpChar); }

	inline ChAnimation* GetCharacter() { return mpChar; }

	void Init() override {}
	void Update() override {}
	void Render(HDC hdc) override {}
};

typedef void (*AnimCallBack/*�Լ��̸�*/)(Character* ch, ChAnimData* an);

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