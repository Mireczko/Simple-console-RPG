#pragma once
#include "WeaponList.h"
#include <vector>
class Shop
{
protected:
	vector<Weapon*> products;

public:
	Shop();
	void showProducts(Inventory*, Character*);
	void addProduct(Weapon*);
	~Shop();
};
