/*
 * Player.h
 *
 *  Created on: Oct 6, 2015
 *      Author: Caro Strickland
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include <cstring>

namespace std {

class Player {
public:
	Player();
	virtual ~Player();
	void setName(string n);
	string getName();
private:
	string name;
};

} /* namespace std */

#endif /* PLAYER_H_ */
