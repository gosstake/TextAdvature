#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Scamander.h"
#include "TreasureBox.h"
#include "Tunnel.h"
#include <cstdlib>
#include <ctime>
#include "Shop.h"
using namespace std;

int main()
{
	srand(time(NULL));

	Map gameMap;
	Player mainPlayer;

	Scamander scamander("Scamander");
	Tunnel tunnel("Slip", 0 , 0, false);
	TreasureBox treasureBox("default");

	gameMap.createMap();
	Shop gameShop;

	int sel;
	cout<<"Do you want to load a saved game?"<<endl;
	cout<<"1) Yes, 2) No"<<endl;
	cin>>sel;

	if (sel==1) {
		int x = 0;
		int y = 0;
		mainPlayer.load(x, y);
		gameMap.setPlayerXPos(x);
		gameMap.setPlayerYPos(y);
	} else {
		mainPlayer.createClass();
	}

	bool gameOver = false;

	while(!gameOver)
	{
		cout << "==================== Next Round ==================== ";
		gameMap.printPlayerPos();
		gameShop.playerArrived(gameMap, mainPlayer, gameShop);

		int selection = 1;
		cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
		cin >> selection;
		Monster* monster = 0;
		

		switch (selection)
		{
		case 1:
			gameMap.movePlayer(tunnel);
			gameMap.checkEncounter(mainPlayer, treasureBox);
			monster = gameMap.checkRandomEncounter(scamander, tunnel, treasureBox);
			gameMap.displayMap(*monster, tunnel,treasureBox);
			if (monster != 0)
			{
				while (true)
				{
					mainPlayer.displayHitPoints();
					monster->displayHitPoints();
					cout << endl;
					bool runAway = mainPlayer.attack(*monster);
					if (runAway)
						break;
					if (monster->isDead())
					{
						mainPlayer.victory(monster->getXPReward(), monster->getGold());
						mainPlayer.levelUp();
						break;
					}
					monster->attack(mainPlayer);
					if (mainPlayer.isDead())
					{
						gameOver = mainPlayer.gameover();
						if(!gameOver) 
							mainPlayer.createClass();
						break;
					}
				}
				delete monster;
				monster = 0;
			}else {
				if(scamander.getMeetPlayer()){
					while (true) {
						std::cout << "Enter Item number to buy it [0 to Skip] :" ;
						int selection = 0;
						std::cin >> selection;
						if (selection > 0) {
							mainPlayer.buyWeapon(scamander.getWeapon(selection));
						}else {
							break;
						}
					}
					scamander.setMeetPlayer(false);
				
				}
			}
			break;
		case 2:
			mainPlayer.rest();
			monster = gameMap.checkRandomEncounter(scamander, tunnel, treasureBox);
			if (monster != 0)
			{
				while (true)
				{
					mainPlayer.displayHitPoints();
					monster->displayHitPoints();
					cout << endl;
					bool runAway = mainPlayer.attack(*monster);
					if (runAway)
						break;
					if (monster->isDead())
					{
						mainPlayer.victory(monster->getXPReward(), monster->getGold());
						mainPlayer.levelUp();
						break;
					}
					monster->attack(mainPlayer);
					if (mainPlayer.isDead())
					{
						mainPlayer.gameover();
						gameOver = true;
						break;
					}
				}
				delete monster;
				monster = 0;
			}
			break;
		case 3:
			mainPlayer.viewStats();
			break;
		case 4:
			cout<<"Do you want to save the game?"<<endl;
			cout<<"1) Yes , 2) No "<<endl;
			cin>>selection;
			if (selection==1)
			{
				mainPlayer.save(gameMap.getPlayerXPos(), gameMap.getPlayerYPos());
				cout<<"You saved the game. Goodbye!"<<endl;
			}
			gameOver = true;
			break;
		}
	}
}


