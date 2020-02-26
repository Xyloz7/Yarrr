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
	int x, y;
	// Adjacent tiles
	int adjtiles[4] = { 0,0,0,0 }; // UP DOWN LEFT RIGHT

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
		cout << adjtiles[3] << endl;
		// Choose unit to attack

		// Trigger attack

		break;
	case Pistol:
		break;
	case Shotgun:
		break;

	}

}