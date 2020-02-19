#pragma once
#include <SDL.h>
#include "SDL_image.h"
#include <iostream>

// WindowRenderer is a class used to create a "global" window and renderer to be used by all other classes so that they
// draw to the same window and can use the same renderer


class WindowRenderer
{
public:
	WindowRenderer();
	~WindowRenderer();

	void WindowRendererInit(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);


	static SDL_Renderer *renderer;
	static SDL_Window *window;

private:


};

