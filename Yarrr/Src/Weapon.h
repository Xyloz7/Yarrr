#pragma once

class UnitManager;
#include "Map.h"
#include "UnitManager.h"

class Weapon
{
public:

	Weapon();
	~Weapon();

	enum WeaponType {
		None,
		Hook,
		Pistol,
		Shotgun
	};

	void PrimaryAttack(int PlayerIndex, Map *lvlMap, UnitManager *U);
	void render();
	
	WeaponType myWeapon;


	// Stats provided
	int ATK, DEF, HP;


protected:

private:
};