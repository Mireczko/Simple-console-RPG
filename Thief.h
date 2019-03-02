#pragma once
#include "Character.h"

class Thief :public Character
{
protected:
public:
	Thief()
	{
		vocation = "Thief";
		experience = 0;
		experienceRequired = 100;
		gold = 100;
		damage = 20;
		health = 100;
		totalHealth = 100;
		level = 1;
		weap = nullptr;
	}
	void scream() override
	{
		cout<< "Yeaah";
	}
};
