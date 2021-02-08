#include "Treasure.h"
#include "weapon.h"
#include <string>
#include <iostream>


using namespace std;

Treasure::Treasure(const std::string& _name, int _value , TreasureType _type, 
                    int _lowDamage, int _highDamage)
{
    mName = _name;
    mValue = _value;
    highDamage = _lowDamage;
    lowDamage = _highDamage;
    type = _type;
}


std::string Treasure::getName()
{
	return mName;
}

TreasureType Treasure::getType()
{
	return type;
}

int Treasure::getValue(){
    return mValue;
}

void Treasure::displayType()
{
    std::cout << "Treasure Type is :" << std::endl;
    if (type == DoubleHitPoint) {	
        std::cout << "DoubleHitPoint" << std::endl;
    }else if(type == TrippleHitPoint) {
       std::cout << "TrippleHitPoint " << std::endl;
    } else if(type == ExtraArmur){
       std::cout << "ExtraArmur" << std::endl;
    } else if (type == Long_Sword) {
       std::cout << "Long_Sword " << std::endl;
    }else if (type == Staff) {
       std::cout << "Staff " << std::endl;
    }else if (type == Flail) {
       std::cout << "Flail " << std::endl;
    }else if (type == Short_Sword) {
       std::cout << "Short_Sword " << std::endl;
    }
}

void Treasure::setValue(int _value) {
        mValue = _value;

}
