#include "Tunnel.h"
#include <string>
#include <iostream>


using namespace std;

Tunnel::Tunnel(const std::string& _name, int _xPos, int _yPos, bool _open)
{
    mName = _name;
    mXPos = _xPos;
    mYPos = _yPos;
    openTunnel = _open;
}


std::string Tunnel::getName()
{
	return mName;
}
int Tunnel::getXpos()
{
	return mXPos;
}
int Tunnel::getYpos()
{
	return mYPos;
}

bool Tunnel::isOpen() {
   return openTunnel;
}
void Tunnel::setOpen(bool _open)
{
	openTunnel = _open;
}

void Tunnel::setXpos(int _xPos)
{
	mXPos = _xPos;
}
void Tunnel::setYpos(int _yPos)
{
	mYPos = _yPos;
}

void Tunnel::displayTunnelEndPosition(){

    std::cout << "Tunnel Leads To .. " << std::endl;
	std::cout << "===================" << std::endl;
    std::cout << "End X Position is : " << mXPos << std::endl;
    std::cout << "End Y Position is : " << mXPos << std::endl;
	std::cout << std::endl;
}


