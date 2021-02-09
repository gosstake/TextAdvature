// PLAYER_H
#ifndef PLAYER_H // include guard
#define PLAYER_H

#include <iostream>
#include "Weapon.h"
#include "Treasure.h"
#include <string>
#include <vector>



using namespace std;


class Monster;

enum magicWords {
	noWord,
	Bombarda,
	Bombarda_Maxima,
	Diffindo,

	healingWords,
	Brackium_Emendo,
	
	LastWord
};

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
	void victory(int xp, int gold);
	bool gameover();
	void displayHitPoints();
	bool Mana(Monster& _monster ,magicWords _nmagic );
 	magicWords getMagicWords(int _selection);	
	void displayMagicWords();
	void displayHealingWords();
	void getCollactables(std::vector<Treasure> _Treasures);
	void switchWeapon();
	void setArmor(int armor);
	int getGold();
	void setGold(int gold);
	void save(int _playerXpos, int _playerYpos);
	void load(int& _playerXpos,int& _playerYpos);
 
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
	std::vector<Weapon> weapons;
	int WIndex;
	magicWords Nmagic;
	std::vector<magicWords> Nmagics;
	int mgold;

};


#endif // PLAYER_H

