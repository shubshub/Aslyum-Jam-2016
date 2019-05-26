#include "game_flags.h"

GameFlags *game_flag_handle = new GameFlags();

void GameFlags::SetFlag(unsigned int flag, bool tf)
{
	switch (flag)
	{
	case 0:
		awakening_book_ = tf;
		break;
	case 1:
		burned_diary_destroyed = tf;
		break;
	case 2:
		final_door_unlock_ = tf;
		break;
	case 3:
		laboratory_code_unlock_ = tf;
		break;
	case 4:
		lost_maze_unlock_ = tf;
		break;
	case 5:
		cold_storage_key_ = tf;
		break;
	case 6:
		button_1 = tf;
		break;
	case 7:
		button_9 = tf;
		break;
	case 8:
		button_9_2 = tf;
		break;
	case 9:
		button_6 = tf;
		break;
	case 10:
		bloody_knife_destroyed = tf;
		break;
	case 11:
		sacrificed_burned_book = tf;
		break;
	case 12:
		sacrificed_restored_book = tf;
		break;
	case 13:
		sacrificed_bloody_knife = tf;
		break;
	case 14:
		sacrificed_easteregg1 = tf;
		break;
	case 15:
		sacrificed_easteregg2 = tf;
		break;
	case 16:
		sacrificed_easteregg3 = tf;
		break;
	case 17:
		has_restored_book = tf;
		break;
	case 18:
		has_burned_book = tf;
		break;
	case 19:
		has_platinum_key = tf;
		break;
	}
}

bool GameFlags::GetFlag(unsigned int flag)
{
	switch (flag)
	{
	case 0:
		return awakening_book_;
		break;
	case 1:
		return burned_diary_destroyed;
		break;
	case 2:
		return final_door_unlock_;
		break;
	case 3:
		return laboratory_code_unlock_;
		break;
	case 4:
		return lost_maze_unlock_;
		break;
	case 5:
		return cold_storage_key_;
		break;
	case 6:
		return button_1;
		break;
	case 7:
		return button_9;
		break;
	case 8:
		return button_9_2;
		break;
	case 9:
		return button_6;
		break;
	case 10:
		return bloody_knife_destroyed;
		break;
	case 11:
		return sacrificed_burned_book;
		break;
	case 12:
		return sacrificed_restored_book;
		break;
	case 13:
		return sacrificed_bloody_knife;
		break;
	case 14:
		return sacrificed_easteregg1;
		break;
	case 15:
		return sacrificed_easteregg2;
		break;
	case 16:
		return sacrificed_easteregg3;
		break;
	case 17:
		return has_restored_book;
		break;
	case 18:
		return has_burned_book;
		break;
	case 19:
		return has_platinum_key;
		break;
	default:
		return false;
	}
}