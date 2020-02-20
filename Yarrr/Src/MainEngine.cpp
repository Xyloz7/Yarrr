#include "Dungeon.h"
#include "MainMenu.h"
#include "StateManager.h"


// CONSTANTS //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Window Dimensions
const int WIDTH = 960;
const int HEIGHT = 640;

// Framerate Initialisation
const int FPS = 60; // Declare Framerate
const int frameDelay = 1000 / FPS; // How long frame should take, max time between frames
Uint32 frameStart;
int frameTime;

// Game declaration
MainMenu *Menu1 = nullptr;
Dungeon* dungeon1 = nullptr;
Level *level1 = nullptr;
Level *level2 = nullptr;
Level *level3 = nullptr;

GameObject *PC1 = nullptr;

vector<vector<int> > lvl2_vect = {
	{ 2,1,0,1,0,1,2,1,0,1, 2 },
	{ 2,0,1,0,1,0,3,0,1,0,2 },
	{ 2,1,0,1,0,1,0,1,0,1,2 },
	{ 2,0,1,0,1,0,1,0,1,0,2 },
	{ 2,1,0,1,0,1,0,1,0,1,2 },
	{ 2,0,1,0,1,0,1,0,1,0,2 }
};

vector<vector<int> > lvl3_vect = {
	{ 2,1,1,1,1,1,2,1,1,1, 2 },
	{ 2,1,1,1,1,1,1,1,1,1,2 },
	{ 2,1,1,1,1,1,0,3,0,1,2 },
	{ 2,0,1,0,1,0,1,0,1,0,2 },
	{ 2,1,0,1,0,1,0,1,0,1,2 },
	{ 2,0,1,0,1,0,1,0,1,0,2 }
};

// Window 
WindowRenderer *WR;

// States
//StateManager *SM;

// State Variable - 0 = menu, 1 = game, 2 = Level
int StateVar = 0;
int TILESIZE = 64;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(int argc, char *args[]) {

	// Initialise window and renderer
	WR = new WindowRenderer();
	WR->WindowRendererInit("Yarr", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);

	// Create Player
	PC1 = new GameObject("assets/Char1_32x32.png", 1, 1);

	// Create Main Menu and initialise
	Menu1 = new MainMenu();
	Menu1->init();

	// Create new game and initialise it
	dungeon1 = new Dungeon;

	// Creating some levels
	level1 = new Level();
	level1->init(PC1);

	level2 = new Level();
	level2->init(PC1);
	level2->LevelMap->LoadMap(lvl2_vect);

	level3 = new Level();
	level3->init(PC1);
	level3->LevelMap->LoadMap(lvl3_vect);
	level3->ChangeSpawn(5, 5);

	dungeon1->AddLevel(level1);
	dungeon1->AddLevel(level2);
	dungeon1->AddLevel(level3);

	// initialising curr_level counter
	int curr = 0;
	
	// Checking game state - main menu, or dungeon
	while (StateVar>=0) {
		
		switch (StateVar) {

		// Case 0 = Main Menu
		case 0:
			Menu1->play(FPS, frameDelay, frameStart, frameTime);
			break;
		case 1:
			level1->play(FPS, frameDelay, frameStart, frameTime);
			break;

		// Case 2 = Dungeon
		case 2:
			// Curr_level starts at 0. 
			// Run Curr_level, if accessible
			if (curr < dungeon1->DungeonLevels.size()) {
				dungeon1->DungeonLevels[curr]->play(FPS, frameDelay, frameStart, frameTime);
			
			// Upon exiting the level, increase counter to go
			// to next lvl
				curr += 1;
			}

			// If inaccessible, return to main menu and 
			// reset curr_level to 0
			else { 
				StateVar = 0;
				curr = 0;
			}

			break;
		case 3:
			return 0; 
			break;

		default:
			std::cout << "Default StateVar message" << std::endl;
			return 4;
			break;
		}
	}



	// Clear when done
	SDL_DestroyWindow(WindowRenderer::window);
	SDL_DestroyRenderer(WindowRenderer::renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;


	// Exit
	return 0;
}