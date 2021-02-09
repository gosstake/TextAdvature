#include "Map.h"
#include <iostream>
#include <stdlib.h> 
#include "Player.h"

using namespace std;

Map::Map()
{
	mPlayerXPos = 0;
	mPlayerYPos = 0;

}

void Map::createMap() {

	std::cout << "MAP CLASS GENERATION" << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "Enter Field Width :  ";
	std::cin >> mapWidth;
	if (mapWidth < 10 ){
		std::cout << "Minimum Width is 10 will be Set! :  ";
		mapWidth = 10;
	}
	std::cout << std::endl << "Enter Field Hight :  ";
	std::cin>> mapHight;
	if (mapHight < 10 ){
		std::cout << "Minimum Hight is 10 will be Set! :  ";
		mapHight = 10;
	}


}

int Map::getPlayerXPos() 
{
	return mPlayerXPos;
}

int Map::getPlayerYPos()
{
	return mPlayerYPos;
}


void Map::displayMap(Monster& monster, Tunnel& _mTunnel, TreasureBox& _mTreasureBox) {
		std::cout << std::endl;
		for(int i  = 0; i < mapHight; i++){
			for(int j = 0; j < mapWidth ; j++){
				if(j == 0 || j == mapWidth-1 || i == 0 || i == mapHight-1 ){
					std::cout <<"+  ";
				}else {
					if (i == static_cast<int>(mapHight/2 ) - mPlayerYPos && j == static_cast<int>(mapWidth/2) + mPlayerXPos ) {
						std::cout <<"C  ";
					}else if ( _mTunnel.isOpen() && (i == static_cast<int>(mapHight/2 ) - _mTunnel.getYpos() && j == static_cast<int>(mapWidth/2) + _mTunnel.getXpos() )) {
						std::cout <<"U  ";
					}else if ((!_mTreasureBox.IsEmpty()) && (i == static_cast<int>(mapHight/2 ) - _mTreasureBox.getYpos() && j == static_cast<int>(mapWidth/2) + _mTreasureBox.getXpos() )){
						std::cout <<"[*]";
					}else if (j == static_cast<int>(mapWidth/2)-1 && i == static_cast<int>(mapHight/2 )-1 ){
						std::cout <<"+  ";
					}else {
						std::cout <<"-  ";
					}
					
				}
			}
			std::cout << std::endl;
		}
}


void Map::setPlayerXPos(int x) 
{
	mPlayerXPos=x;
}

void Map::setPlayerYPos(int y) 
{
	mPlayerYPos=y;
}

void Map::movePlayer(Tunnel &_mTunnel)
{
	int selection = 1;
	if (_mTunnel.isOpen()){
		std::cout << "1) North, 2) East, 3) South, 4) West: 5) UseTunnel  ";
	}else {
		std::cout << "1) North, 2) East, 3) South, 4) West: ";
	}
	std::cin >> selection;
	switch (selection)
	{
	case 1: // North
		mPlayerYPos++;
		break;
	case 2: // East
		mPlayerXPos++;
		break;
	case 3: // South
		mPlayerYPos--;
		break;
	case 4: //Weset
		mPlayerXPos--;
		break;
	case 5: //Tunnel Move
		mPlayerXPos =  _mTunnel.getXpos();
		mPlayerYPos =  _mTunnel.getYpos();
		_mTunnel.setOpen(false);
		break;
	default: // West
		mPlayerXPos--;
		break;
	}
	std::cout << std::endl;
}

bool Map::checkInPosition(int _xPosition , int _yPosition) {
	if(mPlayerXPos == _xPosition && mPlayerYPos == _yPosition) {
		return true;
	}else {
		return false;
	}
}

void Map::checkEncounter( Player& _player, TreasureBox& _treasureBox ) {
		if(checkInPosition(_treasureBox.getXpos(), _treasureBox.getYpos())){
				_treasureBox.ListCollactables();
				std::cout << "Do you want to get the Collactables ? [y/N] " << std::endl;
				std::string ans;
				std::cin >> ans;
				if(ans == "y"){
					_player.getCollactables(_treasureBox.getTreasuresFromTheBox());
					_treasureBox.clear();
				}else{
					_treasureBox.clear();

				}
		}
}


