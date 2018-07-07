# ifndef TEXTURE_H
# define TEXTURE_H

#include <string>



class Texture
{
public:
	// Initialize variables
	Texture();
	// Destroyer 
	~Texture();
	// Loads image from path
	bool loadImageFromFile(std::string path, SDL_Renderer* render);
	// Deallocates the texture
	void free();
	// Draw the texture at a given spot
	void render(int x, int y, SDL_Renderer* render);
	// Returns the value
	int getWidth();
	int getHeight();
private:
				
	// Actual hardware texture
	SDL_Texture* TEXTURE;
	//Image Dimentions
	int WIDTH;
	int HEIGHT;
};

#endif
