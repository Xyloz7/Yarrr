#include "Button.h"



SDL_Texture* ButtonBackgroundSelected;

Button::Button(int xposition, int yposition, int w, int h, char* content, int GameStateID) {
	// Initialise button with screen position and dimensions
	xpos = xposition;
	ypos = yposition;
	bwidth = w;
	bheight = h;
	ButtonText = content;
	isSelected = false;
	isClicked = false;
	GameStateSendID = GameStateID;

	// Set ButtonBackground
	ButtonBackground = TextureManager::LoadTexture("assets/Button1_64x32.png");
	ButtonBackgroundSelected = TextureManager::LoadTexture("assets/Button2_64x32.png");

	// Create Button Rects
	src.x = src.y = 0;
	src.w = src.h = TILESIZE;

	dest.w = bwidth;
	dest.h = bheight;

	dest.x = xpos;
	dest.y = ypos;


	// Button word content
	TTF_Init();
	TTF_Font * font = TTF_OpenFont("assets/Font/OpenSans-Bold.ttf", 25);
	SDL_Color color = { 0, 0, 0 };
	SDL_Surface * surface = TTF_RenderText_Solid(font,
		ButtonText, color);

	ButtonTextTexture = SDL_CreateTextureFromSurface(WindowRenderer::renderer, surface);

	// Create smaller Text Rects
	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(ButtonTextTexture, NULL, NULL, &texW, &texH);
	TextSrc = { 0, 0, texW, texH };

}
Button::~Button() {}


void Button::RenderButton() {

	//std::cout << "Entered Button Render" << std::endl;
	// Function to Show the button
	if (isSelected) {
		TextureManager::Draw(ButtonBackgroundSelected, src, dest);
		TextureManager::Draw(ButtonTextTexture, TextSrc, dest);
	}
	else {
		TextureManager::Draw(ButtonBackground, src, dest);
		TextureManager::Draw(ButtonTextTexture, TextSrc, dest);
	}

}


void Button::ChangeButtonText(char* newcontent) {
	ButtonText = newcontent;
}


void Button::SelectButton() {
	isSelected = true;
}

void Button::deSelectButton() {
	isSelected = false;
}

void Button::ChangeGameState() {
	StateVar = GameStateSendID;
}