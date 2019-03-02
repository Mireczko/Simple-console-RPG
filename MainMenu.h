#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include "Inventory.h"
#include "WeaponList.h"
#include "Shop.h"
#include "Warrior.h"
#include "Thief.h"
#include "Temple.h"
#include "Equipment.h"
#include "Journey.h"
#include <fstream>
#include <vector>

void play(Inventory*, Shop*, Character*);
void newGame()
{
	Inventory* YourInventory = new Inventory;
	Shop* Sklep = new Shop;
	string name;
	Character* Player = nullptr;
	play(YourInventory, Sklep, Player);
}

void play(Inventory*YourInventory, Shop*Sklep,Character* Player)
{
	string name;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Witaj! Jak masz na imie: ";
	cin >> name;
	int kursor = 0;
	int chosen = 0;
	system("cls");
	for (;;)
	{
		cout << "Wybierz klase: " << endl;
		if (kursor == 0)
		{
			SetConsoleTextAttribute(hOut, 4);
			cout << "Warrior" << endl;
			SetConsoleTextAttribute(hOut, 7);
		}
		else cout << "Warrior" << endl;
		if (kursor == 1)
		{
			SetConsoleTextAttribute(hOut, 4);
			cout << "Thief" << endl;
			SetConsoleTextAttribute(hOut, 7);
		}
		else cout << "Thief" << endl;
		char c = _getch();
		if (c == 's')
		{
			kursor++;
		}
		else if (c == 'w')
		{
			kursor--;
		}
		else if ((c == 13) || (c == 'e'))
		{
			if (kursor == 0)
			{
				Player = new Warrior;
				chosen = 1;
			}
			else { Player = new Thief;chosen = 1; }
		}
		if (chosen == 1)
		{
			break;
		}
		if (kursor > 1)kursor = 0;
		if (kursor < 0)kursor = 1;
		system("cls");
	}
	cout << "Milej gry!";_getch();
	kursor = 0;
	for (;;)
	{
		system("cls");
		cout << "|Name: " << name << "|\t|LVL: " << Player->getlevel() << "|\t|Class: " << Player->getVocation() << "|" << "\t|EXP: " << setprecision(1) << (static_cast<double>(Player->getexperience()) / static_cast<double>(Player->getexperienceRequired())) * 100 << "%|" << endl <<
			"|GOLD: " << Player->getgold() << " |\t" << "|DMG: " << Player->getdamage() << "|\t|HP: " << Player->gethealth() << "/" << Player->gettotalHealth() << "|" << endl;

		cout << "--------------------------------------------------------------" << endl;
		cout << "[WS] Wybor" << "\t[E] Przejdz do..." << "\t[O] Zapisz" << endl;
		cout << "--------------------------------------------------------------" << endl;
		if (kursor == 0)
		{
			SetConsoleTextAttribute(hOut, 4);
		}
		cout << "Ekwipunek" << endl;
		SetConsoleTextAttribute(hOut, 7);
		if (kursor == 1)
		{
			SetConsoleTextAttribute(hOut, 4);
		}
		cout << "Sklepik" << endl;
		SetConsoleTextAttribute(hOut, 7);
		if (kursor == 2)
		{
			SetConsoleTextAttribute(hOut, 4);
		}
		cout << "Wyprawa" << endl;
		SetConsoleTextAttribute(hOut, 7);
		if (kursor == 3)
		{
			SetConsoleTextAttribute(hOut, 4);
		}
		cout << "Wylecz sie" << endl;
		SetConsoleTextAttribute(hOut, 7);
		char c = _getch();
		if (c == 's')
		{
			kursor++;
		}
		else if (c == 'w')
		{
			kursor--;
		}
		else if ((c == 13) || (c == 'e'))
		{
			system("cls");
			{	//Ekwipunek
				if (kursor == 0)
				{
					Equipment(YourInventory, Player);
				}
				//Sklep
				if (kursor == 1)
				{
					Sklep->showProducts(YourInventory, Player);
					//Shop();
				}
				//Exp
				if (kursor == 2)
				{
					Journey(Player);
				}
				//Temple
				if (kursor == 3)
				{
					Temple(Player);
				}
			}
		}
		if (kursor > 3)kursor = 0;
		if (kursor < 0)kursor = 3;
	}
}

void SaveGame(Character* Player, Inventory* MyInventory, Shop* Sklep)
{

}
//
//void LoadGame(string fileName)
//{
//	fstream file;
//	file.open(fileName);
//	if (file.fail()) { cout << "ERROR: Could not load level.\n"; system("PAUSE"); exit(1);}
//	vector<string> data;
//	string line;
//	while (getline(file, line))
//	{
//		data.push_back(line);
//	}
//	file.close();
//}

void MainMenu()
{
	cout << "1. New game\n";
	cout << "2. Exit\n";
	cout << endl;

	fstream file;

	char c = _getch();
	switch (c) {
	case '1':
		newGame();
		break;
	case '3':
		exit(0);
	default:
		break;
	}
	system("cls");
}


