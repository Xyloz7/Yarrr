#include "GameObject.h"
#include"TextureManager.h"

// Overload constructor, allow for zero creation
GameObject::GameObject()
{
}


// Constructor takes texture, and position
// Assumes TILESIZE dimensions - TODO change from 2*h to TILESIZE
GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	// REPLACE  with TILESIZE
	xpos = x;
	ypos = y;

	// Source Rectangle
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	// Destination Rectangle
	destRect.h = TILESIZE;
	destRect.w = TILESIZE;

	canWalk = false;
}

// Function to move the object
void GameObject::MoveObj(int xmove, int ymove) {
	// Find matrix co-ord
	// Check if there is an object there
	// If not, move
	xpos = xpos + xmove;
	ypos = ypos + ymove;
}


void GameObject::Update() 
{
	destRect.x = xpos*TILESIZE;
	destRect.y = ypos*TILESIZE;
}

void GameObject::Render()
{
	SDL_RenderCopy(WindowRenderer::renderer, objTexture, &srcRect, &destRect);
}

GameObject::~GameObject()
{
}
