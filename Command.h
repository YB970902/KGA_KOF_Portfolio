#pragma once
#include "Config.h"

class Character;

typedef void (*CallBack/*�Լ��̸�*/)(Character* ch);

class Command
{
private:
	CallBack mpFunc = nullptr;
	Character* mpChar = nullptr;
public:
	Command(Character* ch) { mpChar = ch; };
	~Command() {};
	void Init(CallBack func) { mpFunc = func; }
	void Execute() { mpFunc(mpChar); }

};