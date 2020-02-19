#include "WindowRenderer.h"

SDL_Window* WindowRenderer::window = nullptr;
SDL_Renderer* WindowRenderer::renderer = nullptr;

WindowRenderer::WindowRenderer()
{
}


WindowRenderer::~WindowRenderer()
{
}

void WindowRenderer::WindowRendererInit(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialised..." << std::endl;

		// Create Window
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// Check window creation
		if (window) {
			std::cout << "Window Created!" << std::endl;
		}

		// Create Renderer
		renderer = SDL_CreateRenderer(window, -1, 0);

		// Check renderer creation
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 122, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}
	}

}