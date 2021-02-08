#include "Player.h"
#include "Monster.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Map.h"

using namespace std;

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
	Nmagic =  noWord;
	Nmagics.clear();
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

void Player::setWeapon(int LowDamage, int HighDamage, std::string Name)
{
	mWeapon.mRange.mLowDamage=LowDamage;
	mWeapon.mRange.mHighDamage=HighDamage;
	mWeapon.mName=Name;
}

void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}
 
 int Player::getGold()
{
	return mgold;
}
void Player::setArmor(int armor)
{
	mArmor += armor;
}

int Player::getGold()
{
	return mgold;
}

 void Player::setGold(int gold)
{
	 mgold += gold;
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

void Player::heal()
{
	std::cout << "healing....." << std::endl;
	mHitPoints = mMaxHitPoints;
}

void Player::viewStats()
{
	std::cout << "PLAYER STATS" << std::endl;
	std::cout << "============" << std::endl;
	std::cout << std::endl;
	std::cout << "Name = " << mName << std::endl;
	std::cout << "Class = " << mClassName << std::endl;
  std::cout << "Gold = " << mgold << std::endl;
	std::cout << "Accuracy = " << mAccuracy << std::endl;
	std::cout << "Hitpoints = " << mHitPoints << std::endl;
	std::cout << "MaxHitpoints = " << mMaxHitPoints << std::endl;
	std::cout << "XP = " << mExpPoints << std::endl;
	std::cout << "XP for Next Lvl = " << mNextLevelExp << std::endl;
	std::cout << "Level = " << mLevel << std::endl;
	std::cout << "Armor = " << mArmor << std::endl;
	std::cout << "Weapon Name = " << mWeapon.mName << std::endl;
	std::cout << "Weapon Damage = " << mWeapon.mRange.mLowDamage << "-" << mWeapon.mRange.mHighDamage << std::endl;
	std::cout << "List of Magic Words : " << std::endl;
	if (Nmagics.empty()) {
		std::cout << "Player has no Magic Words..." << std::endl;
	} else {
		for (unsigned int i = 0 ; i < Nmagics.size(); i++ ) {
			if (Nmagics[i] == Bombarda) {
				std::cout << i + 1 << ": " << "Explosion"<< std::endl;
			}else if(Nmagics[i] == Bombarda_Maxima) {
				std::cout << i + 1<< ": " << "GroSe Explosion"<< std::endl;
			} else if(Nmagics[i] == Diffindo){
				std::cout << i + 1<< ": " << "ZerreiSt oder durchtrennt Gegenstaende"<< std::endl;
			} else if (Nmagics[i] == Brackium_Emendo) {
				std::cout << i + 1 << ": " << "Heilt gebrochene Knochen"<< std::endl;
			}	 
		}
	}
	std::cout << std::endl;
	std::cout << "END PLAYER STATS" << std::endl;
	std::cout << "================" << std::endl;
	std::cout << std::endl;
}

void Player::save(Map& gameMap)
{
	int x;
	int y;
	x= gameMap.getPlayerXPos();
	y= gameMap.getPlayerYPos();

	std::ofstream Ausgabe;
	Ausgabe.open("savedGame.txt");
if(Ausgabe)
{
	Ausgabe <<mClassName<<std::endl;
	Ausgabe <<mAccuracy<<std::endl;
	Ausgabe <<mHitPoints<<std::endl;
	Ausgabe <<mMaxHitPoints<<std::endl;
	Ausgabe <<mExpPoints<<std::endl;
	Ausgabe <<mNextLevelExp<<std::endl;
	Ausgabe <<mArmor<<std::endl;
	Ausgabe <<mLevel<<std::endl;
	Ausgabe <<mWeapon.mName<<std::endl;
	Ausgabe <<mWeapon.mRange.mHighDamage<<std::endl;
	Ausgabe <<mWeapon.mRange.mLowDamage<<std::endl;
	Ausgabe <<mgold<<std::endl;
	Ausgabe <<x<<std::endl;
	Ausgabe <<y<<std::endl;
}
	Ausgabe.close();
}

void Player::load(Map& gameMap)

{
	int x;
	int y;
	std::ifstream Eingabe;
	Eingabe.open("savedGame.txt");
if(Eingabe)
{
	Eingabe >> mClassName;
	Eingabe >> mAccuracy;
	Eingabe >> mHitPoints;
	Eingabe >> mMaxHitPoints;
	Eingabe >> mExpPoints;
	Eingabe >> mNextLevelExp;
	Eingabe >> mArmor;
	Eingabe >> mLevel;
	Eingabe >> mWeapon.mName;
	Eingabe >> mWeapon.mRange.mHighDamage;
	Eingabe >> mWeapon.mRange.mLowDamage;
	Eingabe >> mgold;
	Eingabe >> x;
	Eingabe >> y;
	gameMap.setPlayerXPos(x);
	gameMap.setPlayerYPos(y);
}
	Eingabe.close();
}

void Player::victory(int xp)
{
	std::cout << "You won the battle!" << std::endl;
	std::cout << "You win " << xp << " experience points!" << std::endl << std::endl;
	mExpPoints += xp;
}

bool Player::gameover()
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
    return false;
  } else if (select=='q')
  {
    return true;
  }
  else
  {
    std::cout<<"invalid input"<< std::endl;
  }

	return true;
}


