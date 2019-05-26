#include "room.h"
#include "globals.h"
#include <ctype.h>
CommandHandler *handler = new CommandHandler();
Inventory *inventory = new Inventory();

Room::Room(char* room_name, float x, float y, float z, bool locked, unsigned int unlock_item, CommandList list_)
{
	required_item_ = unlock_item;
	locked_ = locked;
	x_ = x;
	y_ = y;
	z_ = z;
	room_name_ = room_name;
	for (unsigned int i = 0; i < list_.movement_.size(); ++i)
	{
		movement_commands_.push_back(list_.movement_[i]);
	}

	for (unsigned int i = 0; i < list_.taking_.size(); ++i)
	{
		taking_commands_.push_back(list_.taking_[i]);
	}

	for (unsigned int i = 0; i < list_.placing_.size(); ++i)
	{
		placing_commands_.push_back(list_.placing_[i]);
	}

	for (unsigned int i = 0; i < list_.using_.size(); ++i)
	{
		using_commands_.push_back(list_.using_[i]);
	}

	for (unsigned int i = 0; i < list_.movement_directions_.size(); ++i)
	{
		movement_directions_.push_back(list_.movement_directions_[i]);
	}

	for (unsigned int i = 0; i < list_.items_.size(); ++i)
	{
		items_in_room_.push_back(list_.items_[i]);
	}

	for (unsigned int i = 0; i < list_.locations_.size(); ++i)
	{
		locations_in_room_.push_back(list_.locations_[i]);
	}

	for (unsigned int i = 0; i < list_.movement_functions_.size(); ++i)
	{
		movement_functions_.push_back(list_.movement_functions_[i]);
	}

	for (unsigned int i = 0; i < list_.using_item_functions_.size(); ++i)
	{
		using_item_functions_.push_back(list_.using_item_functions_[i]);
	}

	for (unsigned int i = 0; i < list_.taking_item_functions_.size(); ++i)
	{
		taking_item_functions_.push_back(list_.taking_item_functions_[i]);
	}

	for (unsigned int i = 0; i < list_.placing_item_functions_.size(); ++i)
	{
		placing_item_functions_.push_back(list_.placing_item_functions_[i]);
	}

	for (unsigned int i = 0; i < list_.special_functions_.size(); ++i)
	{
		special_functions_.push_back(list_.special_functions_[i]);
	}
}

void Room::SetName(char* name_)
{
	room_name_ = name_;
}

char* Room::GetInput()
{
	
	return input_;
}

Vector3 Room::GetPosition()
{
	return Vector3((signed int)x_, (signed int)y_, (signed int)z_);
}

std::vector<char*>& Room::GetMovementComs()
{
	return movement_commands_;
}

std::vector<char*>& Room::GetTakingComs()
{
	return taking_commands_;
}

std::vector<char*>& Room::GetPlacingComs()
{
	return placing_commands_;
}

std::vector<char*>& Room::GetUsingComs()
{
	return using_commands_;
}

std::vector<char*>& Room::GetMovementDirs()
{
	return movement_directions_;
}

std::vector<Item*>& Room::GetItemsInRoom()
{
	return items_in_room_;
}

std::vector<Location*>& Room::GetLocationsInRoom()
{
	return locations_in_room_;
}

std::vector<MovementFunction*>& Room::GetMovementFunctions()
{
	return movement_functions_;
}

std::vector<ItemFunction*>& Room::GetUsingItemFunctions()
{
	return using_item_functions_;
}

std::vector<ItemFunction*>& Room::GetTakingItemFunctions()
{
	return taking_item_functions_;
}

std::vector<ItemFunction*>& Room::GetPlacingItemFunctions()
{
	return placing_item_functions_;
}

std::vector<char*>& Room::GetChecks()
{
	return check_commands_;
}

void Room::AddSpecialFunction(SpecialFunction* function_)
{
	special_functions_.push_back(function_);
}


void Room::Initilize()
{
	CommandList *list_ = new CommandList();
	list_->items_ = GetItemsInRoom();
	list_->using_item_functions_ = GetUsingItemFunctions();
	list_->taking_item_functions_ = GetTakingItemFunctions();
	list_->placing_item_functions_ = GetPlacingItemFunctions();
	list_->check_ = GetChecks();
	list_->locations_ = GetLocationsInRoom();
	list_->movement_ = GetMovementComs();
	list_->movement_directions_ = GetMovementDirs();
	list_->movement_functions_ = GetMovementFunctions();
	list_->placing_ = GetPlacingComs();
	list_->taking_ = GetTakingComs();
	list_->using_ = GetUsingComs();
	list_->special_functions_ = GetSpecialFunctions();
	handler->SetCommands(*list_);
}

