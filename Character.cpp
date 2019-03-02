#include "Character.h"
#include <windows.h>
#include <conio.h>

Character::~Character()
{

}

//Gettery?
bool Character::isAlive()
{
	if (health <= 0) return true;
	else return false;
}
int Character::getexperience()
{
	return experience;
}
int Character::getexperienceRequired()
{
	return experienceRequired;
}
int Character::getgold()
{
	return gold;
}
int Character::getdamage()
{
	return damage;
}
int Character::gethealth()
{
	return health;
}
int Character::gettotalHealth()
{
	return totalHealth;
}
int Character::getlevel()
{
	return level;
}
Weapon* Character::getweapon()
{
	return weap;
}
string Character::getVocation()
{
	return vocation;
}

void Character::equipWeapon(Weapon*W)
{
	if (isWeaponEquipped() == false)
	{
		weap = W;
		this->damage += W->dmg;
	}
	else
	{
		this->damage -= weap->dmg;
		weap = W;
		this->damage += W->dmg;
	}
}

void Character::takeOffWeapon()
{
	if (isWeaponEquipped() == true)
	{
		this->damage -= weap->dmg;
		weap = nullptr;
	}
}

bool Character::isWeaponEquipped()
{
	if (weap != nullptr) return true;
	else return false;
}

void Character::showWeapon()
{
	weap->showItem();
}
void Character::levelUp()
{
	this->damage += level * 2;
	this->level++;
	this->experience = 0;
	this->experienceRequired = level * 100;
	this->totalHealth += 100;
	cout << "Zdobyles poziom " << level << " Twoja sila wzrosla o: " << (level-1) * 2 << endl;_getch();
}
