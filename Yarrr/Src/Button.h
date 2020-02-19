#pragma once
#include "Level.h"
#include "TextureManager.h"
#include <SDL_ttf.h>


extern int TILESIZE;
extern int StateVar;

class Button 
{
public:
	Button(int xposition, int yposition, int w, int h, char* content, int GameStateID);
	~Button();

	void RenderButton();
	void ChangeButtonText(char* newcontent);
	void SelectButton();
	void deSelectButton();
	void ChangeGameState();

protected:
	bool isSelected;
	bool isClicked;
	int xpos;
	int ypos;
	int bwidth;
	int bheight;
	int GameStateSendID;

	char* ButtonText;
	SDL_Texture* ButtonBackground;
	SDL_Texture* ButtonTextTexture;
	SDL_Rect src, dest, TextSrc;

private:



};
