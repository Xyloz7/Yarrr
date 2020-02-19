#pragma once

#include "Level.h"
#include "GameObject.h"

class Dungeon 
{
public:
	// Constructor
	Dungeon();

	// Deconstructor
	~Dungeon();

	void AddLevel(Level* ObjToAdd);
	void RemoveLevel(int pos);

	vector<Level* >DungeonLevels;

	int curr_level;

protected:


private:

};
