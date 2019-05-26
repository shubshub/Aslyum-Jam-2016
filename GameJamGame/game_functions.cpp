#include "game_functions.h"
#include "globals.h"
#include "inventory.h"
#include <stdlib.h>
#include "room.h"
#include "game_endings.h"
//Game Functions for doing things in the game

Room* GetRoomGlobal(signed int x, signed int y, signed int z)
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

void PlayGame()
{
	GlobalOffsetY(1);
}

char* GetItemName(unsigned int id_)
{
	switch (id_)
	{
	case 0:
		return "Awakening Book";
		break;
	case 1:
		return "Burned Book";
		break;
	case 2:
		return "Diamond Key";
		break;
	case 3:
		return "Bedside Lamp";
		break;
	case 4:
		return "War Diary";
		break;
	case 5:
		return "Bloody Knife";
		break;
	case 6:
		return "Time Box";
		break;
	case 7:
		return "Old Game";
		break;
	case 8:
		return "Square Game";
		break;
	case 9:
		return "Dark Game";
		break;
	case 15:
		return "Platinum Key";
		break;
	default:
		return "Undefined Item";
	}
}

void North()
{
	GlobalOffsetY(1);
	Room* temp_ = GetRoomGlobal(GlobalGetX(), GlobalGetY(), GlobalGetZ());
	if (temp_->IsLocked())
	{
		if (global_inventory_->HasItem(temp_->GetUnlockItem()))
		{
			printf("You insert the %s into the lock and the door opens\n", global_inventory_->GetItemName(temp_->GetUnlockItem()));
			temp_->SetLocked(false);
			wait();
			system("@cls||clear");
			return;
		}
		printf("The pathway is locked you require a %s\n", GetItemName(temp_->GetUnlockItem()));
		GlobalOffsetY(-1);
	}
	wait();
	system("@cls||clear");
}

void South()
{
	GlobalOffsetY(-1);
	Room* temp_ = GetRoomGlobal(GlobalGetX(), GlobalGetY(), GlobalGetZ());
	if (temp_->IsLocked())
	{
		if (global_inventory_->HasItem(temp_->GetUnlockItem()))
		{
			printf("You insert the %s into the lock and the door opens\n", global_inventory_->GetItemName(temp_->GetUnlockItem()));
			temp_->SetLocked(false);
			wait();
			system("@cls||clear");
			return;
		}
		printf("The pathway is locked you require a %s\n", GetItemName(temp_->GetUnlockItem()));
		GlobalOffsetY(1);
	}
	wait();
	system("@cls||clear");
}

void East()
{
	GlobalOffsetX(1);
	Room* temp_ = GetRoomGlobal(GlobalGetX(), GlobalGetY(), GlobalGetZ());
	if (temp_->IsLocked())
	{
		if (global_inventory_->HasItem(temp_->GetUnlockItem()))
		{
			printf("You insert the %s into the lock and the door opens\n", global_inventory_->GetItemName(temp_->GetUnlockItem()));
			temp_->SetLocked(false);
			wait();
			system("@cls||clear");
			return;
		}
		printf("The pathway is locked you require a %s\n", GetItemName(temp_->GetUnlockItem()));
		GlobalOffsetX(-1);
	}
	wait();
	system("@cls||clear");
}

void West()
{
	GlobalOffsetX(-1);
	Room* temp_ = GetRoomGlobal(GlobalGetX(), GlobalGetY(), GlobalGetZ());
	if (temp_->IsLocked())
	{
		if (global_inventory_->HasItem(temp_->GetUnlockItem()))
		{
			printf("You insert the %s into the lock and the door opens\n", global_inventory_->GetItemName(temp_->GetUnlockItem()));
			temp_->SetLocked(false);
			wait();
			system("@cls||clear");
			return;
		}
		printf("The pathway is locked you require a %s\n", GetItemName(temp_->GetUnlockItem()));
		GlobalOffsetX(1);
	}
	wait();
	system("@cls||clear");
}

void zUp()
{
	GlobalOffsetZ(1);
	Room* temp_ = GetRoomGlobal(GlobalGetX(), GlobalGetY(), GlobalGetZ());
	if (temp_->IsLocked())
	{
		if (global_inventory_->HasItem(temp_->GetUnlockItem()))
		{
			printf("You insert the %s into the lock and the door opens\n", global_inventory_->GetItemName(temp_->GetUnlockItem()));
			temp_->SetLocked(false);
			wait();
			system("@cls||clear");
			return;
		}
		printf("The pathway is locked you require a %s\n", GetItemName(temp_->GetUnlockItem()));
		GlobalOffsetZ(-1);
	}
	wait();
	system("@cls||clear");
}

