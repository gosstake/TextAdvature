// Scamander
#ifndef SCAMANDER_H
#define SCAMANDER_H

#include <string>
#include <vector>
#include "Weapon.h"


class Scamander
{
public:
	Scamander(const std::string& _name);
	
	std::string getName();
    void displayObjectsList();
	Weapon getWeapon(unsigned int Index);
private:
	std::string mName;
    std::vector<Weapon> Weapons;
	 
};


#endif // SCAMANDER_H