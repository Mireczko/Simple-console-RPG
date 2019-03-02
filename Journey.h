#pragma once
#include "Character.h"
#include "MonsterList.h"
#include <time.h>

void Journey(Character* Player)
{
	if (Player->level < 3)
	{
		Monster* enemy = new Rat;
		Fight(Player, enemy);
	}
	else if (Player->level >= 3 && Player->level <= 10)
	{
		int random = rand() % 3;
		if (random == 0) { Monster*enemy = new Rat;Fight(Player, enemy);}
		else if (random == 1) { Monster*enemy = new Spider;Fight(Player, enemy);}
		else if (random == 2) {Monster*enemy = new Wolf;Fight(Player, enemy);}
	}
	else if (Player->level > 10)
	{
		int random = rand() % 3;
		if (random == 0) { Monster*enemy = new Wolf;Fight(Player, enemy); }
		else if (random == 1) { Monster*enemy = new FireElemental;Fight(Player, enemy); }
		else if (random == 2) { Monster*enemy = new Ghost;Fight(Player, enemy); }
	}
}

void Fight(Character* Player, Monster* enemy)
{
	cout << "Zaatakowal Cie: " << enemy->name << endl;
	system("cls");
	int rollPl;
	int rollEn;
	double damageGiven;
	double damageTaken;
	bool win = 0;
	bool lose = 0;
	srand(time(NULL));

	for (;;)
	{
		bool leave = false;
		if (Player->health == 0)
		{
			leave = true;
			cout << "Masz za malo zdrowia na wyprawe!";_getch();
		}
		if (leave == true)break;
		if ((win == 1)||(lose==1)) { break; }
		while (Player->health > 0 && enemy->health > 0)
		{
			rollEn = rand() % 6 + 1;
			rollPl = rand() % 6 + 1;
			cout << "Twoje zycie: " << Player->health << endl;
			cout << "Zycie "<<enemy->name<<": " << enemy->health << endl<<endl;
			_getch();
			if (rollPl == 6){ cout << "Nie trafiles!"<< endl;_getch(); }
			else
			{
				damageGiven = Player->damage*rollPl - rollEn*enemy->defence;
				if (damageGiven > 0)
				{
					cout << "Trafiles przeciwnika za: " << fixed << setprecision(0) << damageGiven << endl;_getch();
					enemy->health -= damageGiven;
				}
				else { cout << "Trafiles przeciwnika za: 0" << endl; _getch(); }
			}
			if (enemy->health <= 0) { cout << "Gratulacje, pokonales przeciwnika! ";Player->scream();win = 1;_getch();break; }
			if (rollEn == 6 || rollEn == 5 || rollEn == 4) { cout << "Przeciwnik nie trafil!" << endl; _getch(); }
			else
			{
				damageTaken = enemy->damage*rollEn - (Player->level * 3);
				if (damageTaken > 0)
				{
					cout << "Przeciwnik trafil za: " <<fixed<<setprecision(0)<< damageTaken<<endl; _getch();
					Player->health -= damageTaken;
				}
				else { cout << "Przeciwnik trafil za: 0" << endl; _getch(); }
			}
			if (Player->health <= 0) { cout << "Niestety polegles!";lose = 1;Player->health = 0;_getch();break; }
			system("cls");

		}
		if (win == 1)
		{
			double expObtained= enemy->expRatio*(rand() % 5 + 1);
			double goldObtained = enemy->goldRatio*(rand() % 10 + 1);
			cout << "\nOtrzymales " << expObtained << " doswiadczenia i " << goldObtained << " zlota!" << endl; _getch();
			Player->gold += goldObtained;
			Player->experience += expObtained;
			if (Player->experience >= Player->experienceRequired)
			{
				Player->levelUp();
			}
			delete enemy;
			break;
		}
		break;
	}
}