void zBack()
{
	GlobalOffsetZ(-1);
	Room* temp_ = GetRoomGlobal(GlobalGetX(), GlobalGetY(), GlobalGetZ());
	if (temp_->IsLocked())
	{
		if (global_inventory_->HasItem(temp_->GetUnlockItem()))
		{
			printf("You insert the %s into the lock and the door opens\n", global_inventory_->GetItemName(temp_->GetUnlockItem()));
			temp_->SetLocked(false);
			wait();
			system("@cls||clear");
			return;
		}
		printf("The pathway is locked you require a %s\n", GetItemName(temp_->GetUnlockItem()));
		GlobalOffsetZ(1);
	}
	wait();
	system("@cls||clear");
}

void Take()
{
	//TODO: Item Code
}

void AwakeningBook_Use(Location* _location, unsigned int id_)
{
	if (_location->GetItem(id_) && !_location->GetItem(id_)->IsObtained())
	{
		system("@cls||clear");
		printf("You pick the book up and begin reading it...\n\n");
		printf("You have been kidnapped..., But not for real..., Well... it is real... but its also not\n");
		printf("Welcome to the space.... The Dreamworld you might call it...\nA place where those that sleep visit with grace\n");
		printf("But you are not asleep now... I'm going to find you... And I'm going to kill you... There's no point in trying to escape\n\n");
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that Location\n\n");
		wait();
		return;
	}
}

void AwakeningBook_Take(Location* _location, unsigned int id_)
{
	if (_location->GetItem(id_))
	{
		printf("Its best if you just leave the book here for others to [read]\n\n");
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that Location\n\n");
		wait();
		return;
	}
}

void BurnedBook_Use(Location * _location, unsigned int id_)
{
	if (_location->GetItem(id_))
	{
		printf("You pick up the slightly charred remains of a book and begin reading\n");
		printf("The War - 1996 -> 2567 -\n");
		printf("\n\n");
		printf("The year is 2567... My name is -Burned Out-\n");
		printf("Its right outside my door... I can hear it... calling for me -Burned Out-\n");
		printf("Whoever may one day read this... come save me... I'm going to make my way to the cold storage");
		printf("\n\n\nThe rest of the book is too charred to make out, Perhaps I can [restore] it somehow\n");
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that location\n");
		wait();
		return;
	}
}

void BurnedBook_Take(Location * _location, unsigned int id_)
{
	if (_location->GetItem(id_) && _location->GetItem(id_)->IsObtained() == false)
	{
		printf("You take the %s and put it in your bag\n", _location->GetItem(id_)->GetItemName());
		_location->GetItem(id_)->SetObtained(true);
		global_inventory_->ObtainItem(_location->GetItem(id_));
		game_flag_handle->ModifySoul(10);
		game_flag_handle->SetFlag(18, true);
		game_flag_handle->SetFlag(1, true);
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that location\n");
	}
}

void BurnedBook_Destroy()
{
	//TODO Item Destruction Code
	if (game_flag_handle->GetFlag(1) == false)
	{
		printf("You pick up the burned book, And begin tearing it apart...\n");
		printf("You feel slighlty worse... Are you happy with yourself?\n");
		game_flag_handle->SetFlag(1, true);
		game_flag_handle->ModifySoul(-10);
		wait();
		return;
		//global_inventory_->ObtainItem(_location->GetItem(id_));
	}
	else
	{
		printf("No such item exists at that location\n");
	}
	
}

void BurnedBook_Place(Location * _location, unsigned int id_)
{

}

void DiamondKey_Use(Location * _location, unsigned int id_)
{
}

void DiamondKey_Take(Location * _location, unsigned int id_)
{
	if (_location->GetItem(id_) && _location->GetItem(id_)->IsObtained() == false)
	{
		printf("You take the %s and put it in your bag\n", _location->GetItem(id_)->GetItemName());
		_location->GetItem(id_)->SetObtained(true);
		global_inventory_->ObtainItem(_location->GetItem(id_));
		
	}
	else
	{
		printf("No such item exists at that location\n");
	}
}

void DiamondKey_Place(Location * _location, unsigned int id_)
{
}

void BedsideLamp_Use(Location * _location, unsigned int id_)
{
}

void BedsideLamp_Take(Location * _location, unsigned int id_)
{
}

void BedsideLamp_Place(Location * _location, unsigned int id_)
{
}