std::vector<SpecialFunction*>& Room::GetSpecialFunctions()
{
	return special_functions_;
}

void Room::ListLocations()
{
	std::vector<Location*> temp_ = GetLocationsInRoom();
	for (unsigned int i = 0; i < temp_.size(); ++i)
	{
		printf("There is a [%s] here\n", temp_[i]->GetName());
	}
}

void Room::ListDirections()
{
	std::vector<char*> directions_ = GetMovementDirs();
	for (uint32_t i = 0; i < directions_.size(); ++i)
	{
		printf("You can move %s\n", directions_[i]);
	}
}

void Room::ListInventory()
{
	std::vector<Item*>& temp_ = global_inventory_->GetAllItems();
	printf("Your Inventory\n");
	printf("-----------------------------------\n");
	for (int i = 0; i < temp_.size(); ++i)
	{
		printf("%s\n", temp_[i]->GetItemName());
	}
	wait();
	system("@cls||clear");
	return;
}

void Room::Draw()
{
	//struct CommandList *list_ = new CommandList();
	//list_->
	//handler->SetCommands(GetActions(), GetOthers(), GetFunctions());
	//std::vector<char*> temp = GetActions();
	//std::vector<Text>::iterator text;
	/*for (text = dialogue_.begin(); text != dialogue_.end(); ++text)
	{

	//scanf("%*[^\n]\n");
	text->Print();

	}*/
	printf("-----------------------------------\n");
	for (uint32_t i = 0; i < dialogue_.size(); ++i)
	{
		dialogue_[i].Print();
	}
	ListLocations();
	if (this->room_name_ != "Main Menu")
	{
		ListDirections();
	}
	
	printf("-----------------------------------\n");

	printf("What do?: ");
	fgets(GetInput(), INT_MAX, stdin);
	char c[255];
	for (int i = 0; i < 255; ++i)
	{
		c[i] = tolower(GetInput()[i]);
	}
	std::istringstream ss(c);
	std::string token;
	std::vector<std::string> arguments;

	while (std::getline(ss, token, ' ')) {
		arguments.push_back(token);
	}
	std::string cc(c);
	cc.erase(std::remove(cc.begin(), cc.end(), '\n'), cc.end());
	if (cc == "inventory")
	{
		ListInventory();
		return;
	}
	handler->HandleCommand(arguments.size(), arguments, inventory);
}

void Room::AddMovementComs(char* command_)
{
	movement_commands_.push_back(command_);
}

void Room::AddTakingComs(char* command_)
{
	taking_commands_.push_back(command_);
}

void Room::AddPlacingComs(char* command_)
{
	placing_commands_.push_back(command_);
}

void Room::AddUsingComs(char* command_)
{
	using_commands_.push_back(command_);
}

void Room::AddCheck(char* command_)
{
	check_commands_.push_back(command_);
}

void Room::AddMovementDir(char* direction_)
{
	movement_directions_.push_back(direction_);
}

void Room::AddItemInRoom(Item* item_)
{
	items_in_room_.push_back(item_);
}

void Room::AddLocation(Location* location_)
{
	locations_in_room_.push_back(location_);
}

void Room::AddMovementFunc(MovementFunction* function_)
{
	movement_functions_.push_back(function_);
}

void Room::AddUsingItemFunc(ItemFunction* function_)
{
	using_item_functions_.push_back(function_);
}

void Room::AddTakingItemFunc(ItemFunction* function_)
{
	taking_item_functions_.push_back(function_);
}

void Room::AddPlacingItemFunc(ItemFunction* function_)
{
	placing_item_functions_.push_back(function_);
}

void Room::AddText(char* word_)
{
	dialogue_.push_back(Text(word_));
}

float Room::GetX()
{
	return x_;
}

float Room::GetY()
{
	return y_;
}

float Room::GetZ()
{
	return z_;
}

void Room::SetX(int x)
{
	x_ = (float)x;
}

void Room::SetY(int y)
{
	y_ = (float)y;
}

void Room::SetZ(int z)
{
	z_ = (float)z;
}

bool Room::IsLocked()
{
	return locked_;
}

void Room::SetLocked(bool tf)
{
	locked_ = tf;
}

unsigned int Room::GetUnlockItem()
{
	return required_item_;
}

void Room::SetLockItem(int item_)
{
	required_item_ = item_;
}