#include "Scamander.h"
#include "DamageRange.h"
#include "weapon.h"
#include <string>
#include <iostream>


using namespace std;

Scamander::Scamander(const std::string& _name)
{
    mName = _name;
	// intiailize range damgage 
	for (int i = static_cast<WeabonType>(0) ; i < lastType ; i++ ) {
		WeabonType wType = static_cast<WeabonType>(i);
		if (wType == Short_Sword) {
			Weapon weapon; 
			DamageRange damage;
			damage.mHighDamage = 3;
			damage.mLowDamage = 1;
			weapon.mPrice = 3;
			weapon.mRange = damage;
			weapon.mType = Short_Sword;
			Weapons.push_back(weapon);
		}else if (wType == Flail) {
			Weapon weapon; 
			DamageRange damage;
			damage.mHighDamage = 15;
			damage.mLowDamage = 5;
			weapon.mPrice = 7;
			weapon.mRange = damage;
			weapon.mType = Flail;
			Weapons.push_back(weapon);
		} else if (wType == Staff) {
			Weapon weapon; 
			DamageRange damage;
			damage.mHighDamage = 10;
			damage.mLowDamage = 7;
			weapon.mPrice = 5;
			weapon.mRange = damage;
			weapon.mType = Staff;
			Weapons.push_back(weapon);
		} else if (wType == Long_Sword) {
			Weapon weapon; 
			DamageRange damage;
			damage.mHighDamage = 20;
			damage.mLowDamage = 12;
			weapon.mPrice = 10;
			weapon.mRange = damage;
			weapon.mType = Long_Sword;
			Weapons.push_back(weapon);
		}
		
		 
	}

	

}


std::string Scamander::getName()
{
	return mName;
}

bool Scamander::getMeetPlayer(){
	return mMeetPlayer;
}

void Scamander::setMeetPlayer(bool _meet){
	mMeetPlayer = _meet;
}

void Scamander::displayObjectsList()
{
	for (unsigned int i = 0 ; i < Weapons.size(); i++ ) {
		if (Weapons[i].mType == Short_Sword) {
			std::cout << i + 1 << ": " << "Short_Sword "<< "Price: "<< Weapons[i].mPrice << " MaxDamage: " << Weapons[i].mRange.mHighDamage << std::endl;
		}else if(Weapons[i].mType == Flail) {
			std::cout << i + 1<< ": " << "Flail"<< "Price: "<< Weapons[i].mPrice << " MaxDamage: " << Weapons[i].mRange.mHighDamage << std::endl;
		} else if(Weapons[i].mType == Long_Sword){
			std::cout << i + 1<< ": " << "Long_Sword"<< "Price: "<< Weapons[i].mPrice << " MaxDamage: " << Weapons[i].mRange.mHighDamage << std::endl;
		}else if(Weapons[i].mType == Staff) {
			std::cout << i + 1<< ": " << "Staff"<< "Price: "<< Weapons[i].mPrice << " MaxDamage: " << Weapons[i].mRange.mHighDamage << std::endl;
		}	 
	}
}

Weapon Scamander::getWeapon(unsigned int Index) {
		Weapon weapon;
		if (Index >= 0 || Index < Weapons.size()){
			Weapon weapon = Weapons[Index];
		}
		 
		return weapon;

}


