#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

void PrintGameboard(char **gameboard, int height, int width, bool print);

int main() {

  //Vars
  std::string splitstring, input_d, input_a, dimentions_s;
  int height, width, cellsalive, x, y;
  char **gameboard;
  std::vector<std::string>inputarray, alivecellsinput;

  std::cout << "Enter The Dimentions [WxH]: ";
  std::getline(std::cin, input_d);			    // Get the dimentions from the user as string
  std::stringstream stringbuf(input_d);			    // Create string buffer
  
  while (std::getline(stringbuf, splitstring, 'x')) {	    // Break input using a delimiter 
    inputarray.push_back(splitstring);			    // and push it into a string vector
  }
  height = std::stoi(inputarray[1]);			    // Assign height and width from the vector values
  width = std::stoi(inputarray[0]);
    
  gameboard = new char *[width];			    // Gamelist will point to width.
  for (int i = 0; i < width; i++) {                         // For each width value in the gameboard array point
    gameboard[i] = new char[height]; 			    // to the array of heights
  }							    

  std::cout << "How many cells are alive :";		    // Get the amount of cells alive
  std::cin >> cellsalive;
  std::cin.ignore();					    // Remove the \n so program can run using getline

  PrintGameboard(gameboard, height, width, false);	    // Set all the game tiles to dead or '~' and print

  for (int i = 0; i< cellsalive; i++) {
    std::cout << "Enter the " << i+1 << " coordinate [x,y]: "; // Asks for each cordinate    
    std::getline(std::cin, input_a);			    // Get the coordinate from the user
    std::stringstream stringbuf(input_a);		    // Copy the coordinate into the buffer

    while(std::getline(stringbuf, splitstring, ',')) {	    // Breaks string input using delimiter
      alivecellsinput.push_back(splitstring);		    // and pushes it into string vector
    }
    x = std::stoi(alivecellsinput[i*2]);		    // Assign the X and the Y values from the string vectors
    y = std::stoi(alivecellsinput[(i*2)+1]);
    
    if ( x -1 <= width  and  y -1 <= height ) {		    // Check if they are within range
	gameboard[x -1][y -1] = 'A';			    // change the value of the selected cells to 'A'
      }
  }
  std::cout << "The final playing board looks: \n\n";
  PrintGameboard(gameboard, height, width, true);	    // Only print the gameboard
  std::cout << "\n||Press enter to begin||";
  std::cin.ignore();

  
  
  for (int i = 0; i < width; i++) {			    // delete each pointer from pointer list before exit
    delete[] gameboard[i];
  }
  
  return 0;
}

void PrintGameboard(char **gameboard, int height, int width,bool print ) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (!print) {
      gameboard[x][y] = '-';
      }
      std::cout << gameboard[x][y] << " ";
    }
    std::cout << std::endl;
  } 
}
