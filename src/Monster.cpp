#include "Monster.h"
#include "Player.h"
#include <iostream>

using namespace std;

Monster::Monster(const std::string& name, int hp, int acc,
	int xpReward, int armor, const std::string& weaponName,
	int lowDamage, int highDamage, int gold)
{
	mName = name;
	mHitPoints = hp;
	mAccuracy = acc;
	mExpReward = xpReward;
	mArmor = armor;
	mWeapon.mName = weaponName;
	mWeapon.mRange.mLowDamage = lowDamage;
	mWeapon.mRange.mHighDamage = highDamage;
	mGold= gold;
	
}

bool Monster::isDead() 
{
	return mHitPoints <= 0;
}

int Monster::getXPReward()
{
	return mExpReward;
}

int Monster::getGold()
{
	return mGold;
}

std::string Monster::getName()
{
	return mName;
}

int Monster::getArmor()
{
	return mArmor;
}

void Monster::takeDamage(int Damage)
{
	mHitPoints -= Damage;
}

void Monster::displayHitPoints()
{
	std::cout << mName << "'s hitpoints: " << mHitPoints << std::endl;
}


void Monster::attack(Player& player)
{
	std::cout << "A " << mName << " attacks you " << "with a " << mWeapon.mName << std::endl;
	if (Random(0, 20) < mAccuracy)
	{
		int damage = Random(mWeapon.mRange);
		int totalDamage = damage - player.getArmor();
		if (totalDamage <= 0)
		{
			std::cout << "The monster's attack failed to " << "penetrate your armor." << std::endl;
			player.setGold(totalDamage);
		}
		else
		{
			std::cout << "You are hit for " << totalDamage << " damage!" << std::endl;
			player.takeDamage(totalDamage);
		}
	}
	else
	{
		std::cout << "The " << mName << " missed!" << std::endl;
	}
	std::cout << std::endl;

}
