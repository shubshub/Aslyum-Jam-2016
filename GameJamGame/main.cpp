#include "room.h"
#include <stdio.h>
#include "types.h"
#include "command_handler.h"
#include "globals.h"
#include "game_functions.h"
#include "advanced_boolean.h"
#include "game_endings.h"
std::vector<Room*> rooms;

std::vector<char*> all_movement_commands; //All Words Pertaining to Movement
std::vector<char*> all_check_commands; //All Words Pertaining to Checking Something
std::vector<char*> all_use_commands; //All Words Pertaining to Using Something
std::vector<char*> all_take_commands; //All Words Pertaining to Taking Something
std::vector<char*> all_place_commands; //All Words Pertaining to Placing Something

void WordInit()
{
	all_movement_commands.push_back("walk");
	all_movement_commands.push_back("go");
	all_movement_commands.push_back("traverse");
	all_movement_commands.push_back("teleport");
	all_movement_commands.push_back("run");
	all_movement_commands.push_back("crawl");
	all_movement_commands.push_back("move");
	all_movement_commands.push_back("enter");
	all_movement_commands.push_back("step");
	all_movement_commands.push_back("dash");

	all_check_commands.push_back("check");
	all_check_commands.push_back("look");
	all_check_commands.push_back("lookat");
	all_check_commands.push_back("open");
	all_check_commands.push_back("feel");
	all_check_commands.push_back("whatsin");
	all_check_commands.push_back("see");
	all_check_commands.push_back("list");

	all_use_commands.push_back("use");
	all_use_commands.push_back("activate");
	all_use_commands.push_back("try");
	all_use_commands.push_back("read");
	//all_use_commands.push_back("")

	all_take_commands.push_back("take");
	all_take_commands.push_back("steal");
	all_take_commands.push_back("obtain");
	all_take_commands.push_back("borrow");
	all_take_commands.push_back("assimilate");
	all_take_commands.push_back("aqcuire");
	all_take_commands.push_back("buy");
	all_take_commands.push_back("get");

	all_place_commands.push_back("place");
	all_place_commands.push_back("give");
	all_place_commands.push_back("sell");
	all_place_commands.push_back("handover");
	all_place_commands.push_back("handin");
	all_place_commands.push_back("put");


}

std::vector<char*> CreateActions(int length, char* arguments[])
{
	std::vector<char*> temp;
	for (int i = 0; i < length; ++i)
	{
		temp.push_back((char*)arguments[i]);
	}

	return temp;
}

void AddRoom(Room* input)
{
	rooms.push_back(input);
}

Room* GetRoom(int x, int y, int z)
{
	for (uint32_t i = 0; i < rooms.size(); ++i)
	{
		if (rooms[i]->GetPosition() == Vector3(x, y, z))
		{
			return rooms[i];
		}
	}
	return NULL;
}

void AddText(char* input_, Room* room_)
{
	Vector3 position = room_->GetPosition();
	GetRoom(position.x, position.y, position.z)->AddText(input_);
}



bool RoomExists(int x, int y, int z)
{
	for (uint32_t i = 0; i < rooms.size(); ++i)
	{
		if (rooms[i]->GetPosition() == Vector3(x, y, z))
		{
			return true;
		}
	}

	return false;
}



void update()
{
	GetRoom(GlobalGetX(), GlobalGetY(), GlobalGetZ())->Initilize();
	GetRoom(GlobalGetX(), GlobalGetY(), GlobalGetZ())->Draw();
	
}

