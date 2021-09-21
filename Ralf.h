#pragma once
#include <map>
using namespace std;

class ChAnimData
{
public:
	enum AnimStatus
	{
		Idle,
		Move,
		Damaged,
		Weak_Punch,
		Weak_Kick,
		Strong_Punch,
		Strong_Kick,
	};

	enum Acting
	{
		Act_Attack,
		Act_Forward,
		Act_Backward,
		Act_Idle,
	};

	enum Lookat
	{
		Left,
		Right
	};

	map<AnimStatus, int> Animframe;
	map<AnimStatus, int> sizeX;
	map<AnimStatus, int> sizeY;
	map<AnimStatus, const char*> Path;
};

class Ralf: public ChAnimData
{
public:
	ChAnimData mData;

	void init();
};

static ChAnimData::Lookat playerLookat;
static ChAnimData::AnimStatus playerStatus;
static ChAnimData::Acting playerAct;