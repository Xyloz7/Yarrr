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
#include "UnitManager.h"
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
	void init(Unit* PC);
	void handleEvents();

	//void play(int FPS, int frameDelay, Uint32 frameStart, int frameTime);
	void update();
	void render();

	// Changes the spawn in co-ord
	void ChangeSpawn(int Sx, int Sy);
	void AddUnit(Unit* U);

	Map* LevelMap;
protected:
	int spawnX;
	int spawnY;
	ObjManager* OM;
	UnitManager* UM;
	int LevelID;

private:

};

#endif //Level_h