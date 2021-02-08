// WEAPON_H
#ifndef WEAPON_H // include guard
#define WEAPON_H

#include "DamageRange.h"
#include "Random.h"
#include <string>


using namespace std;

enum WeabonType { 
	Short_Sword,
	Flail,
	Staff,
	Long_Sword,

	lastType
};

struct Weapon
{
	std::string mName;
	DamageRange mRange;
	WeabonType mType;
	int mPrice;
};


#endif // WEAPON_H