Monster* Map::checkRandomEncounter(Scamander& _scamander, Tunnel& _tunnel, TreasureBox& _treasureBox )
{
	int roll 			= Random(0, 20);
	int xdistance 		= Random(abs(mPlayerXPos), abs(mPlayerXPos) + 4);
	int ydistance 		= Random(abs(mPlayerYPos), abs(mPlayerYPos) + 4);
	int XPosition_roll 	= RandomPosition(abs(mPlayerXPos), xdistance);
	int YPosition_roll 	= RandomPosition(abs(mPlayerYPos), ydistance);
	
	Monster* monster = 0;
		if ( roll < 5 ) { // 10
			std::cout << "Monster Positon Roll: X: "<< XPosition_roll << " Y: " << YPosition_roll  << " Distance form You:  X: " << xdistance <<" Y: "<< ydistance << std::endl;
			if ((xdistance - abs(mPlayerXPos) <= 2 ) && (XPosition_roll < abs(mPlayerXPos) + xdistance  && XPosition_roll > abs(mPlayerXPos) - xdistance) && (YPosition_roll < abs(mPlayerYPos) + ydistance  && YPosition_roll > abs(mPlayerYPos) - ydistance)) {
				monster = new Monster("Orc", 10, 8, 200, 1, "Short Sword", 2, 7, 2);
				std::cout << "You encountered an Orc!" << std::endl;
				std::cout << "Prepare for battle!" << std::endl;
				std::cout << std::endl;
			} else if ((xdistance - abs(mPlayerXPos)  > 2  ) &&(XPosition_roll < abs(mPlayerXPos) + xdistance  && XPosition_roll > abs(mPlayerXPos) - xdistance) && (YPosition_roll < abs(mPlayerYPos) + ydistance  && YPosition_roll > abs(mPlayerYPos) - ydistance)) {
				monster = new Monster("Goblin", 6, 6, 100, 0, "Dagger", 1, 5, 1);
				std::cout << "You encountered a Goblin!" << std::endl;
				std::cout << "Prepare for battle!" << std::endl;
				std::cout << std::endl;
			} else if ((ydistance - abs(mPlayerYPos) <= 2 ) &&(XPosition_roll < abs(mPlayerXPos) + xdistance  && XPosition_roll > abs(mPlayerXPos) - xdistance) && (YPosition_roll < abs(mPlayerYPos) + ydistance  && YPosition_roll > abs(mPlayerYPos) - ydistance)) {
				monster = new Monster("Ogre", 20, 12, 500, 2, "Club", 3, 8, 3);
				std::cout << "You encountered an Ogre!" << std::endl;
				std::cout << "Prepare for battle!" << std::endl;
				std::cout << std::endl;
			} else if ((ydistance - abs(mPlayerYPos) > 2 ) &&(XPosition_roll < abs(mPlayerXPos) + xdistance  && XPosition_roll > abs(mPlayerXPos) - xdistance) && (YPosition_roll < abs(mPlayerYPos) + ydistance  && YPosition_roll > abs(mPlayerYPos) - ydistance)) {
				monster = new Monster("Orc Lord", 25, 15, 2000, 5, "Two Handed Sword", 5, 20, 5);
				std::cout << "You encountered an Orc Lord!!!" << std::endl;
				std::cout << "Prepare for battle!" << std::endl;
				std::cout << std::endl;
			}
		} else {
			 if (roll >= 6 && roll <= 10){
				std::cout << "You encountered an Weabon sale Man !" << std::endl;
				std::cout << "Say Hi to Scamander!" << std::endl;
				_scamander.displayObjectsList();
				std::cout << std::endl;
			 } else if(roll >= 11 && roll <= 15) {
				int xPosition = Random(-1 * (static_cast<int>(mapWidth/2 )-5) , +1 * (static_cast<int>(mapWidth/2 )-5));
				int yPosition = Random(-1 * (static_cast<int>(mapHight/2 )-2) , +1 * (static_cast<int>(mapHight/2 )-2));
				_tunnel.setOpen(true);
				_tunnel.setXpos(xPosition);
				_tunnel.setYpos(yPosition);
				std::cout << "You encountered an Tunnel !" << xPosition << " " << yPosition << std::endl;
				std::cout << "You can move into the tunnel by the next move !" << std::endl;
				std::cout << std::endl;
			 } else if((roll >= 16 && roll <= 19)) {

				if (_treasureBox.IsEmpty()) {
					int xPosition = Random(-1 * (static_cast<int>(mapWidth/2 )-5) , +1 * (static_cast<int>(mapWidth/2 )-5));
					int yPosition = Random(-1 * (static_cast<int>(mapHight/2 )-2) , +1 * (static_cast<int>(mapHight/2 )-2));
					_treasureBox.setPositon(xPosition, yPosition);
					_treasureBox.randomFill();
					
					std::cout << "You encountered an Treasure Box  ! at Poition X: "<<xPosition  << " Y: " <<  yPosition << std::endl;
					std::cout << "Get your Collactables .. !" << std::endl;
					std::cout << std::endl;
				}
			 }
		}
	return monster;
}

void Map::printPlayerPos() {
	std::cout << "Player Position = (" << mPlayerXPos << ", " << mPlayerYPos << ")" << std::endl << std::endl;
}


