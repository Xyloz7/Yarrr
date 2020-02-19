#include "MainMenu.h"
#include "TextureManager.h"
#include "Map.h"

// Values
const int ButtonNo = 3;

//Map* map2;
Button* button1;
Button* button2;
Button* ButtonArr[ButtonNo];


MainMenu::MainMenu() {

}

MainMenu::~MainMenu() {}

// Initialise
void MainMenu::init() {
	//map2 = new Map();

	CurrButton = -1;

	ButtonArr[0] = new Button(300, 200, 128, 64, "Start", 1);
	ButtonArr[1] = new Button(300, 300, 128, 64, "Level", 2);
	ButtonArr[2] = new Button(300, 400, 128, 64, "Exit", 3);
}

//
void MainMenu::update() {
}

//
void MainMenu::render() {	
	// Clear renderer buffer
	SDL_RenderClear(WindowRenderer::renderer);


	// Stuff painted first goes to background, then after adds to foreground
	//map2->DrawMap();

	for(int i=0;i<ButtonNo ;i++){
		ButtonArr[i]->RenderButton();
	}


	// Show the rendered image
	SDL_RenderPresent(WindowRenderer::renderer);
}


// Event Handler
void MainMenu::handleEvents() {
	SDL_Event e;
	SDL_PollEvent(&e);

	// If X is clicked, close game
	if (e.type == SDL_QUIT)
	{
		isRunning = false;
		StateVar = -1;
	}

	// If there is a keypress, trigger an action
	else if (e.type == SDL_KEYDOWN) {
		// Get keyID
		switch (e.key.keysym.sym) {

			// Quit if Esc
		case SDLK_ESCAPE:
			break;

		case SDLK_SPACE:
			// Go to ShipGame gamestate if space is pressed
			// StateVar = 1;
			//ButtonArr[CurrButton]->ChangeGameState();
			//isRunning = false;
			break;

			// Arrow Key Movement
		case SDLK_RIGHT:
			break;
		case SDLK_LEFT:
			break;
		case SDLK_DOWN:
			// Deselect the current Button
			if (CurrButton >= 0) {
				ButtonArr[CurrButton]->deSelectButton();
			}
			
			// Move down list of buttons
			CurrButton = (CurrButton+1)%ButtonNo;

			// Select new current Button
			ButtonArr[CurrButton]->SelectButton();

			break;
		case SDLK_UP:
			// Deselect the current Button
			if (CurrButton >= 0) {
				ButtonArr[CurrButton]->deSelectButton();
			}

			// Move down list of buttons
			CurrButton = (CurrButton - 1);

			// If negative, reset to last button
			if (CurrButton < 0){
				CurrButton = ButtonNo-1;
			}


			// Select new current Button
			ButtonArr[CurrButton]->SelectButton();

			break;

		case SDLK_RETURN:
			// Enter changes GameState based on button and closes mainmenu
			//std::cout << "Enter recognised" << std::endl;
			ButtonArr[CurrButton]->ChangeGameState();
			isRunning = false;
			break;
			// default do nothing
		default:
			break;
		}
	}

}
