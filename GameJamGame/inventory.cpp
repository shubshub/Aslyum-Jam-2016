#include "inventory.h"

Inventory* global_inventory_ = new Inventory();

void Inventory::ObtainItem(Item* item_)
{
	inventory_list_.push_back(item_);
}

bool Inventory::HasItem(unsigned int id)
{
	for (int i = 0; i < inventory_list_.size(); i++)
	{
		if (inventory_list_[i]->GetItemID() == id)
		{
			return true;
		}
	}
	return false;
}

char* Inventory::GetItemName(unsigned int id)
{
	for (int i = 0; i < inventory_list_.size(); i++)
	{
		if (inventory_list_[i]->GetItemID() == id)
		{
			return inventory_list_[i]->GetItemName();
		}
	}
}

std::vector<Item*>& Inventory::GetAllItems()
{
	return inventory_list_;
}