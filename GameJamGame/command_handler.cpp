#include "command_handler.h"
#include "types.h"

void CommandHandler::SetCommands(CommandList list_)
{
	movement_commands_.swap(list_.movement_);
	taking_commands_.swap(list_.taking_);
	placing_commands_.swap(list_.placing_);
	using_commands_.swap(list_.using_);
	checking_commands_.swap(list_.check_);


	movement_directions_.swap(list_.movement_directions_);
	items_in_room_.swap(list_.items_);
	locations_in_room_.swap(list_.locations_);

	movement_functions_.swap(list_.movement_functions_);
	using_item_functions_.swap(list_.using_item_functions_);
	taking_item_functions_.swap(list_.taking_item_functions_);
	placing_item_functions_.swap(list_.placing_item_functions_);
	special_functions_.swap(list_.special_functions_);

}

void CommandHandler::HandleCommand(int length, std::vector<std::string> arguments, Inventory* inventory_)
{
	unsigned_int32 type = 0;
	/*
	0: Action Commnad (go, walk, take, attack etc etc etc)
	1: Other
	*/

	for (signed int j = 0; j < length; j++)
	{
		/*
		Entire Command Structure
		Moving: "action" "direction"
				"action" "some other word" "direction"

		Taking: "action" "item name" "location"
				"action" "item name" "other word" "location
				"action" "other word" "item name" "location"
				"action" "other word" "item name" "other word" "location"

		Placing: "action" "item name" "location"
				 "action" "item name" "other word" "location
				 "action" "other word" "item name" "location"
				 "action" "other word" "item name" "other word" "location"

		Using: "action" "item name" "location"
			   "action" "item name" "other word" "location"
			   "action" "other word" "item name" "location"
			   "action" "other word" "item name" "other word" "location"
		
		*/

		

		//Action Commands can only be at Position 0
		uint32_t argument_ident_ = 0;

		std::string current_arg(arguments[j]);
		current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());

		for (uint32_t special_func_ = 0; special_func_ < special_functions_.size(); ++special_func_)
		{
			std::string current_arg(arguments[argument_ident_]);
			current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());
			
			if (special_functions_[special_func_]->command_name_ == current_arg)
			{
				if (arguments.size() > 2)
				{
					argument_ident_++;
					std::string current_arg(arguments[argument_ident_]);
					current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());
					//Find Item
					for (uint32_t item_choice = 0; item_choice < global_inventory_->GetAllItems().size(); ++item_choice)
					{
						if (global_inventory_->GetAllItems()[item_choice]->GetItemName() == current_arg)
						{
							if (special_functions_[special_func_]->function_name_inven != NULL)
							{
								special_functions_[special_func_]->function_name_inven(global_inventory_, global_inventory_->GetAllItems()[item_choice]->GetItemID());
							}
						}
					}
				}
				if (special_functions_[special_func_]->function_name_void_ != NULL)
				{
					special_functions_[special_func_]->function_name_void_();
					return;
				}
			}
		}

		//Movement Commands

		for (uint32_t movement_com_ = 0; movement_com_ < movement_commands_.size(); ++movement_com_)
		{
			if (movement_commands_[movement_com_] == arguments[0])
			{
				argument_ident_++; //Increment to the next argument
				std::string current_arg(arguments[argument_ident_]);
				current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());
				for (uint32_t movement_dir_ = 0; movement_dir_ < movement_directions_.size(); ++movement_dir_)
				{
					if (movement_directions_[movement_dir_] == current_arg)
					{
						//Found a Direction
						if (movement_functions_[movement_dir_]->is_locked)
						{
							if (inventory_->HasItem(movement_functions_[movement_dir_]->item_id_))
							{
								char* item_name_ = inventory_->GetItemName(movement_functions_[movement_dir_]->item_id_);
								printf("You use %s and unlocked the way", item_name_);
								if (movement_functions_.size() != 0)
								{
									if (movement_functions_[movement_dir_]->function_name_ != NULL)
									{
										movement_functions_[movement_dir_]->function_name_();
									}
								}
								
								return;
							}
							else
							{
								printf("You do not have the required item to unlock this path\n");
								return;
							}
						}
						else
						{
							printf("\n\nYou walk to the %s\n\n", movement_directions_[movement_dir_]);
							if (movement_functions_.size() != 0)
							{
								if (movement_functions_[movement_dir_]->function_name_ != NULL)
								{
									movement_functions_[movement_dir_]->function_name_();
								}
							}
							return;
						}
					}
				}
				//We have found an Action Commands

			}
		}

		//Item Taking Commands
		for (uint32_t taking_com_ = 0; taking_com_ < taking_commands_.size(); ++taking_com_)
		{
			if (taking_commands_[taking_com_] == arguments[0])
			{
				//Found a Take Commands
				argument_ident_++;
				std::string current_arg(arguments[argument_ident_]);
				current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());
				for (uint32_t item_id_ = 0; item_id_ < items_in_room_.size(); ++item_id_)
				{
					if (items_in_room_[item_id_]->GetItemName() == current_arg)
					{
						//Found an Item now check the Location
						argument_ident_++;
						if (arguments.size() > argument_ident_)
						{
							std::string current_arg(arguments[argument_ident_]);
							current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());
							for (uint32_t location_id_ = 0; location_id_ < locations_in_room_.size(); ++location_id_)
							{
								if (locations_in_room_[location_id_]->GetName() == current_arg)
								{
									if (locations_in_room_[location_id_]->GetItem(items_in_room_[item_id_]->GetItemID()))
									{
										if (taking_item_functions_.size() != 0)
										{
											if (taking_item_functions_[item_id_]->function_name_ != NULL)
											{
												taking_item_functions_[item_id_]->function_name_(locations_in_room_[location_id_], items_in_room_[item_id_]->GetItemID());
											}
										}
										return;
									}
								}
							}
						}
						//printf("Found Item\n");
						return;
					}
				}
			}

			
		}


		//Item Using Commands
		for (uint32_t using_com_ = 0; using_com_ < using_commands_.size(); ++using_com_)
		{
			if (using_commands_[using_com_] == arguments[0])
			{
				//Found a Take Commands
				argument_ident_++;
				std::string current_arg(arguments[argument_ident_]);
				current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());
				for (uint32_t item_id_ = 0; item_id_ < items_in_room_.size(); ++item_id_)
				{
					if (items_in_room_[item_id_]->GetItemName() == current_arg)
					{
						//Found an Item now check the Location
						argument_ident_++;
						if (arguments.size() > argument_ident_)
						{
							std::string current_arg(arguments[argument_ident_]);
							current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());
							for (unsigned_int32 location_id_ = 0; location_id_ < locations_in_room_.size(); ++location_id_)
							{
								if (locations_in_room_[location_id_]->GetName() == current_arg)
								{
									if (locations_in_room_[location_id_]->GetItem(items_in_room_[item_id_]->GetItemID()))
									{
										if (using_item_functions_.size() != 0)
										{
											if (using_item_functions_[item_id_]->function_name_ != NULL)
											{
												using_item_functions_[item_id_]->function_name_(locations_in_room_[location_id_], items_in_room_[item_id_]->GetItemID());
											}
										}
										return;
									}
								}
							}
						}
						//printf("Found Item\n");
						return;
					}
				}
			}
		}

		for (uint32_t check_com_ = 0; check_com_ < checking_commands_.size(); ++check_com_)
		{
			if (checking_commands_[check_com_] == arguments[0])
			{
				//Found the Check Command
				argument_ident_++;
				std::string current_arg(arguments[argument_ident_]);
				current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());
				for (uint32_t location_ident_ = 0; location_ident_ < locations_in_room_.size(); ++location_ident_)
				{
					if (locations_in_room_[location_ident_]->GetName() == current_arg)
					{
						system("@cls||clear");
						printf("List of Items at %s\n", locations_in_room_[location_ident_]->GetName());
						printf("------------------------------------\n");
						for (unsigned int z = 0; z < locations_in_room_[location_ident_]->ItemList().size(); ++z)
						{
							if (locations_in_room_[location_ident_]->ItemList()[z]->IsObtained() == false)
							{
								printf("%s\n", locations_in_room_[location_ident_]->ItemList()[z]->GetItemName());
							}
						}
						printf("\n");
						return;
					}
				}
				return;
			}
		}
		//Do Stuff with the Arguments

	}
}