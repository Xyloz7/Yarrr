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
	int x, y, TargetIndex, ATK, DEF, DMG, adjtiles_index;
	bool ConfirmATK = false;

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


		/*cout << "Pre Delete : ";
		for (size_t i = 0; i < adjtiles.size(); i++) {
			cout << adjtiles[i] << " ";
		}
		cout << endl;*/

		for (size_t i = adjtiles.size()-1; i > 0;  i--) {


			if (adjtiles[i] == 0) {
				adjtiles.erase(adjtiles.begin() + i);
			}
		}

		if (adjtiles[0] == 0) {
			adjtiles.erase(adjtiles.begin());
		}

		/*cout << "Post Delete : ";
		for (size_t i = 0; i < adjtiles.size(); i++) {
			cout << adjtiles[i] << " ";
		}
		cout << endl;*/

		
		// Only Attack if there is at least one valid target
		if (adjtiles.size() > 0) {

			// If only one target, attack it
			if (adjtiles.size() == 1) {
				TargetIndex = 0;
				// Find target index
				for (size_t i = 0; i < adjtiles.size(); i++) {
					TargetIndex += adjtiles[i];
				}

			}

			// If multiple possible, select desired target
			else if (adjtiles.size() > 1) {
				// Selection process
				cout << "Multiple Targets, please select one" << endl;
				
				// Default selection
				adjtiles_index = 0;
				TargetIndex = adjtiles[adjtiles_index];

				cout << "Currently selecting" << adjtiles[adjtiles_index] << endl;

				while (!ConfirmATK) {

					SDL_Event e;
					SDL_PollEvent(&e);
					if (e.type == SDL_KEYDOWN) {

						switch (e.key.keysym.sym) {
							// Arrow Key Movement
						case SDLK_RIGHT:
							adjtiles_index += 1;
							adjtiles_index = adjtiles_index%adjtiles.size();
							TargetIndex = adjtiles[adjtiles_index];
							cout << "Currently selecting" << adjtiles[adjtiles_index] << endl;
							break;
						case SDLK_RETURN:
							ConfirmATK = true;
							break;
						}
					}
				}


			}


			//////////////////////////////////////////////////////////////////////
			// Attack Logic
			//////////////////////////////////////////////////////////////////////
			// Calculate player attack
			ATK = U->LevelUnits[PlayerIndex]->ATK;
			ATK += U->LevelUnits[PlayerIndex]->UnitWeapon->ATK;

			// Calculate target's defense
			DEF = U->LevelUnits[TargetIndex]->DEF;
			DEF += U->LevelUnits[TargetIndex]->UnitWeapon->DEF;

			// Calculate damage based off this
			// TODO - more interesting formula, introduce some randomness
			DMG = ATK - DEF;

			// Deal DMG to target
			U->LevelUnits[TargetIndex]->loseHP(DMG);
			cout << DMG << " Damage dealt = " << ATK << "-" << DEF << endl;

			//////////////////////////////////////////////////////////////////////
			// Attack Logic end
			//////////////////////////////////////////////////////////////////////

		} 

		
		//cout << count << endl;


		break;
	case Pistol:
		break;
	case Shotgun:
		break;

	}

}