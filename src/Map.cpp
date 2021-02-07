#include "Map.h"
#include <iostream>

Map::Map()
{
	mPlayerXPos = 0;
	mPlayerYPos = 0;

}

int Map::getPlayerXPos() 
{
	return mPlayerXPos;
}

int Map::getPlayerYPos()
{
	return mPlayerYPos;
}

void Map::setPlayerXPos(int x) 
{
	mPlayerXPos=x;
}

void Map::setPlayerYPos(int y) 
{
	mPlayerYPos=y;
}

void Map::movePlayer()
{
	int selection = 1;
	std::cout << "1) North, 2) East, 3) South, 4) West: ";
	std::cin >> selection;
	switch (selection)
	{
	case 1: // North
		mPlayerYPos++;
		break;
	case 2: // East
		mPlayerXPos++;
		break;
	case 3: // South
		mPlayerYPos--;
		break;
	default: // West
		mPlayerXPos--;
		break;
	}
	std::cout << std::endl;
}

Monster* Map::checkRandomEncounter()
{
	int roll = Random(0, 20);
	Monster* monster = 0;
		if (roll <= 5)
		{
			return 0;
		}
		else if (roll >= 6 && roll <= 9)
		{
			monster = new Monster("Demon", 4, 2, 50, 0, "Knife", 2, 4);
			std::cout << "You encountered a Demon!" << std::endl;
			std::cout << "Prepare for battle!" << std::endl;
			std::cout << std::endl;

		}
		else if (roll >= 10 && roll <= 13)
		{
			monster = new Monster("Orc", 10, 8, 200, 1, "Short Sword", 2, 7);
			std::cout << "You encountered an Orc!" << std::endl;
			std::cout << "Prepare for battle!" << std::endl;
			std::cout << std::endl;
		}
		else if (roll >= 14 && roll <= 17)
		{
			monster = new Monster("Goblin", 6, 6, 100, 0, "Dagger", 1, 5);
			std::cout << "You encountered a Goblin!" << std::endl;
			std::cout << "Prepare for battle!" << std::endl;
			std::cout << std::endl;
		}
		else if (roll >= 18 && roll <= 19)
		{
			monster = new Monster("Ogre", 20, 12, 500, 2, "Club", 3, 8);
			std::cout << "You encountered an Ogre!" << std::endl;
			std::cout << "Prepare for battle!" << std::endl;
			std::cout << std::endl;
		}
		else if (roll == 20)
		{
			monster = new Monster("Orc Lord", 25, 15, 2000, 5, "Two Handed Sword", 5, 20);
			std::cout << "You encountered an Orc Lord!!!" << std::endl;
			std::cout << "Prepare for battle!" << std::endl;
			std::cout << std::endl;
		}
	return monster;
}

void Map::printPlayerPos()
{
	std::cout << "Player Position = (" << mPlayerXPos << ", " << mPlayerYPos << ")" << std::endl << std::endl;
}