void WarDiary_Use(Location * _location, unsigned int id_)
{
	if (_location->GetItem(id_))
	{
		printf("Thank god... It's finally over...\n");
		printf("The war... it seems like forever, It lasted too long.\n");
		printf("The fact that I am still writing... is a miracle itself.\n");
		printf("The fallout will hit my area soon, and I won't live for much longer\n");
		printf("They've released several nuclear bombs... its what caused the fallout\n");
		printf("It's starting to look like this is the end for me\n");
		printf("The dotVirus is starting to set in, and I can't stop it. Nobody can...\n");
		printf("It's what they've been unleashing in their nuclear bombs\n");
		printf("Nobody knows why it didn't get incinerated in the explosion\n");
		printf("...JaeobLabs they developed the experimental virus to attack the enemy\n");
		printf("..But.. it went rogue and now its unstoppable\n");
		printf("...There's something here!. I'll wri-------\n\n\n");
		printf("- The rest of the note appears to be covered in blood -\n");
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that location");
		wait();
		return;
	}

}

void WarDiary_Take(Location * _location, unsigned int id_)
{
	if (_location->GetItem(id_) && _location->GetItem(id_)->IsObtained() == false)
	{
		printf("You take the %s and put it in your bag\n", _location->GetItem(id_)->GetItemName());
		_location->GetItem(id_)->SetObtained(true);
		global_inventory_->ObtainItem(_location->GetItem(id_));
		game_flag_handle->ModifySoul(-30);
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that location\n");
		wait();
		return;
	}
}

void WarDiary_Place(Location * _location, unsigned int id_)
{
}

void BloodyKnife_Use(Location * _location, unsigned int id_)
{
}

void BloodyKnife_Take(Location * _location, unsigned int id_)
{
	if (_location->GetItem(id_) && _location->GetItem(id_)->IsObtained() == false)
	{
		printf("You take the %s and put it in your bag\n", _location->GetItem(id_)->GetItemName());
		_location->GetItem(id_)->SetObtained(true);
		global_inventory_->ObtainItem(_location->GetItem(id_));
		game_flag_handle->SetFlag(10, true);
		game_flag_handle->ModifySoul(-10);
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that location\n");
		wait();
		return;
	}
}

void BloodyKnife_Destroy()
{
	if (game_flag_handle->GetFlag(10) == false)
	{
		printf("You pick up the blood stained knife and attempt to break it\n");
		printf("The tough metal eventually gives away and breaks in half\n");
		printf("You feel slightly better, Are you happy?");
		game_flag_handle->SetFlag(10, true);
		game_flag_handle->ModifySoul(10);
		//global_inventory_->ObtainItem(_location->GetItem(id_));
		wait();
		return;
	}
}

void BloodyKnife_Place(Location * _location, unsigned int id_)
{
}

void TimeBox_Use(Location * _location, unsigned int id_)
{

}

void TimeBox_Take(Location * _location, unsigned int id_)
{

}

void TimeBox_Place(Location * _location, unsigned int id_)
{
}

void PlatinumKey_Use(Location * _location, unsigned int id_)
{
}

void PlatinumKey_Take(Location * _location, unsigned int id_)
{
	if (_location->GetItem(id_) && _location->GetItem(id_)->IsObtained() == false)
	{
		printf("You take the %s and put it in your bag\n", _location->GetItem(id_)->GetItemName());
		_location->GetItem(id_)->SetObtained(true);
		global_inventory_->ObtainItem(_location->GetItem(id_));
		game_flag_handle->SetFlag(19, true);
		if (game_flag_handle->GetFlag(11) == false)
		{
			game_flag_handle->ModifySoul(-7);
		}
		if (game_flag_handle->GetFlag(12) == true)
		{
			game_flag_handle->ModifySoul(13);
		}
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that location\n");
		wait();
		return;
	}
	
}

void PlatinumKey_Place(Location * _location, unsigned int id_)
{
}

void TakGame_EasterEgg_Read(Location* _location, unsigned int id_)
{
	if (_location->GetItem(id_))
	{
		system("@cls||clear");
		printf("You look at the cover of what appears to be an old video game\n");
		printf("The cover appears to have some kind of boy looking really awkwardly upwards\n");
		printf("The eyes on this boy have what appears to be purple facepaint in the form of a mask like thing\n");
		printf("The game cover appears to have a jungle like settings perhaps the game is based on that...");
		wait();
		return;
	}
}

