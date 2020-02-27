#pragma once
class Unit;

#include "WindowRenderer.h"
#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include "Unit.h"
#include "GameState.h"


extern int StateVar;
using namespace std;


class UnitManager
{
public:
	UnitManager();
	~UnitManager();

	void AddUnit(Unit* ObjToAdd);
	void RemoveUnit(int pos);
	vector<Unit* >LevelUnits;


protected:

private:


};