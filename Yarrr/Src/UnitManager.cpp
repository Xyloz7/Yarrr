#include "UnitManager.h"
#include <vector>


UnitManager::UnitManager()
{
	LevelUnits.clear();
}

UnitManager::~UnitManager()
{
}

void UnitManager::AddUnit(Unit* ObjToAdd) {
	// Resize vector so new object can be added
	LevelUnits.push_back(ObjToAdd);
}


void UnitManager::RemoveUnit(int pos) {
	// Use erase to delete at specified position
	LevelUnits.erase(LevelUnits.begin() + pos);

}
