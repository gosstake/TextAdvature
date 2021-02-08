#include <map>
#include <iostream>
#include <string>
#include "Map.h"
#include "Shop.h"
#include "Player.h"
#include "Weapon.h"


Shop::Shop()
{
    mShopXPosition = 3;
    mShopYPosition = 5;
}

int Shop::getShopXPosition() 
{
	return mShopXPosition;
}

int Shop::getShopYPosition()
{
	return mShopYPosition;
}

void Shop::purchaseHealth(Player& mainPlayer)

{
    int selection;
    selection = 2;
    std::cout<<"The price for a full healing is 1 Gold. Do you want to get healed?"<<std::endl;
    std::cout<<"1) Yes, 2) No ";
    std::cin>>selection;
    if (selection==1)
    {
        mainPlayer.heal();
        std::cout<<"You are healed!"<<std::endl;
    }
    else
    {
        std::cout<<"You got no healing. Have a nice day!"<<std::endl;
    }
}

void Shop::purchaseWeapon(Player& mainPlayer)

{
    int selection;
    selection = 4;
    std::cout<<"Which weapon do you want to buy?"<<std::endl;
    std::cout<<"1) Excalibur (20-40 Damage Range) : 10 Gold"<<std::endl;
    std::cout<<"2) Burning Axe (10-20 Damage Range) : 5 Gold"<<std::endl;
    std::cout<<"3) Club (3-12 Damage Range) : 3 Gold"<<std::endl;
    std::cout<<"4) None";
    std::cin>> selection;
            switch (selection)
	        {
            case 1: 
                mainPlayer.setGold(-10);
                mainPlayer.setWeapon(20,40,"Excalibur");
                std::cout<<"You are now owner of Excalibur! "<<std::endl; 
                break;
            case 2: 
                mainPlayer.setGold(-5);
                mainPlayer.setWeapon(10,20,"Burning Axe");
                std::cout<<"Be carefully! Your Axe is hot!"<<std::endl;
                break;
            case 3: 
                mainPlayer.setGold(-3);
                mainPlayer.setWeapon(10,20,"Club");
                std::cout<<"Wow! Is this really an upgrade? You should get some more Gold Clubman."<<std::endl;
                break;
            default: 
                std::cout<<"You left the Shop! Good Luck with your weak Weapon!"<<std::endl;
                break;
            }

}

void Shop::purchaseArmor(Player& mainPlayer)

{
    int selection;
    selection = 4;
    std::cout<<"Which Armor do you want to buy?"<<std::endl;
    std::cout<<"1) Weak (+1) : 1 Gold , 2) Middle (+2) : 2 Gold , 3) Strong (+3) : 3 Gold, 4) None";
    std::cin>> selection;
            switch (selection)
	        {
            case 1: 
                mainPlayer.setGold(-1);
                mainPlayer.setArmor(1);
                std::cout<<"You got 1 extra armor "<<std::endl; 
                break;
            case 2: 
                mainPlayer.setGold(-2);
                mainPlayer.setArmor(2);
                std::cout<<"You got 2 extra armor "<<std::endl;
                break;
            case 3: 
                mainPlayer.setGold(-3);
                mainPlayer.setArmor(3);
                std::cout<<"You got 3 extra armor "<<std::endl;
                break;
            default: 
                std::cout<<"You left the Shop! Good Luck!"<<std::endl;
                break;
            }

}

void Shop::playerArrived(Map& gameMap,Player& gamePlayer, Shop& gameShop)
{
    
    if (mShopXPosition==gameMap.getPlayerXPos() && mShopYPosition==gameMap.getPlayerYPos())
    {
        int selection = 1;
        std::cout << "You arrived at the Shop" << std::endl;
        std::cout<<"Do you want to purchase anything?" <<std::endl;
        std::cout<<"1) Yes, 2) No ";
        std::cin>> selection;

        if (selection==1)
        {
            selection=4; 
            std::cout<<"What do you want to buy?"<<std::endl;
            std::cout<<"1) Armor, 2) Health, 3) Weapons 4) Nothing ";
            std::cin>> selection;
            switch (selection)
	        {
            case 1: 
                gameShop.purchaseArmor(gamePlayer);
                break;
            case 2: 
                gameShop.purchaseHealth(gamePlayer);
                break;
            case 3: 
                gameShop.purchaseWeapon(gamePlayer);
                break;
            default: 
                std::cout<<"You left the Shop! Good Luck!"<<std::endl;
                break;
            }
        }
        else
        {
           std::cout<<"You left the Shop! Good Luck!"<<std::endl;
        }
    }
}