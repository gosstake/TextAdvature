// Treasure
#ifndef TREASURE_H
#define TREASURE_H

#include <string>
#include "Weapon.h"

enum TreasureType {
    firtTreasureType = 0,
    T_Short_Sword = 1,
    T_Flail= 2,
    T_Staff= 3,
    T_Long_Sword= 4,
    DoubleHitPoint = 5,
    TrippleHitPoint = 6,
    ExtraArmur = 7,
  
    LastTreasureType = 8
};


class Treasure
{
public:
	Treasure(const std::string& _name, int _value, TreasureType _type,
		int _lowDamage, int _highDamage);
	std::string getName();
	void setValue(int _value);
    TreasureType getType();
    int getValue();
	void displayType();
private:
	std::string mName;
	int mValue;
    int highDamage;
    int lowDamage;
    TreasureType type;
    

};

#endif // TREASURE_H