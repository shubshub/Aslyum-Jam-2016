#pragma once
class GameFlags
{
private:
	int soul_level_ = 100;
	bool awakening_book_ = false;
	bool has_burned_book = false;
	bool burned_diary_destroyed = false;
	bool final_door_unlock_ = false;
	bool laboratory_code_unlock_ = false; //Button1 Button9 Button9 Button6
	bool lost_maze_unlock_ = false;
	bool cold_storage_key_ = false;
	bool bloody_knife_destroyed = false;
	bool has_restored_book = false;
	bool has_platinum_key = false;

	//Sacrificial Flags
	bool sacrificed_burned_book = false;
	bool sacrificed_restored_book = false;
	bool sacrificed_bloody_knife = false;
	bool sacrificed_easteregg1 = false;
	bool sacrificed_easteregg2 = false;
	bool sacrificed_easteregg3 = false;

	//Laboratory Key Press
	bool button_1 = false;
	bool button_9 = false;
	bool button_9_2 = false;
	bool button_6 = false;

public:
	GameFlags()
	{
		soul_level_ = 100;
		awakening_book_ = false;
		has_burned_book = false;
		burned_diary_destroyed = false;
		final_door_unlock_ = false;
		laboratory_code_unlock_ = false; //Button1 Button9 Button9 Button6
		lost_maze_unlock_ = false;
		cold_storage_key_ = false;
		bloody_knife_destroyed = false;
		has_restored_book = false;
		has_platinum_key = false;

		//Sacrificial Flags
		sacrificed_burned_book = false;
		sacrificed_restored_book = false;
		sacrificed_bloody_knife = false;
		sacrificed_easteregg1 = false;
		sacrificed_easteregg2 = false;
		sacrificed_easteregg3 = false;

		//Laboratory Key Press
		button_1 = false;
		button_9 = false;
		button_9_2 = false;
		button_6 = false;
	}

	void SetFlag(unsigned int flag, bool tf);

	bool GetFlag(unsigned int flag);

	void ModifySoul(int incdec)
	{
		soul_level_ += incdec;
	}

	int GetSoul()
	{
		return soul_level_;
	}

};

extern GameFlags *game_flag_handle;