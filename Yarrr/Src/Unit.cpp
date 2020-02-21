
#include "Unit.h"
#include "TextureManager.h"
#include <SDL_ttf.h>


Unit::Unit()
{
}

// Constructor takes texture, and position
// Assumes TILESIZE dimensions - TODO change from 2*h to TILESIZE
Unit::Unit(const char* texturesheet, int x, int y)
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

void Unit::StatInit() {
	maxHP = 10;
	curr_HP = maxHP-2;
	ATK = 6;
	DEF = 5;
}

void Unit::showHP() {

	SDL_Texture* HPTexture = TextureManager::LoadTexture("assets/RedTile_32x32.png");
	SDL_Texture* currHPTexture = TextureManager::LoadTexture("assets/GreenTile_32x32.png");

	SDL_Rect HPsrc, HPdest, currHPdest;
	// Source Rectangle
	HPsrc.h = 32;
	HPsrc.w = 32;
	HPsrc.x = 0;
	HPsrc.y = 0;

	// max HP
	HPdest.h = 10;
	HPdest.w = TILESIZE;
	HPdest.x = xpos*TILESIZE;
	HPdest.y = ypos*TILESIZE - TILESIZE/3;
	SDL_RenderCopy(WindowRenderer::renderer, HPTexture, &HPsrc, &HPdest);

	// current HP
	currHPdest.h = 10;
	currHPdest.w = (TILESIZE*curr_HP) / maxHP;
	currHPdest.x = xpos*TILESIZE;
	currHPdest.y = ypos*TILESIZE - TILESIZE / 3;
	SDL_RenderCopy(WindowRenderer::renderer, currHPTexture, &HPsrc, &currHPdest);


}

void Unit::loseHP(int damage) {
	curr_HP -= damage;
}