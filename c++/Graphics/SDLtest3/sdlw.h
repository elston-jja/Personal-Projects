#ifndef SDLW_H
#define SDLW_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>

//extern SDL_Renderer* Renderer;

class SDLWrapper
{
public:
	// Initializes all values to zero
	SDLWrapper();
	// Correctly destroys all pointers
	~SDLWrapper();

	// Load a window filled with white
	bool Window(int w, int h, int posX, int posY, Uint32 flags, const char* windowName , SDL_Surface* ss);
	// Load an image 
	void free();
	// Loads image from path
	bool loadImageFromFile(std::string path);
	// Deallocates the texture
	void freeTexture();
	// Draw the texture at a given spot
	void render(int x, int y);
	// Returns the width
	int getWidth();
	// Returns the height
	int getHeight();
	// Refresh the screen
	void refresh();

	// Get the Renderer surface
	SDL_Renderer* getRenderer();

	//clear the renderer
	void renderClear();

private:
				
	// Actual hardware texture
	SDL_Texture* TEXTURE;
    //Image Dimentions
	int WIDTH;
	int HEIGHT;
	// Render variable
	SDL_Renderer* RENDERER;
	// Window variable
	SDL_Window* WINDOW;
	
};






#endif
