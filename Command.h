#pragma once
#include "Config.h"
#include "GameEntity.h"

class ChAnimation;

typedef void (*CallBack/*�Լ��̸�*/)(ChAnimation* ch);

// "������ �Լ�"��
// �Լ��� "ȣ���ų ��ü"�� �����ϰ�
// Execute�� �����ϸ� "ȣ���ų ��ü"�� "������ �Լ�"�� ȣ���Ѵ�.

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