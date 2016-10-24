#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include "sdlw.h"

SDL_Surface* surface;
SDLWrapper sdl;

bool loadImage();

int main()
{
	bool quit = false;
	SDL_Event e;

	sdl.Window( 640, 480, -1, -1, 0,"test", surface);

	if (! (loadImage()))
	{
		printf("Could not load image");
		quit = true;
	}
	
	while (!quit)
	{
		// Check if event
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
				SDL_Log("Mouse Button 1 (left) is pressed.");
			}

		}
		
	    sdl.setColor(0xFF,0xFF,0xFF,0xFF);		
		sdl.renderClear();
		
		sdl.refresh();
		
	}
	return 0;
}

bool loadImage()
{
	bool success = true;
		if (!sdl.loadImageFromFile("texture.png"))
		{
			printf("The image could not be loaded\n");
			success = false;
		}
		return success;
}