void DirectionSetup()
{
	//All Movement Commands
	MovementFunction* move_north = new MovementFunction();
	move_north->function_name_ = North;

	MovementFunction* move_south = new MovementFunction();
	move_south->function_name_ = South;

	MovementFunction* move_east = new MovementFunction();
	move_east->function_name_ = East;

	MovementFunction* move_west = new MovementFunction();
	move_west->function_name_ = West;

	MovementFunction* move_up = new MovementFunction();
	move_up->function_name_ = zUp;

	MovementFunction* move_down = new MovementFunction();
	move_down->function_name_ = zBack;

	//End All Movement Commands

	for (unsigned int i = 0; i < rooms.size(); ++i)
	{
		Vector3 position = rooms[i]->GetPosition();
		if (RoomExists(position.x + 1, position.y, position.z))
		{
			rooms[i]->AddMovementDir("east");
			rooms[i]->AddMovementFunc(move_east);
		}

		if (RoomExists(position.x - 1, position.y, position.z))
		{
			rooms[i]->AddMovementDir("west");
			rooms[i]->AddMovementFunc(move_west);
		}

		if (RoomExists(position.x, position.y + 1, position.z))
		{
			rooms[i]->AddMovementDir("north");
			rooms[i]->AddMovementFunc(move_north);
		}

		if (RoomExists(position.x, position.y - 1, position.z))
		{
			if (position != Vector3(0, 1, 0))
			{
				rooms[i]->AddMovementDir("south");
				rooms[i]->AddMovementFunc(move_south);
			}
		}

		if (RoomExists(position.x, position.y, position.z + 1))
		{
			rooms[i]->AddMovementDir("up");
			rooms[i]->AddMovementFunc(move_up);
		}

		if (RoomExists(position.x, position.y, position.z - 1))
		{
			rooms[i]->AddMovementDir("down");
			rooms[i]->AddMovementFunc(move_down);
		}
	}
}
//Destroyable Items can be Global
Item* burned_book = new Item(1, "book");
Item* blood_knife = new Item(5, "knife");

void StartGame()
{
	GlobalOffsetY(1);
}

void PressEnter()
{
	/*
	-----------------------------------
Escape Sleepy Time
A Game Created in 48 Hours for the Asylum Jam 2016
Developed by Shubshub
Type 'Start' to start playing
-----------------------------------
What do?:

	*/
	system("@cls||clear");
	printf("-----------------------------------\n");
	printf("Escape Sleepy Time\n");
	printf("A Game Created in 48 Hours for the Asylum Jam 2016\n");
	printf("Developed by Shubshub\n");
	printf("Type 'Start' to start playing\n");
	printf("-----------------------------------\n");
	printf("What do?: start\n");
	_sleep(1000);
	GlobalOffsetY(1);
	system("@cls||clear");

}

