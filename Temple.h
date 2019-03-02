#pragma once
#include <iostream>
#include <windows.h>
#include "Character.h"	
using namespace std;


void Temple(Character* pl)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	double koszt;
	koszt = pl->level * 100;
	for (;;)
	{
		system("cls");
		cout << "Witaj w swiatyni!" << endl;
		SetConsoleTextAttribute(hOut, 4);
		cout << "Jesli chcesz sie uzdrowic musisz zaplacic : " << fixed << setprecision(0) << koszt << " zlota" << endl;
		SetConsoleTextAttribute(hOut, 7);
		char c = _getch();
		if ((c == 13) || (c == 'e'))
		{
			if (pl->gold <= koszt)
			{
				cout << "Nie masz wystarczajaco duzo zlota!" << endl;
			}
			else if (pl->health == pl->totalHealth)
			{
				cout << "Jestes w pelni zdrowy!" << endl;
			}
			else
			{
				pl->gold -= koszt;
				pl->health = pl->totalHealth;
				cout << "Zostales uzdrowiony!";
			}
			_getch();
		}
		else if (c == 27) break;
	}
}