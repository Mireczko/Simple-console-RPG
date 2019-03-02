#pragma once
#include "Weapon.h"

class ShortSword : public Weapon
{
public:
	ShortSword()
	{
		name = "Short Sword";
		dmg = 5;
		buyCost = 100;
		sellCost = buyCost * 0.4;
	}
};

class CarlinSword : public Weapon
{
public:
	CarlinSword()
	{
		name = "Carlin Sword";
		dmg = 15;
		buyCost = 300;
		sellCost = buyCost*0.4;
	}
};

class Mace : public Weapon
{
public:
	Mace()
	{
		name = "Mace\t";
		dmg = 30;
		buyCost = 1000;
		sellCost = buyCost*0.4;
	}
};

class BattleAxe : public Weapon
{
public:
	BattleAxe()
	{
		name = "Battle Axe";
		dmg = 60;
		buyCost = 5000;
		sellCost = buyCost*0.4;
	}
};

class WarHammer : public Weapon
{
public:
	WarHammer()
	{
		name = "War Hammer";
		dmg = 90;
		buyCost = 15000;
		sellCost = buyCost*0.4;
	}
};

class DragonHammer : public Weapon
{
public:
	DragonHammer()
	{
		name = "Dragon Hammer";
		dmg = 150;
		buyCost = 40000;
		sellCost = buyCost*0.4;
	}
};

class MagicSword : public Weapon
{
public:
	MagicSword()
	{
		name = "Magic Sword";
		dmg = 250;
		buyCost = 100000;
		sellCost = buyCost * 0.4;
	}
};
