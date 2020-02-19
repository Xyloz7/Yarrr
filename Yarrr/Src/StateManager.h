#pragma once

#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include "MainMenu.h"


// StateManager is used to store "global" state variable enum and change between menus, games etc.


class StateManager
{
public:
	StateManager();
	~StateManager();

	void StateManagerInit();


	static enum states { Menu, ShipGame1 };
	states current_state;

private:
	//MainMenu *Menu1;
	//ShipGame *ShipGame1;
};

