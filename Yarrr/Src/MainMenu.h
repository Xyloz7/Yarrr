#pragma once
#include "Level.h"
#include "StateManager.h"
#include "GameState.h"
#include "Button.h"

extern int StateVar;

class MainMenu : public GameState
{
public:
	MainMenu();
	~MainMenu();
	void init();
	void handleEvents();

	//void play(int FPS, int frameDelay, Uint32 frameStart, int frameTime);
	void update();
	void render();

	//bool running() { return isMainMenuRunning; }

protected:
	int CurrButton;

private:
	//bool isMainMenuRunning = true;

};