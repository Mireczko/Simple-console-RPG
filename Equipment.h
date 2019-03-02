#pragma once
#include <iostream>
#include <windows.h>
#include "Inventory.h"
#include "Character.h"
using namespace std;

void Equipment(Inventory*YourInventory, Character*Player)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int kurs = 0;
	for (;;)
	{
		cout << "Twoj ekwipunek:\n\n";
		for (int i = 0; i < YourInventory->getsize() + 1; i++)
		{
			if (i == kurs && i != YourInventory->getsize())
			{
				SetConsoleTextAttribute(hOut, 4);
				cout << i + 1 << " ";YourInventory->getitems()[i]->showItem(); cout << endl;
				SetConsoleTextAttribute(hOut, 7);
			}
			else if (i != YourInventory->getsize())
			{
				cout << i + 1 << " ";YourInventory->getitems()[i]->showItem(); cout << endl;
			}
			if (i == kurs &&i == YourInventory->getsize())
			{
				SetConsoleTextAttribute(hOut, 4);
				cout << endl << "Zdejmij bron";
				SetConsoleTextAttribute(hOut, 7);
				cout << endl << "Aktualnie dzierzona bron: "; Player->showWeapon();
				cout << endl << "Aby sprzedac przedmiot wcisnij T" << endl;
			}
			else if (i == YourInventory->getsize())
			{
				cout << endl << "Zdejmij bron";
				cout << endl << "Aktualnie dzierzona bron: "; Player->getweapon()->showItem();
				cout << endl << "Aby sprzedac przedmiot wcisnij T" << endl;
			}

		}
		char c = _getch();
		if (c == 's')
		{
			kurs++;
		}
		else if (c == 'w')
		{
			kurs--;
		}
		else if (c == 27)
		{
			break;
		}
		else if ((c == 't' && kurs != YourInventory->getsize()))
		{
			YourInventory->sellWeapon(kurs, Player);
		}
		else if (((c == 13) || (c == 'e')) && (kurs == YourInventory->getsize()))
		{
			Player->takeOffWeapon();
		}
		else if ((c == 13) || (c == 'e') && kurs != YourInventory->getsize())
		{
			Player->equipWeapon(YourInventory->getitems()[kurs]);
		}


		if (kurs >= YourInventory->getsize() + 1)kurs = 0;
		else if (kurs < 0) kurs = YourInventory->getsize();
		system("cls");
	}
}