bool Player::attack(Monster& monster)
{
	bool switchingWeapon = true;
	while(switchingWeapon) {
		int selection = 1;
		std::cout << "1) Attack, 2) Switch Weapon,3) Run ,3) Mana:";
		std::cin >> selection;
		std::cout << std::endl;
		if(selection != 2 ){
			switchingWeapon = false;
		}
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
				{
					switchWeapon();
					break;
				}
			case 3:
				{
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
			case 4:
				displayMagicWords();
				std::cout << std::endl;
				displayHealingWords();
				std::cout << std::endl;
				std::cout << "Enter the Magic word to attack the Monster: " << std::endl;
				std::cin >> selection;
				std::cout << std::endl;
				bool MagicState = Mana(monster, getMagicWords(selection));
				return MagicState;
				
				break;
		
		}
	}
	return false;
}

bool Player::Mana(Monster& _monster ,magicWords _nmagic ){
	int Magic_damage ;
	int totalDamage;
	switch (_nmagic) {

		case Bombarda :
			std::cout << "You attack an " << _monster.getName() << " with a Explosion Magic Attack >>>>>" << std::endl;
			Magic_damage = static_cast<int>(mMaxHitPoints / 2);
			totalDamage =  Magic_damage - _monster.getArmor();
			std::cout << "You attack for " << totalDamage << " damage!" << std::endl;
			_monster.takeDamage(totalDamage);
			break;
		case Bombarda_Maxima:
			std::cout << "You attack an " << _monster.getName() << " with a Double Explosion Magic Attack >>>>><<<<<" << std::endl;
			Magic_damage = static_cast<int>(mMaxHitPoints);
			totalDamage =  Magic_damage - _monster.getArmor();
			std::cout << "You attack for " << totalDamage << " damage!" << std::endl;
			_monster.takeDamage(totalDamage);
			break;

		case Diffindo:
			std::cout << "You attack an " << _monster.getName() << " with a Surround Collapse  Magic Attack >>>>><<<<<" << std::endl;
			Magic_damage = static_cast<int>(mMaxHitPoints / 3 );
			totalDamage =  Magic_damage - _monster.getArmor();
			std::cout << "You attack for " << totalDamage << " damage!" << std::endl;
			_monster.takeDamage(totalDamage);
			break;
		case Brackium_Emendo:
			std::cout << "You activate your Magic Armor >>} " << std::endl;
			mArmor = 10;
			return true;

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
		weapons.push_back(mWeapon);
		WIndex = 0;
		Nmagics.push_back(Bombarda);
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
		weapons.push_back(mWeapon);
		WIndex = 0;
		Nmagics.clear();
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
		weapons.push_back(mWeapon);
		WIndex = 0;
		Nmagics.push_back(Bombarda);
		Nmagics.push_back(Bombarda_Maxima);
		Nmagics.push_back(Diffindo);
		Nmagics.push_back(Brackium_Emendo);
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
		weapons.push_back(mWeapon);
		WIndex = 0;
		Nmagics.push_back(Bombarda);
		Nmagics.push_back(Brackium_Emendo);
		break;
	}
}

