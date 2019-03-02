#pragma once
#include <string>
#include <iostream>
#include "Character.h"
#include <windows.h>
using namespace std;

class Weapon
{
protected:
	string name;
	int dmg;
	int def;
	double buyCost;
	double sellCost;
public:
	void showItem()
	{
		if (this != nullptr)
		{
			cout << name;
		}
		else cout << "Brak ";
	}
	int getDmg()
	{
		return dmg;
	}
	int getDef()
	{
		return def;
	}
	double getbuyCost() { return buyCost; };
	friend class Character;
	friend class Inventory;
};