void InitilizeGame()
{
	WordInit();
	
	game_flag_handle->SetFlag(1, false);
	game_flag_handle->SetFlag(2, false);
	game_flag_handle->SetFlag(3, false);
	game_flag_handle->SetFlag(4, false);
	game_flag_handle->SetFlag(5, false);
	game_flag_handle->SetFlag(6, false);
	game_flag_handle->SetFlag(7, false);
	game_flag_handle->SetFlag(8, false);
	game_flag_handle->SetFlag(9, false);


	CommandList temp_ = CommandList();
	//All Game Rooms + Location Set
	Room* main_menu_room_ = new Room(); //Main Menu
	main_menu_room_->SetName("Main Menu");
	Room* final_room_ = new Room("Escape Room", 0, -1, 0, true, 15, temp_);

	Room* awakening_room_ = new Room(); //Awakening Room
	Room* laboratory_room_ = new Room(); //Laboratory
	Room* hallway_room_ = new Room();
	Room* bedroom_room_ = new Room("Bedroom", 1, 3, 0, true, 2, temp_);
	Room* kitchen_room_ = new Room();
	Room* shrine_room_ = new Room();
	Room* cold_storage_room_ = new Room();

	//Location* final_door_ = new Location("platinumdoor");

	main_menu_room_->SetX(0);
	main_menu_room_->SetY(0);
	main_menu_room_->SetZ(0);

	awakening_room_->SetX(0);
	awakening_room_->SetY(1);
	awakening_room_->SetZ(0);

	laboratory_room_->SetX(0);
	laboratory_room_->SetY(2);
	laboratory_room_->SetZ(0);

	hallway_room_->SetX(0);
	hallway_room_->SetY(3);
	hallway_room_->SetZ(0);

	bedroom_room_->SetX(1);
	bedroom_room_->SetY(3);
	bedroom_room_->SetZ(0);

	kitchen_room_->SetX(-1);
	kitchen_room_->SetY(3);
	kitchen_room_->SetZ(0);

	shrine_room_->SetX(0);
	shrine_room_->SetY(4);
	shrine_room_->SetZ(0);

	cold_storage_room_->SetX(-1);
	cold_storage_room_->SetY(4);
	cold_storage_room_->SetZ(0);
	cold_storage_room_->SetLocked(true);
	cold_storage_room_->SetLockItem(500);

	awakening_room_->SetName("Awakening Room");
	laboratory_room_->SetName("Laboratory Room");
	hallway_room_->SetName("Hallway");
	bedroom_room_->SetName("Bedroom");
	kitchen_room_->SetName("Kitchen");
	shrine_room_->SetName("Shrine Room");
	cold_storage_room_->SetName("Cold Storage");

	//End All Rooms

	//All Items
	Item* awakening_book = new Item(0, "book"); //Fully Programmed
	awakening_book->SetObtained(false);
	burned_book->SetObtained(false);
	Item* diamond_key = new Item(2, "diamondkey");
	diamond_key->SetObtained(false);
	Item* bedside_lamp = new Item(3, "bedsidelamp");
	bedside_lamp->SetObtained(false);
	Item* war_diary = new Item(4, "diary");
	war_diary->SetObtained(false);
	
	blood_knife->SetObtained(false);
	Item* time_box = new Item(6, "timebox");
	time_box->SetObtained(false);
	Item* platinum_key = new Item(15, "platinumkey");
	platinum_key->SetObtained(false);

	Item* self_sac = new Item(7000, "self");

	//Laboratory Buttons
	Item* lab_button_1 = new Item(256, "button_1");
	lab_button_1->SetObtained(false);
	Item* lab_button_2 = new Item(257, "button_2");
	lab_button_2->SetObtained(false);
	Item* lab_button_3 = new Item(258, "button_3");
	lab_button_3->SetObtained(false);
	Item* lab_button_4 = new Item(259, "button_4");
	lab_button_4->SetObtained(false);
	Item* lab_button_5 = new Item(260, "button_5");
	lab_button_5->SetObtained(false);
	Item* lab_button_6 = new Item(261, "button_6");
	lab_button_6->SetObtained(false);
	Item* lab_button_7 = new Item(262, "button_7");
	lab_button_7->SetObtained(false);
	Item* lab_button_8 = new Item(263, "button_8");
	lab_button_8->SetObtained(false);
	Item* lab_button_9 = new Item(264, "button_9");
	lab_button_9->SetObtained(false);
	Item* lab_text_thingity = new Item(453456, "Type controlpanel to use the panel");
	lab_text_thingity->SetObtained(false);

	//Misc Items that Just tell Stories
	Item* pupununu_game_ = new Item(7, "oldgame"); //Tak and the Power of Juju Easter Egg
	pupununu_game_->SetObtained(false);
	Item* kingdom_game_ = new Item(8, "squaregame"); //Kingdom Hearts Easter Egg
	kingdom_game_->SetObtained(false);
	Item* cloud_game_ = new Item(9, "darkgame"); //Dark Chronicle Easter Egg
	cloud_game_->SetObtained(false);
	Item* human_history_book_ = new Item(400, "historybook");
	human_history_book_->SetObtained(false);
	Item* final_message_book_ = new Item(401, "finalentry");
	final_message_book_->SetObtained(false);

	//End All Items

	//All Locations
	Location* box_with_items = new Location("box");
	Location* table_with_items = new Location("table");
	Location* laboratory_panel = new Location("panel");
	Location* hallway_shelf = new Location("shelf");
	Location* sacrificial_shrine = new Location("shrine");
	Location* bedside_table = new Location("table");
	Location* bed_bed_bed = new Location("bed");
	Location* kitchen_bench = new Location("bench");
	Location* bedroom_door = new Location("door");
	Location* final_door_ = new Location("platinumdoor");
	Location* time_box_loc = new Location("time_box");
	//End All Locations

	//Add All Commands

	//Main Menu
	//main_menu_room_->AddMovementComs("start");
	//main_menu_room_->AddMovementDir("");

	SpecialFunction* start_game = new SpecialFunction();
	start_game->command_name_ = "start";
	start_game->function_name_void_ = StartGame;

	SpecialFunction* default_enter = new SpecialFunction();
	default_enter->command_name_ = "";
	default_enter->function_name_void_ = PressEnter;
	main_menu_room_->AddSpecialFunction(start_game);
	main_menu_room_->AddSpecialFunction(default_enter);


	for (unsigned int i = 0; i < all_movement_commands.size(); ++i)
	{
		awakening_room_->AddMovementComs(all_movement_commands[i]);
		laboratory_room_->AddMovementComs(all_movement_commands[i]);
		hallway_room_->AddMovementComs(all_movement_commands[i]);
		bedroom_room_->AddMovementComs(all_movement_commands[i]);
		kitchen_room_->AddMovementComs(all_movement_commands[i]);
		shrine_room_->AddMovementComs(all_movement_commands[i]);
		cold_storage_room_->AddMovementComs(all_movement_commands[i]);
	}

	for (unsigned int i = 0; i < all_check_commands.size(); ++i)
	{
		awakening_room_->AddCheck(all_check_commands[i]);
		laboratory_room_->AddCheck(all_check_commands[i]);
		hallway_room_->AddCheck(all_check_commands[i]);
		bedroom_room_->AddCheck(all_check_commands[i]);
		kitchen_room_->AddCheck(all_check_commands[i]);
		shrine_room_->AddCheck(all_check_commands[i]);
		cold_storage_room_->AddCheck(all_check_commands[i]);
	}

	for (unsigned int i = 0; i < all_place_commands.size(); ++i)
	{
		awakening_room_->AddPlacingComs(all_place_commands[i]);
		laboratory_room_->AddPlacingComs(all_place_commands[i]);
		hallway_room_->AddPlacingComs(all_place_commands[i]);
		bedroom_room_->AddPlacingComs(all_place_commands[i]);
		kitchen_room_->AddPlacingComs(all_place_commands[i]);
		shrine_room_->AddPlacingComs(all_place_commands[i]);
		cold_storage_room_->AddPlacingComs(all_place_commands[i]);
	}

	for (unsigned int i = 0; i < all_take_commands.size(); ++i)
	{
		awakening_room_->AddTakingComs(all_take_commands[i]);
		laboratory_room_->AddTakingComs(all_take_commands[i]);
		hallway_room_->AddTakingComs(all_take_commands[i]);
		bedroom_room_->AddTakingComs(all_take_commands[i]);
		kitchen_room_->AddTakingComs(all_take_commands[i]);
		shrine_room_->AddTakingComs(all_take_commands[i]);
		cold_storage_room_->AddTakingComs(all_take_commands[i]);
	}

	for (unsigned int i = 0; i < all_use_commands.size(); ++i)
	{
		awakening_room_->AddUsingComs(all_use_commands[i]);
		laboratory_room_->AddUsingComs(all_use_commands[i]);
		hallway_room_->AddUsingComs(all_use_commands[i]);
		bedroom_room_->AddUsingComs(all_use_commands[i]);
		kitchen_room_->AddUsingComs(all_use_commands[i]);
		shrine_room_->AddUsingComs(all_use_commands[i]);
		cold_storage_room_->AddUsingComs(all_use_commands[i]);
	}


	//End All Commands

	//Add Rooms
	AddRoom(main_menu_room_);
	AddRoom(awakening_room_);
	AddRoom(laboratory_room_);
	AddRoom(hallway_room_);
	AddRoom(bedroom_room_);
	AddRoom(kitchen_room_);
	AddRoom(shrine_room_);
	AddRoom(cold_storage_room_);
	//End All Rooms

	//Items at Location
	table_with_items->PlaceItem(awakening_book);
	table_with_items->PlaceItem(kingdom_game_);

	box_with_items->PlaceItem(diamond_key);
	box_with_items->PlaceItem(pupununu_game_);

	//Bedside Table
	bedside_table->PlaceItem(war_diary);

	//Laboratory Buttons on Panel
	laboratory_panel->PlaceItem(lab_button_1);
	laboratory_panel->PlaceItem(lab_button_2);
	laboratory_panel->PlaceItem(lab_button_3);
	laboratory_panel->PlaceItem(lab_button_4);
	laboratory_panel->PlaceItem(lab_button_5);
	laboratory_panel->PlaceItem(lab_button_6);
	laboratory_panel->PlaceItem(lab_button_7);
	laboratory_panel->PlaceItem(lab_button_8);
	laboratory_panel->PlaceItem(lab_button_9);
	laboratory_panel->PlaceItem(lab_text_thingity);
	//End Laboratory Buttons on Panel

	hallway_shelf->PlaceItem(burned_book);;

	bedside_table->PlaceItem(war_diary);
	bedside_table->PlaceItem(bedside_lamp);


	kitchen_bench->PlaceItem(blood_knife);

	sacrificial_shrine->PlaceItem(platinum_key);

	time_box_loc->PlaceItem(cloud_game_);
	
	//End Items at Location

	//Item Functions
	ItemFunction* war_diary_use_ = new ItemFunction();
	war_diary_use_->function_name_ = WarDiary_Use;

	ItemFunction* war_diary_take = new ItemFunction();
	war_diary_take->function_name_ = WarDiary_Take;

	ItemFunction* awakening_book_read_ = new ItemFunction();
	awakening_book_read_->function_name_ = AwakeningBook_Use;
	ItemFunction* awakening_book_take = new ItemFunction();
	awakening_book_take->function_name_ = AwakeningBook_Take;

	ItemFunction* diamond_key_take = new ItemFunction();
	diamond_key_take->function_name_ = DiamondKey_Take;


	ItemFunction* platinum_key_take = new ItemFunction();
	platinum_key_take->function_name_ = PlatinumKey_Take;

	ItemFunction* burned_book_use = new ItemFunction();
	burned_book_use->function_name_ = BurnedBook_Use;

	ItemFunction* burned_book_take = new ItemFunction();
	burned_book_take->function_name_ = BurnedBook_Take;

	ItemFunction* take_oldgame_ = new ItemFunction();
	take_oldgame_->function_name_ = TakGame_EasterEgg_Take;

	ItemFunction* take_kingdomgame = new ItemFunction();
	take_kingdomgame->function_name_ = KingdomGame_EasterEgg_Take;

	ItemFunction* take_cloudgame = new ItemFunction();
	take_cloudgame->function_name_ = DarkCloudGame_EasterEgg_Take;

	ItemFunction* read_oldgame = new ItemFunction();
	read_oldgame->function_name_ = TakGame_EasterEgg_Read;

	ItemFunction* read_kingdomgame = new ItemFunction();
	read_kingdomgame->function_name_ = KingdomGame_EasterEgg_Read;

	ItemFunction* read_cloudgame = new ItemFunction();
	read_cloudgame->function_name_ = DarkCloudGame_EasterEgg_Read;
	
	//Add Locations to Room
	awakening_room_->AddLocation(table_with_items);
	awakening_room_->AddItemInRoom(awakening_book);
	awakening_room_->AddItemInRoom(kingdom_game_);
	
	awakening_room_->AddUsingItemFunc(awakening_book_read_);
	awakening_room_->AddTakingItemFunc(awakening_book_take);
	awakening_room_->AddTakingItemFunc(take_kingdomgame);
	awakening_room_->AddUsingItemFunc(read_kingdomgame);
	laboratory_room_->AddLocation(box_with_items);
	laboratory_room_->AddItemInRoom(diamond_key);
	laboratory_room_->AddItemInRoom(pupununu_game_);
	laboratory_room_->AddTakingItemFunc(diamond_key_take);
	laboratory_room_->AddTakingItemFunc(take_oldgame_);
	laboratory_room_->AddUsingItemFunc(NULL);
	laboratory_room_->AddUsingItemFunc(read_oldgame);
	laboratory_room_->AddLocation(laboratory_panel);
	laboratory_room_->AddItemInRoom(lab_button_1);
	laboratory_room_->AddItemInRoom(lab_button_2);
	laboratory_room_->AddItemInRoom(lab_button_3);
	laboratory_room_->AddItemInRoom(lab_button_4);
	laboratory_room_->AddItemInRoom(lab_button_5);
	laboratory_room_->AddItemInRoom(lab_button_6);
	laboratory_room_->AddItemInRoom(lab_button_7);
	laboratory_room_->AddItemInRoom(lab_button_8);
	laboratory_room_->AddItemInRoom(lab_button_9);
	

	bedroom_room_->AddLocation(bedside_table);
	bedroom_room_->AddItemInRoom(war_diary);
	bedroom_room_->AddUsingItemFunc(war_diary_use_);
	bedroom_room_->AddTakingItemFunc(war_diary_take);

	shrine_room_->AddLocation(sacrificial_shrine);
	shrine_room_->AddItemInRoom(platinum_key);
	shrine_room_->AddTakingItemFunc(platinum_key_take);

	hallway_room_->AddLocation(hallway_shelf);
	hallway_room_->AddItemInRoom(burned_book);
	hallway_room_->AddUsingItemFunc(burned_book_use);
	hallway_room_->AddTakingItemFunc(burned_book_take);
	

	SpecialFunction* laboratory_panel_use = new SpecialFunction();
	laboratory_panel_use->command_name_ = "controlpanel";
	laboratory_panel_use->function_name_void_ = SpecialFunction_ControlPanel;

	laboratory_room_->AddSpecialFunction(laboratory_panel_use);

	SpecialFunction* destroy_burned_book = new SpecialFunction();
	destroy_burned_book->command_name_ = "destroybook";
	destroy_burned_book->function_name_void_ = BurnedBook_Destroy;

	SpecialFunction* destroy_blood_knife = new SpecialFunction();
	destroy_blood_knife->command_name_ = "destroyknife";
	destroy_blood_knife->function_name_void_ = BloodyKnife_Destroy;

	SpecialFunction* timebox_restore = new SpecialFunction();
	timebox_restore->command_name_ = "usebox";
	timebox_restore->function_name_void_ = SpecialFunction_TimeBox;

	SpecialFunction* final_door_use_thing_ = new SpecialFunction();
	final_door_use_thing_->command_name_ = "escape";
	final_door_use_thing_->function_name_void_ = SpecialFunction_PlatinumDoor;

	ItemFunction* take_blood_knife = new ItemFunction();
	take_blood_knife->function_name_ = BloodyKnife_Take;

	hallway_room_->AddSpecialFunction(destroy_burned_book);
	kitchen_room_->AddSpecialFunction(destroy_blood_knife);
	kitchen_room_->AddLocation(kitchen_bench);
	kitchen_room_->AddItemInRoom(blood_knife);
	kitchen_room_->AddTakingItemFunc(take_blood_knife);
	cold_storage_room_->AddSpecialFunction(timebox_restore);
	cold_storage_room_->AddLocation(time_box_loc);
	cold_storage_room_->AddItemInRoom(cloud_game_);
	cold_storage_room_->AddTakingItemFunc(take_cloudgame);
	cold_storage_room_->AddUsingItemFunc(read_cloudgame);

	//End Locations to Room

	SpecialFunction* sacrifice_items = new SpecialFunction();
	sacrifice_items->command_name_ = "sacrifice";
	sacrifice_items->function_name_inven = SpecialFunction_Sacrifice;
	shrine_room_->AddSpecialFunction(sacrifice_items);

	//All Text

	//Main Menu Text
	AddText("Escape Sleepy Time\n", main_menu_room_);
	AddText("A Game Created in 48 Hours for the Asylum Jam 2016\n", main_menu_room_);
	AddText("Developed by Shubshub\n", main_menu_room_);
	AddText("Type 'Start' to start playing\n", main_menu_room_);
	//End Main Menu Text

	//Awakening Room Text
	
	AddText("Awakening Room\n\n", awakening_room_);
	AddText("You find yourself in a strange room\n", awakening_room_);
	AddText("You have no idea where you are...\n", awakening_room_);
	AddText("Perhaps we should try and find our way out..\n", awakening_room_);
	AddText("A voice speaks to you 'If you wish to escape.... just type escape...'\n", awakening_room_);
	AddText("'Your actions will be tested against however... so... try not to escape right away or I'll kill you'\n", awakening_room_);
	awakening_room_->AddSpecialFunction(final_door_use_thing_);
	
	//Laboratory Room Text

	AddText("Laboratory Room\n\n", laboratory_room_);
	AddText("You find yourself in a room full of technology\n", laboratory_room_);
	AddText("Along the side of the wall is a panel full of buttons\n", laboratory_room_);

	//Hallway Room Text
	AddText("Hallway\n\n", hallway_room_);
	AddText("You appear to be in some long corridor\n", hallway_room_);
	AddText("There are rooms on both the left and right hand sides of the wall\n", hallway_room_);
	AddText("At the far end is a door with a sign labeled 'Shrine Room'\n", hallway_room_);

	//Bedroom Text
	AddText("Bedroom\n\n", bedroom_room_);
	AddText("You find yourself in a bedroom of sorts\n", bedroom_room_);
	AddText("There are things that a bed would normally have they are all here\n", bedroom_room_);
	AddText("There appears to be what is the remains of a human corpse lying on the ground covered in blood\n", bedroom_room_);

	//Kitchen Text
	AddText("Kitchen\n\n", kitchen_room_);
	AddText("You find yourself in a kitchen\n", kitchen_room_);
	AddText("There are kitchen appliances scattered about the room\n", kitchen_room_);

	//Shrine Room
	AddText("Shrine Room\n\n", shrine_room_);
	AddText("You find yourself in a room which appears to be devoid of any unclean subtance\n", shrine_room_);
	AddText("You can sacrifice items to the shrine... by typing 'sacrifice [item] shrine'\n", shrine_room_);

	AddText("Cold Storage\n\n", cold_storage_room_);
	AddText("You find yourself in a very cold place, what appears to be a room for cold things\n", cold_storage_room_);
	AddText("There is a strange box here, type [usebox] to see what its all about\n", cold_storage_room_);
	
	//End All Text

	


	global_inventory_->ObtainItem(self_sac);

	DirectionSetup();


}


int main(int argc, char **argv)
{
	
	InitilizeGame();
	//SpecialFunction_ControlPanel();
	while (1)
	{
		update();
		if (game_flag_handle->GetFlag(1) == true)
		{
			burned_book->SetObtained(true);
		}
		if (game_flag_handle->GetFlag(10) == true)
		{
			blood_knife->SetObtained(true);
		}
	}
	return 0;
}