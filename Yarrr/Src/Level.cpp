#include "Level.h"
#include "ObjManager.h"
#include "Unit.h"
#include "GameState.h"
#include "Map.h"
#include "TextureManager.h"
#include "GameObject.h"



//////////////////////////////////////////////
// Constants and initialising//

Unit* ship4;

//////////////////////////////////////////////



// Constructor
Level::Level()
{
}

// Deconstructor
Level::~Level()
{
}

void Level::ChangeSpawn(int Sx, int Sy) {
	spawnX = Sx;
	spawnY = Sy;

}

// Initialise the Level
void Level::init(Unit* PC) {
	LevelID = 0;

	ship4 = new Unit("assets/Ship1_32x32.png", 2, 2);
	ship4->StatInit();
	//char1 = new GameObject("assets/Char1_32x32.png", 3 * TILESIZE, 0);
	LevelMap = new Map();
	//map3 = new Map();
	UM = new UnitManager();

	//cout << UM1->LevelObjects.size() << endl;

	// PC always placed as first item in Object Manager
	// TODO - rework function to ensure that it is first
	// i.e. use emplace or something
	UM->AddUnit(PC);
	UM->AddUnit(ship4);

	spawnX = 0;
	spawnY = 0;

}


// Event Handler
void Level::handleEvents() {

	if (UM->LevelUnits[0]->xpos == -1 && UM->LevelUnits[0]->ypos == -1) {
		UM->LevelUnits[0]->xpos = spawnX;
		UM->LevelUnits[0]->ypos = spawnY;

	}


	SDL_Event e;
	SDL_PollEvent(&e);

	// If X is clicked, close game
	if (e.type == SDL_QUIT)
	{
		isRunning = false;
		StateVar = -1;
	}

	// If there is a keypress, trigger an action
	else if (e.type == SDL_KEYDOWN) {
		int xposnext = 0;
		int yposnext = 0;
		// Get keyID
		switch (e.key.keysym.sym) {

			// Quit if Esc
		case SDLK_ESCAPE:
			StateVar = 0;
			isRunning = false;
			break;


			// Arrow Key Movement
		case SDLK_RIGHT:
			// Get next pos
			xposnext = UM->LevelUnits[0]->xpos + 1;
			yposnext = UM->LevelUnits[0]->ypos;
			break;
		case SDLK_LEFT:
			// Get next pos
			xposnext = UM->LevelUnits[0]->xpos - 1;
			yposnext = UM->LevelUnits[0]->ypos;
			break;
		case SDLK_DOWN:

			// Get next pos
			xposnext = UM->LevelUnits[0]->xpos;
			yposnext = UM->LevelUnits[0]->ypos + 1;
			break;
		case SDLK_UP:

			// Get next pos
			xposnext = UM->LevelUnits[0]->xpos;
			yposnext = UM->LevelUnits[0]->ypos - 1;
			break;

			// default do nothing
		default:
			break;
		}



		// Assume move is valid, the set false if not
		bool canMove = true;

		// Check xposnext and yposnext are not going negative
		if (xposnext < 0) {
			xposnext = 0;
		}

		if (yposnext < 0) {
			yposnext = 0;
		}

		//cout << UM->LevelUnits[0]->xpos << "|" << UM->LevelUnits[0]->ypos << endl;
		//cout << LevelMap->mapMatrix[1].size() << "|" << yposnext << endl;

		// Checking if move takes char outside of map range
		if (xposnext >= LevelMap->mapMatrix.size()-1) {
			xposnext = LevelMap->mapMatrix.size()-1;
		}
		if (yposnext >= LevelMap->mapMatrix[1].size()-1) {
			yposnext = LevelMap->mapMatrix[1].size()-1;
		}

		// Check for Game obj collisions
		for (size_t i = 0; i < UM->LevelUnits.size(); i++) {
			int xtemp = UM->LevelUnits[i]->xpos;
			int ytemp = UM->LevelUnits[i]->ypos;
			if (xposnext==xtemp && yposnext==ytemp && UM->LevelUnits[i]->canWalk==false) {
				canMove = false;
			}
		}

		// Check for obstructions with Map i.e. walls
		if (LevelMap->mapMatrix[xposnext][yposnext] == 2) {
			canMove = false;
		}
		

		// If the move is valid, then move
		if(canMove){

			cout << "move detected" << endl;
			UM->LevelUnits[0]->MoveObj(xposnext-UM->LevelUnits[0]->xpos, yposnext - UM->LevelUnits[0]->ypos);
		}

		// If the move took us onto an exit, move to next lvl 
		if (LevelMap->mapMatrix[xposnext][yposnext] == 3) {
			cout << "Next lvl case entered" << endl;
			UM->LevelUnits[0]->xpos = -1;
			UM->LevelUnits[0]->ypos = -1;
			//UM->LevelUnits[0]->loseHP(1);

			isRunning = false;
		}

	}


}




//
void Level::update() {

	for (size_t i = 0; i < UM->LevelUnits.size(); i++) {
		UM->LevelUnits[i]->Update();
	}

}


//
void Level::render() {

	// Clear renderer buffer
	SDL_RenderClear(WindowRenderer::renderer);

	// Stuff painted first goes to background, then after adds to foreground
	
	LevelMap->DrawMap();

	for (size_t i = 0; i < UM->LevelUnits.size(); i++) {
		UM->LevelUnits[i]->Render();
		UM->LevelUnits[i]->showHP();
	}

	// Draw HP of player
	//OM->LevelObjects[0]->showHP();

	// Show the rendered image
	SDL_RenderPresent(WindowRenderer::renderer);




}

