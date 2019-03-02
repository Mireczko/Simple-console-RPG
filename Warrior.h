#pragma once
#include "Character.h"

class Warrior :public Character
{
protected:
public:
	Warrior()
	{
		experience = 0;
		experienceRequired = 100;
		gold = 500;
		damage = 10;
		healthbefore = 150.5;
		health = static_cast<int>(healthbefore);
		totalHealth = 150;
		level = 1;
		weap = nullptr;
	}
	Warrior(int exp)
	{
		vocation = "Warrior";
		experienceRequired = 100;
		gold = 0;
		damage = 10;
		healthbefore = 150.5;
		health = 150;
		totalHealth = 150;
		level = 1;
		weap = nullptr;
		experience = exp;
	}
	void scream() override
	{
		cout << "Wooho";
	}
	ostream &operator << (ostream & out)
	{
		return out << "Vocation: " << vocation << " Damage: " << damage << "Level: " << level;
	}
};