void KingdomGame_EasterEgg_Read(Location* _location, unsigned int id_)
{
	if (_location->GetItem(id_))
	{
		system("@cls||clear");
		printf("You look at the cover of what appears to be an old video game\n");
		printf("The cover appears to have many people sitting on what could possibly be a gargoyle\n");
		printf("In the background there appears to be a large heart shaped moon\n");
		printf("There appears to be a boy holding a large oversized key\n");
		wait();
		return;
	}

}

void DarkCloudGame_EasterEgg_Read(Location* _location, unsigned int id_)
{
	if (_location->GetItem(id_))
	{
		system("@cls||clear");
		printf("You look at the cover of what appears to be an old video game\n");
		printf("Looking it over you see 2 characters on the front one of them is holding a sword and appears to be female\n");
		printf("The other character is holding a wrench and appears to be male");
		printf("In the background what appears to be some sort of flying vessel with what could be arms\n");
		printf("its size on the box gives the illusion of it being far away\n");
		wait();
		return;
	}
}

void TakGame_EasterEgg_Take(Location* _location, unsigned int id_)
{
	if (_location->GetItem(id_) && _location->GetItem(id_)->IsObtained() == false)
	{
		printf("You take the %s and put it in your bag\n", _location->GetItem(id_)->GetItemName());
		_location->GetItem(id_)->SetObtained(true);
		global_inventory_->ObtainItem(_location->GetItem(id_));
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that location\n");
		wait();
		return;
	}
}

void KingdomGame_EasterEgg_Take(Location * _location, unsigned int id_)
{
	if (_location->GetItem(id_) && _location->GetItem(id_)->IsObtained() == false)
	{
		printf("You take the %s and put it in your bag\n", _location->GetItem(id_)->GetItemName());
		_location->GetItem(id_)->SetObtained(true);
		global_inventory_->ObtainItem(_location->GetItem(id_));
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that location\n");
		wait();
		return;
	}
}

void DarkCloudGame_EasterEgg_Take(Location * _location, unsigned int id_)
{
	if (_location->GetItem(id_) && _location->GetItem(id_)->IsObtained() == false)
	{
		printf("You take the %s and put it in your bag\n", _location->GetItem(id_)->GetItemName());
		_location->GetItem(id_)->SetObtained(true);
		global_inventory_->ObtainItem(_location->GetItem(id_));
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that location\n");
		wait();
		return;
	}
}

void HumanHistoryBook_Use(Location * _location, unsigned int id_)
{
}

void HumanHistoryBook_Take(Location * _location, unsigned int id_)
{
	if (_location->GetItem(id_) && _location->GetItem(id_)->IsObtained() == false)
	{
		printf("You take the %s and put it in your bag\n", _location->GetItem(id_)->GetItemName());
		_location->GetItem(id_)->SetObtained(true);
		global_inventory_->ObtainItem(_location->GetItem(id_));
		wait();
		return;
	}
	else
	{
		printf("No such item exists at that location\n");
		wait();
		return;
	}
}

void HumanHistoryBook_Place(Location * _location, unsigned int id_)
{

}

void SpecialFunction_TimeBox()
{
	char input[255];
	if (game_flag_handle->GetFlag(18) == true && game_flag_handle->GetFlag(17) == false)
	{ 
		printf("You look at the box, It lets off a strange light...\n");
		printf("What would you like to do?: ");
		fgets(input, INT_MAX, stdin);
		std::string current_arg(input);
		current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());
		if (current_arg == "restore book")
		{
			printf("You place the Burned Book inside the box, It starts to glow...\n");
			printf("After the glowing subsides you take the book out and it is noticably less charred\n");
			game_flag_handle->SetFlag(17, true); //We now have the Restored Book
			game_flag_handle->ModifySoul(10);
			wait();
			return;
		}
	}
	else
	{
		printf("This just looks like an ordinary box, To be honest there isn't much here about it\n");
		wait();
		return;
	}
}

