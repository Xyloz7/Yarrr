#include "Weapon.h"


// Overload constructor, allow for zero creation
Weapon::Weapon()
{
	myWeapon = WeaponType::Hook;
	ATK = DEF = HP = 0;
}

Weapon::~Weapon()
{

}

void Weapon::render()
{
	// SDL_RenderCopy(WindowRenderer::renderer, objTexture, &srcRect, &destRect);

}

void Weapon::PrimaryAttack(int PlayerIndex, Map *lvlMap, UnitManager *U)
{
	int x, y, count, TargetIndex, ATK, DEF, DMG;

	// Adjacent tiles
	vector<int > adjtiles{ 0, 0, 0, 0 };
	// int adjtiles[4] = { 0,0,0,0 }; // UP DOWN LEFT RIGHT

	// Position
	x = U->LevelUnits[PlayerIndex]->xpos;
	y = U->LevelUnits[PlayerIndex]->ypos;


	// Switch and perform a different attack based on the weapon type
	switch (myWeapon){

	case Hook:
////////////////////////////////////////////////////////////////////////
		// Find adjacent Units and store their index in adjtiles
		for (size_t i = 1; i < U->LevelUnits.size(); i++) {
			// UP
			if (U->LevelUnits[i]->xpos == x && U->LevelUnits[i]->ypos == y-1) {
				adjtiles[0] = i;
			}
			// DOWN
			else if(U->LevelUnits[i]->xpos == x && U->LevelUnits[i]->ypos == y + 1) {
				adjtiles[1] = i;
			}
			// LEFT
			else if (U->LevelUnits[i]->xpos == x - 1 && U->LevelUnits[i]->ypos == y) {
				adjtiles[2] = i;
			}
			// RIGHT
			else if (U->LevelUnits[i]->xpos == x + 1 && U->LevelUnits[i]->ypos == y) {
				adjtiles[3] = i;
			}
		}
////////////////////////////////////////////////////////////////////////
		// Choose unit to attack
		count = 0;
		for (size_t i = 0; i < adjtiles.size(); i++) {
			if (adjtiles[i] > 0) {
				count += 1;
			}
		}


		if (count == 1) {
			TargetIndex = 0;
			// Find target index
			for (size_t i = 0; i < adjtiles.size(); i++) {
				TargetIndex += adjtiles[i];
			}

			// Attack Logic

			// Calculate player attack
			ATK = U->LevelUnits[PlayerIndex]->ATK;
			ATK += U->LevelUnits[PlayerIndex]->UnitWeapon->ATK;

			// Calculate target's defense
			DEF = U->LevelUnits[TargetIndex]->DEF;
			DEF = U->LevelUnits[TargetIndex]->UnitWeapon->DEF;

			// Calculate damage based off this
			// TODO - more interesting formula, introduce some randomness
			DMG = ATK - DEF;

			// losehp
			U->LevelUnits[TargetIndex]->loseHP(DMG);



		}
		else if (count > 1) {
			// Selection process
		
		}

		cout << count << endl;

		// Trigger attack

		break;
	case Pistol:
		break;
	case Shotgun:
		break;

	}

}