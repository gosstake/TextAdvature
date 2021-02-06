#include "TreasureBox.h"
#include "weapon.h"
#include <string>
#include <iostream>


using namespace std;

TreasureBox::TreasureBox(const std::string& _name)
{
    mName = _name;
}



std::string TreasureBox::getName()
{
		return mName;
}

bool TreasureBox::IsEmpty()
{
    return Treasures.empty();
}

void TreasureBox::setPositon(int _xPos , int _yPos){
    mTreasureXPos = _xPos;
    mTreasureYPos = _yPos;
}

int TreasureBox::getXpos() {
    return mTreasureXPos;
}

int TreasureBox::getYpos() {
    return mTreasureYPos;
}

void TreasureBox::setTreasure(Treasure _treasure)
{
	Treasures.push_back(_treasure);
}

void TreasureBox::randomFill()
{
   while (Treasures.size() < 2 ) {
        int roll = Random(static_cast<int>(firtTreasureType)+1, static_cast<int>(LastTreasureType)-1);
        TreasureType Ttype = static_cast<TreasureType>(roll);
        Treasure TTemp("T1",roll, Ttype, 0, 10);
        Treasures.push_back(TTemp);
   }
   
}
void TreasureBox::clear(){
    Treasures.clear();
}
void TreasureBox::ListCollactables() {
    std::cout << "You have reached the TreasureBox.. !" << std::endl;
    std::cout << "List of Collactables .. !" << std::endl;
    for (unsigned int i = 0 ; i < Treasures.size(); i++ ) {
           std::cout << "Name :" << Treasures[i].getName() << " Type : "<< Treasures[i].getType() << " Value : " << Treasures[i].getValue()<< std::endl;  
    }
}

 std::vector<Treasure> TreasureBox::getTreasuresFromTheBox(){

        return Treasures;
 }
