#ifndef Level_h
#define Level_h

#include <iostream>
#include <SDL.h>
#include "SDL_image.h"
#include "WindowRenderer.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "GameState.h"
#include "ObjManager.h"
#include "Map.h"



extern int StateVar;


class Level : public GameState
{
public:
	// Constructor
	Level();

	// Deconstructor
	~Level();

	// Initialise
	void init(GameObject* PC);
	void handleEvents();

	//void play(int FPS, int frameDelay, Uint32 frameStart, int frameTime);
	void update();
	void render();

	Map* LevelMap;
protected:

	ObjManager* OM;
	int LevelID;

private:

};

#endif //Level_h