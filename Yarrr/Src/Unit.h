#pragma once
#include "GameObject.h"

// Unit class for players/enemies


extern int TILESIZE;

class Unit : public GameObject
{
public:
	Unit();
	Unit(const char* texturesheet, int x, int y);

	// Function to set stats
	void StatInit();


	// Function to display HP bar
	void showHP();

protected:
	// Units have stats i.e. health, mana etc
	int maxHP;
	int curr_HP;
	int ATK;
	int DEF;


private:

};

