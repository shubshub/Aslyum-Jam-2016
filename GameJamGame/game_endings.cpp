#include "game_endings.h"
#include "inventory.h"
#include "game_flags.h"
#include <windows.h>
#include <iostream>
void Ending1()
{
	//By far the worst ending
	printf("You attempt to forcefully open the door made of solid platinum\n");
	printf("You somehow manage to open the door...\n");
	printf("A strange dark entity greets you on the other side...\n");
	printf("It speaks in a eerie voice\n");
	printf("------------------------------------\n");
	printf("...See I told you I'd find you.... And I said I was going to kill you....\n");
	printf("But thats too eassssyyy... I think you'll make a nice playtoy... You can join my other friends...\n");
	printf("*eerie laughter is emitted from the strange entities mouth*\n");
	printf("------------------------------------\n");

	printf("\n\nYou have been captured...\n");
	printf("Ending 1/13\n");

}

void Ending2()
{
	printf("You attempt to open the door made of solid platinum by inserting the key into the lock\n");
	printf("You hear the lock click... and then the platinum key breaks in half\n");
	printf("The world around you begins to melt away...\n");
	printf("Every atom of your body feels like its exploding a million times over\n");
	printf("Blood starts to seep from every possible opening in your body\n");
	printf("...You have Died...\n");
	printf("Ending 2/13\n");
}

void Ending3()
{
	printf("You attempt to open the door made of solid platinum by inserting the key into the lock\n");
	printf("You hear the lock click and the door starts to open\n");
	printf("You enter the strange room...\n");
	printf("You see a portal before you and a voice speaks 'Step into the Light...\n");
	printf(" if you are worthy then you'll be granted passage to the new world'\n");
	if (game_flag_handle->GetSoul() >= 80)
	{
		printf("As you step into the light you are blinded by its brightness\n");
		printf("You awaken in what appears to be an infinitely large white room...\n");
		printf("You hear a voice, Welcome... I am god... You have done well to make it here\n");
		printf("It appears my angels are satisfied with your actions in the mortal realm\n");
		printf("You have been granted access to heaven... Step through the door and enjoy your new home\n");
		printf("\n\nEnding 3/13\n");
		return;
	}
	if (game_flag_handle->GetSoul() >= 50)
	{
		printf("As you step into the light you are blinded by its brightness\n");
		printf("You awaken in what appears to be an infinitely large white room...\n");
		printf("You hear a voice, Welcome... I am god... You have done well to make it here\n");
		printf("You are not worthy enough to be granted passage to the heavens...\n");
		printf("You shall be forced to walk forever among the forgotten souls, The Limbo Lands it be called\n");
		printf("You yourself will eventually forget everything and become a forgotten soul yourself\n");
		printf("\n\nEnding 4/13\n");
		return;
	}
	if (game_flag_handle->GetSoul() < 50)
	{
		printf("As you step into the light it turns a dark red color...\n");
		printf("You hear a scream... as a figure appears before you\n");
		printf("'You are unworthy to step into this light... for this I must punish you...'\n");
		printf("The unknown figure charges towards you piercing your chest with a devastating punch\n");
		printf("Every atom of your body instantanously explodes 500 times over while keeping you alive so that you can feel the pain\n");
		printf("...After what seems like forever you fall limp to the floor\n");
		printf(" - You have died - ");
		printf("\n\nEnding 5/13");
		return;
	}
}

void Ending4()
{
	printf("You look to the shrine that stands before you...\n");
	printf("You hear a voice beckon 'take this knife and turn it on yourself and descend to depths!' as a knife appears before you\n");
	printf("you take the knife in your hand... turning it towards your chest\n");
	printf("You sink the knife deep into your chest as you start to bleed out\n");
	printf("You collapse to the floor... A figure appears over you...\n");
	printf("'You have done well my friend... You shall never return to the mortal realm...'\n");
	printf("'I have a special place for you.... down in hell...'\n");
	printf("\n\n - You have died -\n\n");
	printf("Ending 6/13\n");
	return;
}

void wait()
{
	std::cout << "Press ENTER to continue....." << std::endl;
	std::cin.ignore(1);
}