void SpecialFunction_Sacrifice(Inventory* inventory_, unsigned int id_)
{
	for (uint32_t i = 0; i < inventory_->GetAllItems().size(); ++i)
	{
		if (inventory_->GetAllItems()[i]->GetItemID() == id_)
		{
			if (inventory_->GetAllItems()[i]->IsSacrificed() == false)
			{
				printf("You sacrifce %s to the shrine\n", inventory_->GetAllItems()[i]->GetItemName());
				inventory_->GetAllItems()[i]->SetSacrificed(true);
				switch (inventory_->GetAllItems()[i]->GetItemID())
				{
					case 1: //Burned Book, Restored Book
					{
						if (game_flag_handle->GetFlag(17) == true)
						{
							game_flag_handle->ModifySoul(15);
							game_flag_handle->SetFlag(12, true);
							game_flag_handle->SetFlag(11, true);
						}
						else
						{
							game_flag_handle->ModifySoul(9);
							game_flag_handle->SetFlag(11, true);
						}
						break;
					}
					case 5: //Blooded Knife
					{
						game_flag_handle->SetFlag(13, true);
						game_flag_handle->ModifySoul(-5);
						break;
					}
					case 7: //Tak aGame
					{
						game_flag_handle->SetFlag(14, true);
						game_flag_handle->ModifySoul(1);
						break;
					}
					case 8: //Kingdom Hearts Game
					{
						game_flag_handle->SetFlag(15, true);
						game_flag_handle->ModifySoul(1);
						break;
					}
					case 9: //Dark Chronicle Game
					{
						game_flag_handle->SetFlag(16, true);
						game_flag_handle->ModifySoul(1);
						break;
					}
					case 7000:
					{
						Ending4();
						break;
					}
				}
				wait();
				return;
			}
		}
	}
}

void SpecialFunction_ControlPanel()
{
	char buttonInput[255];
	while (1)
	{
		if (game_flag_handle->GetFlag(6) == true)
		{
			if (game_flag_handle->GetFlag(7) == true)
			{
				if (game_flag_handle->GetFlag(8) == true)
				{
					if (game_flag_handle->GetFlag(9) == true)
					{
						GetRoomGlobal(-1, 4, 0)->SetLocked(false);
						game_flag_handle->SetFlag(3, true);
						printf("You hear what sounds like a lock unlocking itself in the distance\n");
						wait();
					}
				}
			}
		}
		printf("You look down at the control panel it is covered in buttons\n");
		printf("You see a set of 9 buttons that stand out from each other\n");
		printf("Perhaps if you pushed these in a specific order they would do something\n");
		printf("Type back to return to the room\n");
		printf("Buttons: 1, 2, 3, 4, 5, 6, 7, 8, 9\n");
		printf("What button would you like to press?: ");
		fgets(buttonInput, INT_MAX, stdin);
		std::string current_arg(buttonInput);
		current_arg.erase(std::remove(current_arg.begin(), current_arg.end(), '\n'), current_arg.end());
		if (current_arg == "back")
		{
			break;
		}
		if (current_arg == "1")
		{
			if (game_flag_handle->GetFlag(6) == false)
			{
				if (game_flag_handle->GetFlag(7) == false)
				{
					if (game_flag_handle->GetFlag(8) == false)
					{
						if (game_flag_handle->GetFlag(9) == false)
						{
							system("@cls||clear");
							printf("You press the button firmly and it makes a click sound\n");
							game_flag_handle->SetFlag(6, true);
						}
						else
						{
							game_flag_handle->SetFlag(6, false);
							game_flag_handle->SetFlag(7, false);
							game_flag_handle->SetFlag(8, false);
							game_flag_handle->SetFlag(9, false);
						}
					}
					else
					{
						game_flag_handle->SetFlag(6, false);
						game_flag_handle->SetFlag(7, false);
						game_flag_handle->SetFlag(8, false);
						game_flag_handle->SetFlag(9, false);
					}
				}
				else
				{
					game_flag_handle->SetFlag(6, false);
					game_flag_handle->SetFlag(7, false);
					game_flag_handle->SetFlag(8, false);
					game_flag_handle->SetFlag(9, false);
				}
			}
			else
			{
				game_flag_handle->SetFlag(6, false);
				game_flag_handle->SetFlag(7, false);
				game_flag_handle->SetFlag(8, false);
				game_flag_handle->SetFlag(9, false);
			}
			
		}
		if (current_arg == "2" || current_arg == "3" || current_arg == "4" || current_arg == "5" || current_arg == "7" || current_arg == "8")
		{
			system("@cls||clear");
			printf("You press the button firmly and it makes a sound\n");
			game_flag_handle->SetFlag(6, false);
			game_flag_handle->SetFlag(7, false);
			game_flag_handle->SetFlag(8, false);
			game_flag_handle->SetFlag(9, false);
		}
		if (current_arg == "6")
		{
			if (game_flag_handle->GetFlag(6) == true)
			{
				if (game_flag_handle->GetFlag(7) == true)
				{
					if (game_flag_handle->GetFlag(8) == true)
					{
						if (game_flag_handle->GetFlag(9) == false)
						{
							system("@cls||clear");
							printf("You press the button firmly and it makes a click sound\n");
							game_flag_handle->SetFlag(9, true);
						}
						else
						{
							game_flag_handle->SetFlag(6, false);
							game_flag_handle->SetFlag(7, false);
							game_flag_handle->SetFlag(8, false);
							game_flag_handle->SetFlag(9, false);
						}
					}
					else
					{
						game_flag_handle->SetFlag(6, false);
						game_flag_handle->SetFlag(7, false);
						game_flag_handle->SetFlag(8, false);
						game_flag_handle->SetFlag(9, false);
					}
				}
				else
				{
					game_flag_handle->SetFlag(6, false);
					game_flag_handle->SetFlag(7, false);
					game_flag_handle->SetFlag(8, false);
					game_flag_handle->SetFlag(9, false);
				}
			}
			else
			{
				game_flag_handle->SetFlag(6, false);
				game_flag_handle->SetFlag(7, false);
				game_flag_handle->SetFlag(8, false);
				game_flag_handle->SetFlag(9, false);
			}
		}
		if (current_arg == "9")
		{
			if (game_flag_handle->GetFlag(6) == true) //1
			{
				if (game_flag_handle->GetFlag(7) == false) //9 Part 1
				{
					system("@cls||clear");
					printf("You press the button firmly and it makes a click sound\n");
					game_flag_handle->SetFlag(7, true); //Set it to true

				}
				else if (game_flag_handle->GetFlag(8) == false)
				{
					system("@cls||clear");
					printf("You press the button firmly and it makes a click sound\n");
					game_flag_handle->SetFlag(8, true);
				}
				else
				{
					game_flag_handle->SetFlag(6, false);
					game_flag_handle->SetFlag(7, false);
					game_flag_handle->SetFlag(8, false);
					game_flag_handle->SetFlag(9, false);
				}
			}
			else
			{
				game_flag_handle->SetFlag(6, false);
				game_flag_handle->SetFlag(7, false);
				game_flag_handle->SetFlag(8, false);
				game_flag_handle->SetFlag(9, false);
			}
		}

	}
	return;


}

