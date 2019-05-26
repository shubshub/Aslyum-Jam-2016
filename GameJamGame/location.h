#pragma once
#include <vector>
#include "item.h"
class Location
{
private:
	char* location_name_;
	std::vector<Item*> items_in_location_;
public:
	Location(char* location_name);
	~Location();

	bool PlaceItem(Item* item_);

	Item* GetItem(unsigned int id);

	std::vector<Item*> ItemList();

	char* GetName();
};