void Ending5()
{
	printf("You attempt to open the door made of platinum by inserting the key into its lock\n");
	printf("The door opens with ease and you step inside\n");
	printf("There are two portals here... On the other side of either there are different things\n");
	printf("A Voice speaks to you 'Step into one... And Recieve your Reward... Only the purest of heart will choose correctly...'\n");
	printf("\n\nThe left hand portal contains the mortal realm, You may return... Back to your life... What it was before you came here\n");
	printf("\n\nOn the other hand to the right is a portal that contains anything you've ever wanted...\n");
	printf("Riches... Games... World Domination... Whatever it is you want.... ITS UP TO YOU...");
	//Depends on your Soul Level
	if (game_flag_handle->GetSoul() >= 75)
	{
		printf("Your pure soul allows you to decide... You step into the left most portal\n");
		printf("A blinding light fills the room... and then... you black out\n");
		wait();
		system("@cls||clear");
		printf("\n\nYou awaken in your bedroom... Everything seems to be back the way it was before\n");
		printf("Was it all a dream?.... I can't really remember...\n");
		printf("...You'll never know...\n");
		printf("\n\nEnding 7/13\n");
		return;
	}
	if (game_flag_handle->GetSoul() >= 50 && game_flag_handle->GetSoul() < 75)
	{
		printf("You attempt to make your mind up... Its genuinely a tough decision\n");
		Sleep(1000);
		printf("The 2 Portals start to shrink in size...\n");
		Sleep(1000);
		printf("You make a mad dash for the right hand side portal...\n");
		Sleep(1000);
		printf("Its too late... both portals fade into nothingness...\n");
		printf("A voice speaks to you... 'You have taken too long... Your soul is unworthy...'\n");
		printf("'For your impureness... you shall be forced to walk this land... never asleep... never awake... never dead...'\n");
		printf("...Welcome to your new home... You are the forgotten ones... who they can never remember except they will always remember...\n");
		printf("\n\nEnding 8/13\n");
		return;
	}

	if (game_flag_handle->GetSoul() < 50)
	{
		printf("Your mind is made up easily... Tempted too much by the riches and other rewards in the right hand portal\n");
		printf("You walk towards it... stepping inside... you appear in a room with all that you could desire sitting there for the taking\n");
		printf("As you step forward to claim your final reward... a voice speak to you\n");
		printf("'I am disappointed... I thought you would be more pure... All you wanted was to be rich... No care for anyone else...'\n");
		printf("'For this you shall be punished... Forced to walk the earth as a forgotten soul... nobody can see you... nobody can hear you...'\n");
		printf("'You can never interact with anything or anyone... however you have what your heart desires... but you may never use it...'\n");
		printf("'I hope you're happy... you caused this...'\n");
		printf("\n\nEnding 9/13\n");
		return;
	}
}

//These Endings are Given based on your Soul level
void Ending6()
{
	printf("You open the door using the platinum key... and you step inside\n");
	printf("A figure stands before you and speaks to you\n");
	printf("'Well done... You have done well... I have been watching you'\n");
	printf("'...Your reward for getting here... is peace... You will be returned to your own realm... Enjoy it... We almost killed you'\n");
	printf("\n\nEnding 10/13\n");
	return;
}

void Ending7()
{
	printf("You open the door using the platinum key... and you step inside\n");
	printf("A figure stands before you and speaks to you\n");
	printf("'Come forward... We have found your soul to be pure of heart... Your reward shall be great'\n");
	printf("'You will be granted passage to the immortal realm to be among the gods... You can have whatever your heart desires'\n");
	printf("\n\nEnding 11/13\n");
	return;
}

void Ending8()
{
	printf("You open the door using the platinum key... and you step inside\n");
	printf("A figure stands before you and speaks to you\n");
	printf("'...You are worthy to be called a god... A being of legend... although very real indeed... Step into the light and fufill your destiny'\n");
	printf("- You have ascended to God Status -\n");
	printf("\n\nEnding 12/13\n");
	return;
}

void Ending9()
{
	printf("You open the door using the platinum key... and you step inside\n");
	printf("Suddenly you black out and awaken in a room... is this your bedroom?...\n");
	printf("...It appears this was all just a dream... you can go back to sleep now\n");
	printf("\n\nEnding 13/13\n");
	return;
}

void GameEnd()
{
	wait();
	system("@cls||clear");
	printf("Thanks for playing Escape Sleepy Time...\n");
	printf("You should go back and try to get every possible ending in the game!\n");
	printf("Please leave a rating if you enjoyed the game\n");
	printf("Leave feedback also\n");
	printf("I might try and add extra content if people like what I've produced\n");
	printf("\n\nHit enter to end the game\n\n");
	wait();
	exit(0);
}