#include <stdio.h>
#include <stdint.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include "sdlw.h"

/*
 * This will help to utilize the SDL libraries with less hastle
 *
 * Created by: Elston A
 */

SDLWrapper::SDLWrapper()
{
	printf("Wrapper class loaded\n");
	RENDERER = NULL;
	WINDOW = NULL;
	TEXTURE = NULL;
}

SDLWrapper::~SDLWrapper()
{
	// Deallocate the window
	free();
	// Deallocate the texture
	freeTexture();
	IMG_Quit();
	SDL_Quit();
}

// Create a Window
bool SDLWrapper::Window(int w, int h, int posX, int posY, Uint32 flags, const char* windowName, SDL_Surface* ss)
{
	bool success = true;

	printf("Intialzing SDL modules\n");

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("The window could not be created | Err: %s\n", SDL_GetError());
	}
	else
	{
		if (posX <= -1)
			posX = SDL_WINDOWPOS_UNDEFINED;
		if (posY <= -1)
			posY = SDL_WINDOWPOS_UNDEFINED;
		
		WINDOW = SDL_CreateWindow( windowName, posX, posY, w, h, flags);

		if (WINDOW == NULL)
		{
			printf("Window could not be created | Err: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			printf("Initializing render surface\n");
			RENDERER = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_ACCELERATED);

			if (RENDERER == NULL)
			{
				printf("The renderer surface could not be created | Err: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				printf("Initializing image loading\n");
				SDL_SetRenderDrawColor(RENDERER, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;

				if (!(IMG_Init(imgFlags)&imgFlags))
				{
					printf("Imaging could not be initialized | IMG Err: %s n", IMG_GetError());
					success = false;
				}
				else
				{
					ss = SDL_GetWindowSurface(WINDOW);
				}
			}
		}
	}
	
	return success;
}

void SDLWrapper::free()
{
	if (WINDOW != NULL)
	{
		SDL_DestroyRenderer(RENDERER);
		RENDERER = NULL;
		SDL_DestroyWindow(WINDOW);
		WINDOW = NULL;
	}
}

void SDLWrapper::freeTexture()
{
	if (TEXTURE != NULL)
	{
		SDL_DestroyTexture(TEXTURE);
		TEXTURE = NULL;
		HEIGHT = 0;
		WIDTH = 0;
	}
}

bool SDLWrapper::loadImageFromFile(std::string path)
{
	// Get rid of previous texture
	freeTexture();
	// Create the final Texture
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str());

	if (loadedSurface == NULL)
	{
		printf("The image could not be loaded %s| ERR: %s\n",path.c_str(),SDL_GetError());
		
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface( RENDERER, loadedSurface);

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

void SDLWrapper::render(int x, int y)
{
	//Set render spaceing and render on the screen
	SDL_Rect renderQuad = { x, y, WIDTH, HEIGHT};
	SDL_RenderCopy(RENDERER,TEXTURE,NULL, &renderQuad);
}

int SDLWrapper::getWidth()
{
	return WIDTH;
}

int SDLWrapper::getHeight()
{
	return HEIGHT;
}

SDL_Renderer* SDLWrapper::getRenderer()
{
	return RENDERER;
}

void SDLWrapper::refresh()
{
	SDL_RenderPresent(RENDERER);
}


void SDLWrapper::renderClear()
{
	SDL_RenderClear(RENDERER);
}

void SDLWrapper::setColor(Uint8 R, Uint8 G, Uint8 B, Uint8 A)
{
	SDL_SetRenderDrawColor(RENDERER, R, G, B, A);
	
}

//bool SDLWrapper::isRightClick(void);
