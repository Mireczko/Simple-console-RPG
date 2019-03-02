#pragma once
#include<vector>
#include <conio.h>
#include "Weapon.h"

class Inventory
{
protected:
	int capacity;
	vector<Weapon*> items;
public:
	Inventory();
	~Inventory();
	void showInventory();
	bool addItem(Weapon *);
	int getsize();
	vector<Weapon*> getitems();
	void sellWeapon(int, Character*);
};