#pragma once
#include "Character.h"
#include <string>
using namespace std;

class Character;
class Monster
{
protected:
	string name;
	int damage;
	int health;	
	int totalHealth;
	int expRatio;
	int goldRatio;
	int defence;
public:
	virtual void scream() = 0;
	virtual ~Monster() {};
	friend void Fight(Character*, Monster*);
};

