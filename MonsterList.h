#pragma once
#include "Monster.h"

class Rat : public Monster
{
public:
	Rat()
	{
		name = "Rat";
		damage=5;
		health=100;
		totalHealth=100;
		expRatio=20;
		goldRatio = 10;
		defence = 5;
	}
	void scream()override {};
};

class Spider :public Monster
{
public:
	Spider()
	{
		name = "Spider";
		damage = 15;
		health = 350;
		totalHealth = 350;
		expRatio = 40;
		goldRatio = 20;
		defence = 8;
	}
	void scream()override {};
};

class Wolf : public Monster
{
public:
	Wolf()
	{
		name = "Wolf";
		damage = 20;
		health = 400;
		totalHealth = 400;
		expRatio = 60;
		goldRatio = 35;
		defence = 10;
	}
	void scream()override {};
};

class FireElemental : public Monster
{
public:
	FireElemental()
	{
		name = "Fire Elemental";
		damage = 300;
		health = 1000;
		totalHealth = 1000;
		expRatio = 700;
		goldRatio = 700;
		defence = 30;
	}
	void scream()override {};
};

class Ghost : public Monster
{
public:
	Ghost()
	{
		name = "Ghost";
		damage = 250;
		health = 1500;
		totalHealth = 1500;
		expRatio = 250;
		goldRatio = 700;
		defence = 40;
	}
	void scream()override {};
};
