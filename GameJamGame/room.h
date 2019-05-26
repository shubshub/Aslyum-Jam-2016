#pragma once
#include <vector>
#include <sstream>
#include "text.h"
#include "types.h"
#include "command_handler.h"
#include "inventory.h"
#include "game_endings.h"

class Room
{
private:
	float x_, y_, z_;
	char* room_name_;
	std::vector<Text> dialogue_;
	
	std::vector<char*> movement_commands_;
	std::vector<char*> taking_commands_;
	std::vector<char*> placing_commands_;
	std::vector<char*> using_commands_;
	std::vector<char*> check_commands_;

	std::vector<char*> movement_directions_; //Allows the Player to move in a specified direction
	std::vector<Item*> items_in_room_; //List of Items in the Room, For Taking Items
	std::vector<Location*> locations_in_room_;

	std::vector<MovementFunction*> movement_functions_;
	std::vector<ItemFunction*> using_item_functions_;
	std::vector<ItemFunction*> taking_item_functions_;
	std::vector<ItemFunction*> placing_item_functions_;
	std::vector<SpecialFunction*> special_functions_;

	char input_[255];
	bool locked_ = false;
	unsigned int required_item_ = 0; //Required Item to Unlock Room
public:

	Room(char* room_name, float x, float y, float z, bool locked, unsigned int unlock_item, CommandList list_);
	Room() {};

	char* GetInput();

	Vector3 GetPosition();

	void ListInventory();
	//Get
	std::vector<char*>& GetMovementComs();
	std::vector<char*>& GetTakingComs();
	std::vector<char*>& GetPlacingComs();
	std::vector<char*>& GetUsingComs();

	std::vector<char*>& GetMovementDirs();
	std::vector<Item*>& GetItemsInRoom();
	std::vector<Location*>& GetLocationsInRoom();
	std::vector<MovementFunction*>& GetMovementFunctions();
	std::vector<ItemFunction*>& GetUsingItemFunctions();
	std::vector<ItemFunction*>& GetTakingItemFunctions();
	std::vector<ItemFunction*>& GetPlacingItemFunctions();
	std::vector<SpecialFunction*>& GetSpecialFunctions();

	std::vector<char*>& GetChecks();

	//Set
	void AddMovementComs(char*);
	void AddTakingComs(char*);
	void AddPlacingComs(char*);
	void AddUsingComs(char*);
	void AddCheck(char*);
	void SetName(char*);

	void AddMovementDir(char*);
	void AddItemInRoom(Item*);
	void AddLocation(Location*);
	void AddMovementFunc(MovementFunction*);
	void AddUsingItemFunc(ItemFunction*);
	void AddTakingItemFunc(ItemFunction*);
	void AddPlacingItemFunc(ItemFunction*);
	void AddSpecialFunction(SpecialFunction*);

	void Initilize(); //For Manual Initilization

	void Draw();
	void ListLocations();
	void ListDirections();

	void AddText(char* word_);

	float GetX();

	float GetY();

	float GetZ();

	void SetX(int);
	void SetY(int);
	void SetZ(int);
	void SetLockItem(int item_);

	bool IsLocked();
	void SetLocked(bool);
	unsigned int GetUnlockItem();
};

extern std::vector<Room*> rooms;