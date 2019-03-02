#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Monster.h"

using namespace std;
class Weapon;
class Shop;
class Character
{
protected:
	Weapon* weap;
	int level;
	double healthbefore;
	int health;
	int totalHealth;
	int experience;
	int experienceRequired;
	bool isAlive();
	int gold;
	int damage;
	string vocation;
public:
	virtual void scream() = 0;
	virtual ~Character();
	int getexperience();
	int getexperienceRequired();
	int getgold();
	int getdamage();
	int gethealth();
	int gettotalHealth();
	int getlevel();
	Weapon* getweapon();
	string getVocation();
	void equipWeapon(Weapon*);
	void takeOffWeapon();
	bool isWeaponEquipped();
	void showWeapon();
	void levelUp();
	friend class Weapon;
	friend class Inventory;
	friend class Shop;
	friend void Temple(Character*);
	friend void Journey(Character*);
	friend void Fight(Character*, Monster*);
};