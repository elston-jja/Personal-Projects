#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


// Starts up SDL and creates window
bool init();

// Loads media
bool loadmedia();

// Frees media and shuts down SDL
void close();

// Surface to render to
SDL_Window* gWindow = NULL;

// The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// The Image that will load on the screen
SDL_Surface* gHelloWorld = NULL;

/* Functions */

bool init() {
  // Initialization flag
  bool success = true;

  // Initialize SDL
  if (SDL_Init( SDL_INIT_VIDEO ) < 0) {

    printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
    success = false;
  }
  else {

    // Create Window
    gWindow = SDL_CreateWindow("Basic Graphics", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (gWindow == false) {
      printf("Window could not be created! SDL_ERROR: %s\n", SDL_GetError() );
      success = false;
    }
    else {
      
      // Get window surface
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }
  return success;
}

bool loadMedia() {

  // Loading success flag
  bool success = true;

  //Load splash image

  gHelloWorld = SDL_LoadBMP("hello_world.bmp");
  if (gHelloWorld == NULL){
    printf(" Unable to load image! SDL_ERROR: %s \n", SDL_GetError());
    success = false;
  }
  
  return success;
}

void close() {

  // Deallocate surface
  SDL_FreeSurface(gHelloWorld);
  gHelloWorld = NULL;

  // Destroy window
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;

  // Quit();
  SDL_Quit();
}

int main(int argc, char *argv[])
{

  // Startup SDL and Create window
  if (!init()){
    printf("Failed to initialize!\n");
  }
  else {
    //Load meida
    if (!loadMedia()) {
      printf("Failed to load media\n");
    }
    else{
      // Apply the image
      SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

      // Update the surface
      SDL_UpdateWindowSurface(gWindow);

      // Wait before closing

      SDL_Delay( 2000 );
    }
  }

  // Free resources and close SDL
  close();
  
  return 0;
}
