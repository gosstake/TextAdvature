#include <iostream>
#include "Map.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include "Shop.h"
using namespace std;

int main()
{
	srand(time(NULL));

	Map gameMap;
	Player mainPlayer;
	Shop gameShop;

	int sel;
	cout<<"Do you want to load a saved game?"<<endl;
	cout<<"1) Yes, 2) No"<<endl;
	cin>>sel;

	if (sel==1)
	{
		mainPlayer.load(gameMap);
	}
	else
	{
	mainPlayer.createClass();
	}

	bool gameOver = false;

	while(!gameOver)
	{
		gameMap.printPlayerPos();
		gameShop.playerArrived(gameMap,mainPlayer, gameShop);

		int selection = 1;
		cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
		cin >> selection;
		Monster* monster = 0;

		switch (selection)
		{
		case 1:
			gameMap.movePlayer();
			monster = gameMap.checkRandomEncounter();
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
			}
			break;
		case 2:
			mainPlayer.rest();
			monster = gameMap.checkRandomEncounter();
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
				mainPlayer.save(gameMap);
				cout<<"You saved the game. Goodbye!"<<endl;
			}
			gameOver = true;
			break;
		}
	}
}


