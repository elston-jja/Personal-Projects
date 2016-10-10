#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include "texture.h"
#include "sdlw.h"

Texture::Texture()
{
	HEIGHT = 0;
	WIDTH = 0;
	TEXTURE = NULL;
}

Texture::~Texture()
{
	//Deallocate
	free();
}

void Texture::free()
{
	if (TEXTURE != NULL)
	{
		SDL_DestroyTexture(TEXTURE);
	    TEXTURE = NULL;
		WIDTH = 0;
		HEIGHT = 0;
	}
}


bool Texture::loadImageFromFile(std::string path, SDL_Renderer* render)
{
	// Get rid of previous texture
	free();
	// Create the final Texture
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str());

	if (loadedSurface == NULL)
	{
		printf("The image could not be loaded %s| ERR: %s\n",path.c_str(),SDL_GetError());
		
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface( render, loadedSurface);

		if (newTexture == NULL)
		{
			printf("Failed to convert surface | ERR: %s", SDL_GetError());
			
		}
		else
		{
			WIDTH = loadedSurface->w;
			HEIGHT = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}

    TEXTURE = newTexture;
	return TEXTURE != NULL;
}

void Texture::render(int x, int y, SDL_Renderer* render)
{
	//Set render spaceing and render on the screen
	SDL_Rect renderQuad = { x, y, WIDTH, HEIGHT};
	SDL_RenderCopy(render,TEXTURE,NULL, &renderQuad);
}

int Texture::getWidth()
{
	return WIDTH;
}
int Texture::getHeight()
{
	return HEIGHT;
}