void Player::switchWeapon() {
	if (weapons.size() > 1 ) {
		if(WIndex < weapons.size()) {
			WIndex++;
		}
		if(WIndex == weapons.size()) {
			WIndex = 0;
		} 
		std::cout << "Weapon has Switched ... " << std::endl;
		mWeapon = weapons[WIndex];
	}
	
}

void Player::getCollactables(std::vector<Treasure> _Treasures){
		 for (unsigned int i = 0 ; i < _Treasures.size(); i++ ) {
			TreasureType Ttype = _Treasures[i].getType();
			if (Ttype == DoubleHitPoint){
				std::cout << "HitPionts got Doubled $$" << std::endl;
				mHitPoints = mHitPoints * 2;
				 
			}else if(Ttype == TrippleHitPoint) {
				std::cout << "HitPionts got Trippeld $$$" << std::endl;
				mHitPoints = mHitPoints * 3;
			}else if(Ttype == ExtraArmur) {
				std::cout << "You got extra Armor }}" << std::endl;
				mArmor = mArmor + 5;
			}else if(Ttype == T_Short_Sword) {
				   std::cout << "Got new Weapon.." << std::endl;
					Weapon TWeapon;
					TWeapon.mName = "Short Sword";
					TWeapon.mRange.mLowDamage = 1;
					TWeapon.mRange.mHighDamage = 6;
					weapons.push_back(TWeapon);
			}else if(Ttype == T_Flail) {
				 std::cout << "Got new Weapon.." << std::endl;
					Weapon TWeapon;
					TWeapon.mName = "Flail";
					TWeapon.mRange.mLowDamage = 1;
					TWeapon.mRange.mHighDamage = 6;
					weapons.push_back(TWeapon);
			}else if(Ttype == T_Staff) {
				 std::cout << "Got new Weapon.." << std::endl;
					Weapon TWeapon;
					TWeapon.mName = "Staff";
					TWeapon.mRange.mLowDamage = 1;
					TWeapon.mRange.mHighDamage = 4;
					weapons.push_back(TWeapon);
			}else if(Ttype == T_Long_Sword) {
				 std::cout << "Got new Weapon.." << std::endl;
					Weapon TWeapon;
					TWeapon.mName = "Long Sword";
					TWeapon.mRange.mLowDamage = 1;
					TWeapon.mRange.mHighDamage = 8;
					weapons.push_back(TWeapon);
			}
           

    }
}


void Player::displayMagicWords(){
	std::cout << "List of Magic words:... " << std::endl;
	std::cout << "================================" << std::endl;
	for (unsigned int i = noWord ; i < healingWords ; i++ ) {
		magicWords Magic = static_cast<magicWords>(i);
		if (Magic == Bombarda) {	
			std::cout << i << ": " << std::string("Explosion")<< std::endl;
		}else if(Magic == Bombarda_Maxima) {
			std::string sTemp = "Große Explosion";
			std::cout << i << ": " << sTemp << std::endl;
		} else if(Magic == Diffindo){
			std::cout << i << ": " << "Zerreißt oder durchtrennt Gegenstände"<< std::endl;
		}
		 
	}
}

void Player::displayHealingWords(){
	std::cout << "List of Healing words:... " << std::endl;
	std::cout << "================================" << std::endl;
	for (unsigned int i = healingWords ; i < LastWord ; i++ ) {
		magicWords Magic = static_cast<magicWords>(i);
		if (Magic == Brackium_Emendo) {
			std::cout << i << ": " << "Heilt gebrochene Knochen"<< std::endl;
		}
		
		 
	}
}

magicWords Player::getMagicWords(int _selection){
		magicWords Magic = static_cast<magicWords>(_selection);
		if (Magic == Bombarda) {	
			return Bombarda;
		}else if(Magic == Bombarda_Maxima) {
			return Bombarda_Maxima;
		} else if(Magic == Diffindo){
			return Diffindo;
		} else if (Magic == Brackium_Emendo) {
			return Brackium_Emendo;
		}
		return noWord;
}