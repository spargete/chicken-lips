/*
 * Player.hpp
 *
 *  Created on: Feb 21, 2017
 *      Author: sean
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "PlayerMove.hpp"
#include "Point.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

class Player {
public:
 	Player() {}
	virtual ~Player() {}
	virtual int getXPosition() {return 0;}
	virtual int getYPosition() {return 0;}
	virtual int getAmmo() {}
	virtual int getPlayerType(){}
	virtual PlayerMove::BulletOrShieldType getShieldType() {}

	virtual void move(std::vector<Player*>* playerListPointer, int size) {}
	virtual void shoot(int xOffset, int yOffset, PlayerMove::BulletOrShieldType bulletType, std::vector<Player*>* playerListPointer, int size) {} // bulletType: 0 = metal bullet, 1 = plasma beam
	virtual void shield(PlayerMove::BulletOrShieldType shieldType) {} // shieldType: 0 = metal shield, 1 = thermionic reflector
	virtual void reload() {}

	virtual void resetShieldType() {}
	virtual void resetMovingTo(Point*** pointListPointer) {}

	virtual void setMarkedForDeath(bool mark) {}
	virtual bool getMarkedForDeath() {}

	virtual PlayerMove playMove(PlayerMove humanPlayerMove, Point*** pointListPointer, int size, int index) {}

	virtual Point* getMovingTo() {}

	int playerType; // Defines which graphic should be used for the player. Default 0 is HumanPlayer graphic

private:
	PlayerMove::BulletOrShieldType shieldType;
	virtual void setXPosition(int newX) {}
	virtual void setYPosition(int newY) {}
	int x;
	int y;
	int ammo;
	Point* movingTo; 
	bool markedForDeath;
};



#endif /* PLAYER_HPP_ */
