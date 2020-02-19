#pragma once

#include <SDL.h>
#include "SDL_image.h"
#include "WindowRenderer.h"


extern int TILESIZE;

class GameObject
{
public:
	GameObject();
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void Update();
	void Render();
	void MoveObj(int xmove, int ymove);
	int xpos, ypos;
	bool canWalk;

protected:
	// xpos, ypos should be co-ordinates, then multiply by 
	// TILESIZE to draw



	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
private:

};

