#pragma once
#include "GameObject.h"
// FORWARD DECLARATION, circular includes
class Weapon;
#include "Weapon.h"

// Unit class for players/enemies


extern int TILESIZE;

class Unit : public GameObject
{
public:
	Unit();
	Unit(const char* texturesheet, int x, int y);

	// Function to set stats
	void StatInit();
	void loseHP(int damage);
	// Function to display HP bar
	void showHP();
	Weapon* UnitWeapon;

	// Units have stats i.e. health, mana etc
	int maxHP;
	int curr_HP;
	int ATK;
	int DEF;
protected:



private:

};

