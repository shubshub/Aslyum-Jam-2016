#pragma once
#include <vector>
#include "item.h"
class Inventory
{
private:
	std::vector<Item*> inventory_list_;
	//Inventory is stored as a list of Item ID's
public:
	void ObtainItem(Item* item_);
	bool HasItem(unsigned int);
	char* GetItemName(unsigned int);

	std::vector<Item*>& GetAllItems();

};

extern Inventory* global_inventory_;