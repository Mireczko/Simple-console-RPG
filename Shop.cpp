#include "Shop.h"
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "Inventory.h"

Shop::Shop()
{
	products.push_back(new ShortSword);
	products.push_back(new CarlinSword);
	products.push_back(new Mace);
	products.push_back(new BattleAxe);
	products.push_back(new WarHammer);
	products.push_back(new DragonHammer);
	products.push_back(new MagicSword);
}

void Shop::showProducts(Inventory *inv, Character*pl)
{
	//for (int i = 0; i < products.size(); i++)
	//{
	//	cout << i + 1; cout << ".";products[i]->showItem();cout << "\t\tCena: " <<fixed<<setprecision(0) << products[i]->getbuyCost(); cout << endl;
	//}
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int kurs = 0;
	for (;;)
	{
		cout << "Witamy w sklepie!\n\n";
		for (int i = 0; i < products.size(); i++)
		{
			if (i == kurs)
			{
				SetConsoleTextAttribute(hOut, 4);
				cout << i + 1 << ".";products[i]->showItem();cout << "\tCena " << fixed << setprecision(0) << products[i]->getbuyCost(); cout<<" zlota" << endl;
				SetConsoleTextAttribute(hOut, 7);
			}
			else
			{
				cout << i + 1 << ".";products[i]->showItem();cout << "\tCena " << fixed << setprecision(0) << products[i]->getbuyCost(); cout << " zlota" << endl;
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
		else if ((c == 13) || (c == 'e'))
		{
			if (pl->getgold() >= products[kurs]->getbuyCost())
			{
				if (inv->addItem(products[kurs]) == true)
				{
					pl->gold -= products[kurs]->getbuyCost();
					cout << "\nItemek kupiony! " << endl;
					products.erase(products.begin() + kurs);
				}
			}
			else cout << "\nNiestety, potrzebujesz jeszcze: " << products[kurs]->getbuyCost() - pl->gold << " zlota!" << endl;
			_getch();
		}

		if (kurs > products.size() - 1) { kurs = 0; }
		else if (kurs < 0) { kurs = products.size() - 1; }
		if (c == 27) break;
		system("cls");
		
	}
}
void Shop::addProduct(Weapon* W)
{
	products.push_back(W);
}

Shop::~Shop()
{
	for (int i = 0; i < products.size();i++)
	{
		delete products[i];
	}
}