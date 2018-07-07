# ifndef TEXTURE_H
# define TEXTURE_H

#include <string>

class LTexture
{
public:
	//Initializes variables
	LTexture();

    //Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool loadFromFile( std::string path);

	//Deallocates texture
	void free();
	
	//Renders textures @ a given point
	void render(int x, int y);

	//Gets width and dimentions
	int getWidth();
	int getHeight();

private:

	// Actual hardware texture
	SDL_Texture* mTexture;

	//Image dimentions
	int mWidth;
	int mHeight;
	
};

#endif
