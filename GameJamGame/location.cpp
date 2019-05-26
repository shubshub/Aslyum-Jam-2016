#include "location.h"

Location::Location(char* location_name)
{
	location_name_ = location_name;
}

Location::~Location()
{
	
}

char* Location::GetName()
{
	return location_name_;
}

std::vector<Item*> Location::ItemList()
{
	return items_in_location_;
}

bool Location::PlaceItem(Item* item_)
{
	for (unsigned int i = 0; i < items_in_location_.size(); ++i)
	{
		if (items_in_location_[i] == item_)
		{
			return false; //Failed to place item in room
		}
	}
	items_in_location_.push_back(item_);
	return true;
}

Item* Location::GetItem(unsigned int id)
{
	for (unsigned int i = 0; i < items_in_location_.size(); ++i)
	{
		if (items_in_location_[i]->GetItemID() == id)
		{
			return items_in_location_[i];
		}
	}
	return NULL;
}