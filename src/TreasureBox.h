// TreasureBox
#ifndef TREASUREBOX_H
#define TREASUREBOX_H

#include <string>
#include <vector>
#include "Weapon.h"
#include "Treasure.h"


class TreasureBox
{
public:
	TreasureBox(const std::string& _name);
	std::string getName();
	void setPositon(int _xPos , int _yPos);
	int getXpos();
	int getYpos();
	void clear();
	bool IsEmpty();
	void randomFill();
	void setTreasure(Treasure _treasure);
    std::vector<Treasure> getTreasuresFromTheBox();
	void ListCollactables();
private:
	std::string mName;
	std::vector<Treasure> Treasures;
	int mTreasureXPos;
	int mTreasureYPos;
};


#endif // TREASUREBOX_H