#pragma once
#include <map>
using namespace std;

class ChAnimData
{
public:
	enum class AnimStatus
	{
		Idle,
		Move_Front,
		Move_Backward,
		Damaged,
		Weak_Punch,
		Weak_Kick,
		Strong_Punch,
		Strong_Kick,
	};

	enum class Acting
	{
		Act_Attack,
		Act_Left_Move,
		Act_Right_Move,
		Act_Idle,
	};

	enum class Lookat
	{
		Left_Lookat,
		Right_Lookat
	};

	//추후에 스트럭트로 묶자.
	map<AnimStatus, int> Animframe;
	map<AnimStatus, int> AnimSpeed;
	map<AnimStatus, int> sizeX;
	map<AnimStatus, int> sizeY;
	map<AnimStatus, const char*> Path;
	map<AnimStatus, int> moveAfteraction;
	
};