void FinalStats()
{
	printf("Your Items\n");
	printf("-------------------\n");
	for (unsigned int i = 0; i < global_inventory_->GetAllItems().size(); ++i)
	{
		if (global_inventory_->GetAllItems()[i]->IsSacrificed())
		{
			printf("%s [sacrificed]\n", global_inventory_->GetAllItems()[i]->GetItemName());
		}
		else
		{
			printf("%s\n", global_inventory_->GetAllItems()[i]->GetItemName());
		}
	}
	printf("-------------------\n");
	printf("\n\nYou had a soul level of %i", game_flag_handle->GetSoul());
}

void SpecialFunction_PlatinumDoor()
{
	system("@cls||clear");
	//TODO Ending Code
	//Your Soul Level is Irrelevant if you haven't completed all the required objectives to get higher than Ending 5
	if (game_flag_handle->GetFlag(19) == false)
	{
		//Don't even have the Platinum Key how shameful
		Ending1();
		wait();
	}
	else if (game_flag_handle->GetFlag(19) == true && game_flag_handle->GetFlag(3) == false)
	{
		//Never did the Lab Combo Lock
		Ending2();
		wait();
	}
	else if (game_flag_handle->GetFlag(19) == true && game_flag_handle->GetFlag(3) == true && game_flag_handle->GetFlag(1) == true)
	{
		Ending5();
		wait();
	}
	else if (game_flag_handle->GetFlag(19) == true && game_flag_handle->GetFlag(3) == true && game_flag_handle->GetFlag(11) == false)
	{
		Ending3();
		wait();
	}
	else if (game_flag_handle->GetFlag(19) == true && game_flag_handle->GetFlag(3) == true && game_flag_handle->GetFlag(11) == true)
	{
		Ending4();
		wait();
	}
	else if (game_flag_handle->GetSoul() <= 125)
	{
		Ending6();
		wait();
	}
	else if (game_flag_handle->GetSoul() <= 135)
	{
		Ending7();
		wait();
	}
	else if (game_flag_handle->GetSoul() <= 150)
	{
		Ending8();
		wait();
	}
	else if (game_flag_handle->GetSoul() > 150)
	{
		Ending9();
		wait();
	}
	system("@cls||clear");
	FinalStats();
	printf("\n\n\n--------------------");
	printf("\n...To be Continued...\n");
	GameEnd();
}