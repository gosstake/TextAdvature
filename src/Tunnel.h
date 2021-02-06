// Tunnel
#ifndef TUNNEL_H
#define TUNNEL_H

#include <string>
#include <vector>
#include "Weapon.h"


class Tunnel
{
public:
	Tunnel(const std::string& _name, int _mXPos, int _mYPos, bool _open);
	std::string getName();
    int getXpos();
    int getYpos();
    void setXpos(int _xPos);
    void setYpos(int _yPos);
	void displayTunnelEndPosition();
    void setOpen(bool _open);
    bool isOpen();
private:
	std::string mName;
    int mXPos;
    int mYPos;
    bool openTunnel;
};

#endif // TUNNEL_H