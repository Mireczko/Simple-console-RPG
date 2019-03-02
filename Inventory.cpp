#include "inventory.h"
#include <iomanip>
Inventory::Inventory()
{
	capacity = 5;
}
Inventory::~Inventory()
{

}
void Inventory::showInventory()
{
	for (int i = 0; i < items.size(); i++)
	{
		items[i]->showItem();
		cout << endl;
	}
}

bool Inventory::addItem(Weapon *itemek)
{
	if (items.size() == 5)
	{
		cout << "\nEkwipunek pelny!";
		return false;
	}
	items.push_back(itemek);
	return true;
}
int Inventory::getsize()
{
	return items.size();
}
vector<Weapon*> Inventory::getitems()
{
	return items;
}
void Inventory::sellWeapon(int i, Character* pl)
{
	if (items.size() > 0)
	{
		if (pl->weap == items[i])
		{
			cout << "\nNajpierw zdejmij przedmiot zeby go sprzedac!";
			_getch();
		}
		else
		{
			cout << "\nCena sprzedazy: " << fixed <<setprecision(0)<<items[i]->sellCost << endl;
			cout << "Czy chcesz sprzedac (y-tak, n-nie)?" << endl;
			if (_getch() == 'y')
			{
				pl->gold += items[i]->sellCost;
				delete items[i];
				items.erase(items.begin() + i);
			}
			else
			{
				cout << "Moze innym razem..." << endl;
				_getch();
			}
		}
	}
}
