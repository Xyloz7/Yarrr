#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "WindowRenderer.h"
#include <SDL.h>
#include "SDL_image.h"
/*#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include <vector> 
*/

extern int StateVar;

class GameState
{
public:
	// Constructor
	GameState();

	// Deconstructor
	~GameState();

	// Initialise
    virtual void init();
	virtual void handleEvents();

	/////////////////////////////////////////////////////////////////////////
	// Only non virtual func atm
	void play(int FPS, int frameDelay, Uint32 frameStart, int frameTime);
	/////////////////////////////////////////////////////////////////////////

	virtual void update();
	virtual void render();

	bool running() { return isRunning; }

	//static SDL_Renderer *renderer;

protected:
	bool isRunning = false;
private:



};

#endif // GAMESTATE_H