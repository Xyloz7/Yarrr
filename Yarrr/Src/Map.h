#pragma once

#include <vector>
#include "TextureManager.h"


extern int TILESIZE;


using namespace std;

class Map 
{
public:
	Map();
	~Map();

	void LoadMap(vector<vector<int> > inputMapMatrix);
	void DrawMap();

	vector<vector<int> > mapMatrix;
protected:


private:
	SDL_Rect src, dest;

	SDL_Texture* yellow;
	SDL_Texture* white;
	SDL_Texture* grey;


};