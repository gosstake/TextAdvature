#pragma once

#include <iostream>
#include "Weapon.h"
#include <string>
#include "Map.h"

class Monster;

class Player
{
public:
	Player();
	bool isDead();
	std::string getName();
	int getArmor();
	void takeDamage(int damage);
	void createClass();
	bool attack(Monster& monster);
	void setWeapon(int LowDamage, int HighDamage, std::string Name);
	void levelUp();
	void rest();
	void heal();
	void viewStats();
	void victory(int xp);
	void gameover();
	void displayHitPoints();
	void setArmor(int armor);
	int getGold();
	void setGold(int gold);
	void save(Map& gameMap);
	void load(Map& gameMap);
  
private:
	std::string mName;
	std::string mClassName;
	int mAccuracy;
	int mHitPoints;
	int mMaxHitPoints;
	int mExpPoints;
	int mNextLevelExp;
	int mLevel;
	int mArmor;
	Weapon mWeapon;
	int mgold;

};

