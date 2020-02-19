#pragma once

#include "WindowRenderer.h"
#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "GameState.h"


extern int StateVar;
using namespace std;


class ObjManager
{
public:
	ObjManager();
	~ObjManager();

	void AddObj(GameObject* ObjToAdd);
	void RemoveObj(int pos);
	vector<GameObject* >LevelObjects;
	

protected:
	
private:


};