#include "item.h"


Item::Item(unsigned int item_id, char* item_name)
{
	item_id_ = item_id;
	item_name_ = item_name;
	obtained_ = false;
	sacrificed_ = false;
}

Item::~Item()
{

}

void Item::SetSacrificed(bool tf)
{
	sacrificed_ = tf;
}

bool Item::IsSacrificed()
{
	return sacrificed_;
}

unsigned int Item::GetItemID()
{
	return item_id_;
}

char* Item::GetItemName()
{
	return item_name_;
}

void Item::SetObtained(bool tf)
{
	obtained_ = tf;
}

bool Item::IsObtained()
{
	return obtained_;
}