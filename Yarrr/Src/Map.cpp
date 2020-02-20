#include "Map.h"



using namespace std;


vector<vector<int> > lvl1_vect = {
	{ 2,1,0,1,0,1,2,1,0,1, 2 },
	{ 2,0,1,0,1,0,1,0,1,0,2 },
	{ 2,1,0,1,0,1,0,1,0,1,2 },
	{ 2,0,3,0,1,0,1,0,1,0,2 },
	{ 2,1,0,1,0,1,0,1,0,1,2 },
	{ 2,0,1,0,1,0,1,0,1,0,2 },
	{ 0,1,0,1,0,1,0,1,0,1,2 },
	{ 1,0,1,0,1,0,2,0,1,0,2 },
	{ 0,1,0,1,0,1,0,1,0,1,2 },
	{ 1,0,1,0,1,0,1,0,1,0,2 },
	{ 0,1,0,1,0,1,0,4,0,1,2 },
	{ 1,0,1,0,1,0,1,0,1,0,2 },
	{ 0,1,0,1,0,1,0,1,0,1,2 },
	{ 1,0,1,0,1,0,1,0,1,0,2 },
	{ 0,1,0,1,0,1,0,1,0,1,2 }
};



Map::Map() {
	yellow = TextureManager::LoadTexture("assets/YellowTile_32x32.png");
	white = TextureManager::LoadTexture("assets/WhiteTile_32x32.png");
	grey = TextureManager::LoadTexture("assets/GreyTile_32x32.png");
	green = TextureManager::LoadTexture("assets/GreenTile_32x32.png");
	blue = TextureManager::LoadTexture("assets/LightBlueTile_32x32.png");


	// Load default Map
	LoadMap(lvl1_vect);

	src.x = src.y = 0;
	src.w = src.h = 32;

	dest.w = TILESIZE;
	dest.h = TILESIZE;

	dest.x = dest.y = 0;
}

Map::~Map() {}

void Map::LoadMap(vector<vector<int> > inputMapMatrix)
{
	// Clear Matrix
	mapMatrix.clear();
	// Resize it to be same as inputMapMatrix
	// TODO - If using jagged arrays instead of square matrix
	// Then loop through each and resize accordingly rather
	// than using resize.
	mapMatrix.resize(inputMapMatrix.size(), vector<int>(inputMapMatrix[1].size(), -1));


	// Loop through input array and set map values equal to it.
	for (int row=0;row<inputMapMatrix.size();row++)
	{
		for (int col = 0; col<inputMapMatrix[row].size(); col++)
		{
			mapMatrix[row][col] = inputMapMatrix[row][col];
		}
	}

}

void Map::DrawMap() 
{
	int type = 0;
	// Loop through map and render
	for (int row = 0; row<mapMatrix.size(); row++)
	{
		for (int col = 0; col<mapMatrix[row].size(); col++)
		{
			type = mapMatrix[row][col];
			dest.x = row * TILESIZE;
			dest.y = col * TILESIZE;


			switch (type) {

			case 0:
				TextureManager::Draw(yellow, src, dest);
				break;
			case 1:
				TextureManager::Draw(white, src, dest);
				break;
			case 2:
				TextureManager::Draw(grey, src, dest);
				break;
			case 3:
				TextureManager::Draw(green, src, dest);
				break;
			case 4:
				TextureManager::Draw(blue, src, dest);
				break;
			default:
				break;
			
			}
				
		}
	}

}