#include "GameState.h"


//////////////////////////////////////////////
// Constants and initialising//
extern int TILESIZE;
//////////////////////////////////////////////



// Constructor
GameState::GameState()
{
}

// Deconstructor
GameState::~GameState()
{
}


// Initialise the ShipGame
void GameState::init() {

}


// Game Loop
void GameState::play(int FPS, int frameDelay, Uint32 frameStart, int frameTime) {

	isRunning = true;
	while (isRunning) {
		frameStart = SDL_GetTicks();
		handleEvents(); 
		update();
		render();

		frameTime = SDL_GetTicks() - frameStart; // Time to handle events, update and render
												 // If delay > time then we should delay frame display to keep it at 60 FPS
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}

// Event Handler
void GameState::handleEvents() {
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
	
	}


}




//
void GameState::update() {

}


//
void GameState::render() {




}


