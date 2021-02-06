#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Scamander.h"
#include "TreasureBox.h"
#include "Tunnel.h"
#include <cstdlib>
#include <ctime>

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
	mainPlayer.createClass();

	bool gameOver = false;

	while(!gameOver)
	{
		cout << "==================== Next Round ==================== ";
		gameMap.printPlayerPos();
		
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
						mainPlayer.victory(monster->getXPReward());
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
			}else {

			}
			break;
		case 2:
			mainPlayer.rest();
			break;
		case 3:
			mainPlayer.viewStats();
			break;
		case 4:
			gameOver = true;
			break;
		}
	}
}


