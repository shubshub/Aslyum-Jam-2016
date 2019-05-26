#pragma once
class Item
{
private:
	unsigned int item_id_;
	char* item_name_;
	bool obtained_ = false; //Only really useful if its in the Room
	bool sacrificed_ = false;
public:
	Item(unsigned int item_id, char* item_name);
	~Item();

	unsigned int GetItemID();
	char* GetItemName();
	void SetObtained(bool tf);
	bool IsObtained();
	bool IsSacrificed();
	void SetSacrificed(bool tf);
	//Operator Overloads
	bool operator==(const Item &i)
	{
		if (item_id_ == i.item_id_)
		{
			if (item_name_ == i.item_name_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}


};