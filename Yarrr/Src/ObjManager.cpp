#include "ObjManager.h"
#include <vector>


ObjManager::ObjManager()
{
	LevelObjects.clear();
}

ObjManager::~ObjManager()
{
}

void ObjManager::AddObj(GameObject* ObjToAdd) {
	// Resize vector so new object can be added
	LevelObjects.push_back( ObjToAdd);
}


void ObjManager::RemoveObj(int pos) {
	// Use erase to delete at specified position
	LevelObjects.erase(LevelObjects.begin() + pos);

}
