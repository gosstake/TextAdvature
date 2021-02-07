#include "Player.h"
#include "Monster.h"
#include <string>
#include <iostream>



Player::Player()
{
	mName = "Default";
	mClassName = "Default";
	mAccuracy = 0;
	mHitPoints = 0;
	mMaxHitPoints = 0;
	mExpPoints = 0;
	mNextLevelExp = 0;
	mLevel = 0;
	mArmor = 0;
	mWeapon.mName = "Default Weapon Name";
	mWeapon.mRange.mLowDamage = 0;
	mWeapon.mRange.mHighDamage = 0;
	mgold = 0;
}


std::string Player::getName()
{
	return mName;
}

bool Player::isDead()
{
	return mHitPoints <= 0;
}

int Player::getArmor()
{
	return mArmor;
}

void Player::displayHitPoints()
{
	std::cout << mName << "'s hitpoints: " << mHitPoints << std::endl;
}

void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}

int Player::getGold()
{
	return mgold;
}

 void Player::setGold(int gold)
{
	 mgold= gold;
}

void Player::levelUp()
{
	if (mExpPoints >= mNextLevelExp)
	{
		std::cout << "You gained a level!" << std::endl;
		mLevel++;
		mNextLevelExp = mLevel * mLevel * 1000;
		mAccuracy += Random(1, 3);
		mMaxHitPoints += Random(2, 6);
		mArmor += Random(1, 2);
		mLevel = mMaxHitPoints;
	}
}

void Player::rest()
{
	std::cout << "resting....." << std::endl;
	mHitPoints = mMaxHitPoints;
}

void Player::viewStats()
{
	std::cout << "PLAYER STATS" << std::endl;
	std::cout << "============" << std::endl;
	std::cout << std::endl;
	std::cout << "Name = " << mName << std::endl;
	std::cout << "Class = " << mClassName << std::endl;
	std::cout << "Accuracy = " << mAccuracy << std::endl;
	std::cout << "Hitpoints = " << mHitPoints << std::endl;
	std::cout << "MaxHitpoints = " << mMaxHitPoints << std::endl;
	std::cout << "XP = " << mExpPoints << std::endl;
	std::cout << "XP for Next Lvl = " << mNextLevelExp << std::endl;
	std::cout << "Level = " << mLevel << std::endl;
	std::cout << "Armor = " << mArmor << std::endl;
	std::cout << "Weapon Name = " << mWeapon.mName << std::endl;
	std::cout << "Weapon Damage = " << mWeapon.mRange.mLowDamage << "-" << mWeapon.mRange.mHighDamage << std::endl;
	std::cout << "Gold = " << mgold << std::endl;
	std::cout << std::endl;
	std::cout << "END PLAYER STATS" << std::endl;
	std::cout << "================" << std::endl;
	std::cout << std::endl;
}


void Player::victory(int xp)
{
	std::cout << "You won the battle!" << std::endl;
	std::cout << "You win " << xp << " experience points!" << std::endl << std::endl;
	mExpPoints += xp;
}

void Player::gameover()
{
	std::cout << "You died in battle..." << std::endl;
	std::cout << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "GAME OVER!" << std::endl;
	std::cout << "================================" << std::endl;
        std::cout << "Press 'n' to new start or press 'q' to quit ";
	char select;
        std::cin >> select;
	
	if (select == 'n')
	{
	    createClass();	
	}
	
	else if (select=='q')
	{
		std::cout << std::endl;
	}
}

bool Player::attack(Monster& monster)
{
	int selection = 1;
	std::cout << "1) Attack, 2) Run: ";
	std::cin >> selection;
	std::cout << std::endl;
	switch (selection)
	{
	case 1:
		std::cout << "You attack an " << monster.getName() << " with a " << mWeapon.mName << std::endl;
		if (Random(0, 20) < mAccuracy)
		{
			int damage = Random(mWeapon.mRange);
			int totalDamage = damage - monster.getArmor();
			if (totalDamage <= 0)
			{
				std::cout << "Your attack failed to penetrate " << "the armor." << std::endl;
			}
			else
			{
				std::cout << "You attack for " << totalDamage << " damage!" << std::endl;
				monster.takeDamage(totalDamage);
			}
		}
		else
		{
			std::cout << "You miss!" << std::endl;
		}
		std::cout << std::endl;
		break;
	case 2:
		int roll = Random(1, 4);
		if (roll == 1)
		{
			std::cout << "You run away!" << std::endl;
			return true;
		}
		else
		{
			std::cout << "You could not escape!" << std::endl;
			break;
		}
	}
	return false;
}



void Player::createClass()
{
	std::cout << "CHARACTER CLASS GENERATION" << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "Enter your character's name: ";
	getline(std::cin, mName);
	std::cout << "Please select a character class number..." << std::endl;
	std::cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";
	int characterNum = 1;
	std::cin >> characterNum;
	switch (characterNum)
	{
	case 1: // Fighter
		mClassName = "Fighter";
		mAccuracy = 10;
		mHitPoints = 20;
		mMaxHitPoints = 20;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 4;
		mWeapon.mName = "Long Sword";
		mWeapon.mRange.mLowDamage = 1;
		mWeapon.mRange.mHighDamage = 8;
		break;
	case 2: // Wizard
		mClassName = "Wizard";
		mAccuracy = 5;
		mHitPoints = 10;
			mMaxHitPoints = 10;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 1;
		mWeapon.mName = "Staff";
		mWeapon.mRange.mLowDamage = 1;
		mWeapon.mRange.mHighDamage = 4;
		break;
	case 3: // Cleric
		mClassName = "Cleric";
		mAccuracy = 8;
		mHitPoints = 15;
		mMaxHitPoints = 15;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 3;
		mWeapon.mName = "Flail";
		mWeapon.mRange.mLowDamage = 1;
		mWeapon.mRange.mHighDamage = 6;
		break;
	default: // Thief
		mClassName = "Thief";
		mAccuracy = 7;
		mHitPoints = 12;
		mMaxHitPoints = 12;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 2;
		mWeapon.mName = "Short Sword";
		mWeapon.mRange.mLowDamage = 1;
		mWeapon.mRange.mHighDamage = 6;
		break;
	}
}
