#include "Dungeon.h"

//////////////////////////////////////////////
// Constants and initialising//
//////////////////////////////////////////////



// Constructor
Dungeon::Dungeon()
{
	curr_level = 1;
}

// Deconstructor  
Dungeon::~Dungeon()
{
}


void Dungeon::AddLevel(Level* ObjToAdd) {
	// Resize vector so new object can be added
	DungeonLevels.push_back(ObjToAdd);
}


void Dungeon::RemoveLevel(int pos) {
	// Use erase to delete at specified position
	DungeonLevels.erase(DungeonLevels.begin() + pos);

}

int Dungeon::get_curr_level() {
	// Use erase to delete at specified position
	return curr_level;
}
