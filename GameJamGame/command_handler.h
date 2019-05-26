#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include "item.h"
#include "location.h"
#include "inventory.h"

struct ItemFunction
{
	unsigned int item_id_; //ID Required to use to invoke Function
	void(*function_name_)(Location* location_, unsigned int id_); //Must pass in a location to use item on
};

struct MovementFunction
{
	bool is_locked; //Wether this Direction is Locked
	unsigned int item_id_; //Is Room is Locked Required Item to Unlock Room
	void(*function_name_)(void);
};

struct SpecialFunction
{
	char* command_name_;
	void(*function_name_full)(Location* _location, unsigned int id_);
	void(*function_name_)(Location* _location);
	void(*function_name_inven)(Inventory* inventory_, unsigned int id_);
	void(*function_name_void_)(void);
};

struct CommandList
{
	//Easy pass the entire list to the CommandHandler

	std::vector<char*> movement_;
	std::vector<char*> taking_;
	std::vector<char*> placing_;
	std::vector<char*> using_;
	std::vector<char*> check_;

	std::vector<char*> movement_directions_;
	std::vector<Item*> items_;
	std::vector<Location*> locations_;

	std::vector<ItemFunction*> using_item_functions_;
	std::vector<ItemFunction*> taking_item_functions_;
	std::vector<ItemFunction*> placing_item_functions_;
	std::vector<MovementFunction*> movement_functions_;

	std::vector<SpecialFunction*> special_functions_;
	
};






class CommandHandler
{
private:
	/*
	Commands:
	Movement Commands, An Action word that invokes walking
	Taking Commands, An Action word that invokes taking an item
	Placing Commands, An Action word that invokes placing an item
	Using Commands, An Action word that invokes using an item on something

	*/
	std::vector<char*> movement_commands_;
	std::vector<char*> taking_commands_;
	std::vector<char*> placing_commands_;
	std::vector<char*> using_commands_;
	std::vector<SpecialFunction*> special_functions_;

	/*
	Command Additives - Words that add onto the end of a command to do stuff
	Movement Directions, Combines with Movement Commands to move in those directions (1 Vector - Directions)
	Item Taking, Combines an Item Name and Location to take an item from that Location (1 Vectors - Item Names)
	Item Placing, Combines an Item Name and Location to place an item at that Location (Access to Inventory)
	Using on, Combines Inventory List and Locations in Room to use item on things

	*/

	std::vector<char*> movement_directions_; //Allows the Player to move in a specified direction
	std::vector<Item*> items_in_room_; //List of Items in the Room, For Taking Items
	std::vector<Location*> locations_in_room_;

	std::vector<MovementFunction*> movement_functions_;
	std::vector<ItemFunction*> using_item_functions_;
	std::vector<ItemFunction*> taking_item_functions_;
	std::vector<ItemFunction*> placing_item_functions_;
	
	std::vector<char*> checking_commands_; //Check a Location for Items

	char* current_action_;
	char* current_noun_;


public:
	CommandHandler()
	{
		/*action_commands_.push_back("go");
		action_commands_.push_back("walk");
		action_commands_.push_back("take");
		action_commands_.push_back("eat");
		action_commands_.push_back("use");

		other_words_.push_back("north");
		other_words_.push_back("south");
		other_words_.push_back("east");
		other_words_.push_back("south");*/

	}

	void SetCommands(CommandList list_);

	void HandleCommand(int length, std::vector<std::string> arguments, Inventory* inventory_);


};