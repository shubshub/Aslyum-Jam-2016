#pragma once
#include "location.h"
#include "game_flags.h"
#include "item.h"
#include "inventory.h"
//Game Functions
void North();

void South();

void East();

void West();

void zUp();

void zBack();

void PlayGame();

void AwakeningBook_Use(Location* _location, unsigned int id_);
void AwakeningBook_Take(Location* _location, unsigned int id_);

void BurnedBook_Use(Location* _location, unsigned int id_);
void BurnedBook_Take(Location* _location, unsigned int id_);
void BurnedBook_Destroy();
void BurnedBook_Place(Location* _location, unsigned int id_); //Place Burned Book in the Shrine

void DiamondKey_Use(Location* _location, unsigned int id_);
void DiamondKey_Take(Location* _location, unsigned int id_);
void DiamondKey_Place(Location* _location, unsigned int id_); //Place Diamond Key in Bedroom Lock

void BedsideLamp_Use(Location* _location, unsigned int id_);
void BedsideLamp_Take(Location* _location, unsigned int id_);
void BedsideLamp_Place(Location* _location, unsigned int id_); //Switch Lamp on/off

void WarDiary_Use(Location* _location, unsigned int id_);
void WarDiary_Take(Location* _location, unsigned int id_);
void WarDiary_Place(Location* _location, unsigned int id_); //Sacrifice the War Dairy to the Shrine

void BloodyKnife_Use(Location* _location, unsigned int id_);
void BloodyKnife_Take(Location* _location, unsigned int id_);
void BloodyKnife_Place(Location* _location, unsigned int id_); //Sacrifice the Bloody Knife to the Shrine
void BloodyKnife_Destroy();

void TimeBox_Use(Location* _location, unsigned int id_);
void TimeBox_Take(Location* _location, unsigned int id_);
void TimeBox_Place(Location* _location, unsigned int id_);

void PlatinumKey_Use(Location* _location, unsigned int id_);
void PlatinumKey_Take(Location* _location, unsigned int id_);
void PlatinumKey_Place(Location* _location, unsigned int id_); //Place the Platinum Key in the Final Door

void TakGame_EasterEgg_Read(Location* _location, unsigned int id_);
void KingdomGame_EasterEgg_Read(Location* _location, unsigned int id_);
void DarkCloudGame_EasterEgg_Read(Location* _location, unsigned int id_);

void TakGame_EasterEgg_Take(Location* _location, unsigned int id_);
void KingdomGame_EasterEgg_Take(Location* _location, unsigned int id_);
void DarkCloudGame_EasterEgg_Take(Location* _location, unsigned int id_);

void HumanHistoryBook_Use(Location* _location, unsigned int id_);
void HumanHistoryBook_Take(Location* _location, unsigned int id_);
void HumanHistoryBook_Place(Location* _location, unsigned int id_);

void SpecialFunction_ControlPanel();
void SpecialFunction_TimeBox();
void SpecialFunction_Sacrifice(Inventory* inventory_, unsigned int id_);

void FinalStats();
void SpecialFunction_PlatinumDoor();

char* GetItemName(unsigned int id_);
//void BookFirstRoomUse(Location* _location, unsigned int id_);
//void BookFirstRoomTake(Location* _location, unsigned int id_);