// MAP_H
#ifndef MAP_H // include guard
#define MAP_H

#include "Weapon.h"
#include "Monster.h"
#include "Scamander.h"
#include "TreasureBox.h"
#include "Player.h"
#include "Tunnel.h"
#include <string>

using namespace std;

class Map
{
public:
	Map();
	void createMap();
	void displayMap(Monster& monster, Tunnel& _mTunnel, TreasureBox& _mTreasureBox);
	int getPlayerXPos();
	int getPlayerYPos();
	void movePlayer();
	void movePlayer(Tunnel& _mTunnel);
	Monster* checkRandomEncounter(Scamander& _scamander, Tunnel& _tunnel, TreasureBox& _treasureBox );
	void checkEncounter( Player& _player, TreasureBox& _treasureBox );
	void printPlayerPos();
	bool checkInPosition(int _xPosition , int _yPosition);
private:
	int mapWidth;
	int mapHight;
	int mPlayerXPos;
	int mPlayerYPos;


};

#endif // MAP_H




