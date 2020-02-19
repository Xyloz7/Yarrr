#include "TextureManager.h"
#include <iostream>
#include "WindowRenderer.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	if (!IMG_Load(texture)) {
		std::cout << "Error, could not load texture" << std::endl;
	}
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(WindowRenderer::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(WindowRenderer::renderer, tex, &src, &dest);
}

