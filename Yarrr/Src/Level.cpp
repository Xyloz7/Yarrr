#include "Level.h"
#include "ObjManager.h"
#include "GameState.h"
#include "Map.h"
#include "TextureManager.h"
#include "GameObject.h"



//////////////////////////////////////////////
// Constants and initialising//
GameObject* ship3;
GameObject* ship4;


//ObjManager* OM1;

//////////////////////////////////////////////



// Constructor
Level::Level()
{
}

// Deconstructor
Level::~Level()
{
}


// Initialise the Level
void Level::init() {

	ship3 = new GameObject("assets/Char1_32x32.png", 1, 1);
	ship4 = new GameObject("assets/Ship1_32x32.png", 2, 2);
	//char1 = new GameObject("assets/Char1_32x32.png", 3 * TILESIZE, 0);
	LevelMap = new Map();
	//map3 = new Map();
	OM = new ObjManager();

	//cout << OM1->LevelObjects.size() << endl;
	OM->AddObj(ship4);
	OM->AddObj(ship3);

	/*cout << "Message 1" << endl;
	cout << ship4->xpos << endl;
	cout << OM1->LevelObjects[0]->xpos << endl;
	*/
}


// Event Handler
void Level::handleEvents() {
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
			xposnext = ship3->xpos + 1;
			yposnext = ship3->ypos;
			break;
		case SDLK_LEFT:
			// Get next pos
			xposnext = ship3->xpos - 1;
			yposnext = ship3->ypos;
			break;
		case SDLK_DOWN:

			// Get next pos
			xposnext = ship3->xpos;
			yposnext = ship3->ypos + 1;
			break;
		case SDLK_UP:

			// Get next pos
			xposnext = ship3->xpos;
			yposnext = ship3->ypos - 1;
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

		cout << LevelMap->mapMatrix.size() << "|" << xposnext << endl;
		cout << LevelMap->mapMatrix[1].size() << "|" << yposnext << endl;

		// Checking if move takes char outside of map range
		if (xposnext >= LevelMap->mapMatrix.size()-1) {
			xposnext = LevelMap->mapMatrix.size()-1;
		}
		if (yposnext >= LevelMap->mapMatrix[1].size()-1) {
			yposnext = LevelMap->mapMatrix[1].size()-1;
		}

		// Check for Game obj collisions
		for (size_t i = 0; i < OM->LevelObjects.size(); i++) {
			int xtemp = OM->LevelObjects[i]->xpos;
			int ytemp = OM->LevelObjects[i]->ypos;
			if (xposnext==xtemp && yposnext==ytemp && OM->LevelObjects[i]->canWalk==false) {
				canMove = false;
			}
		}

		// Check for obstructions with Map i.e. walls
		if (LevelMap->mapMatrix[xposnext][yposnext] == 2) {
			canMove = false;
		}
		
		// If the move is valid, then move
		if(canMove){
			ship3->MoveObj(xposnext-ship3->xpos, yposnext - ship3->ypos);
		}
	}


}




//
void Level::update() {


	for (size_t i = 0; i < OM->LevelObjects.size(); i++) {
		OM->LevelObjects[i]->Update();
	}

}


//
void Level::render() {

	// Clear renderer buffer
	SDL_RenderClear(WindowRenderer::renderer);

	// Stuff painted first goes to background, then after adds to foreground
	LevelMap->DrawMap();

	for (size_t i = 0; i < OM->LevelObjects.size(); i++) {
		OM->LevelObjects[i]->Render();
	}

	// Show the rendered image
	SDL_RenderPresent(WindowRenderer::renderer);




}


