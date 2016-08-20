#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>

class PopulateSquares {
private:
  std::string input;
  std::string item;
  int length;
  int width;
   
public: 
  std::vector<std::string>dimentions;		             // Vector to allocate dimentions. Only 0 and 1. used for length 
  void GetDimentions();					     // and width
  int GetArea() { return int (length)*(width) ;}
  int GetLength() { return int (length); }
  int GetWidth() { return int (width); }
};

void PopulateSquares::GetDimentions() {

  std::cout << "Enter the dimentions [LxW]: ";
  std::cin >> input;

  std::stringstream inp(input);				    // Sets up a string buffer

  while( std::getline(inp, item, 'x') ){		    // Break the input using the delimiter char 'x' 
    dimentions.push_back(item);				    // Saves the broken string as strings in a vector array
  }
  length = std::stoi(dimentions[1]);			    // Sets the length and the width by calling the first and second
  width = std::stoi(dimentions[0]);			    // From the array
}

class Gameboard {
private:
  int rows;
  int columbs;
  char gameboard;
public:
  Gameboard (int width, int length) : rows(width) , columbs(length) {char gameboard[columbs][rows];}
  char GetGameboard() {return gameboard ;}

};

template<int numberOfRows, int numberOfColumns>
void PrintGameboard(int (&theArray)[numberOfRows][numberOfColumns])
{
  for(int x = 0; x < numberOfRows; x++){
    for(int y = 0; y < numberOfColumns; y++){
      std::cout << theArray[x][y] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {

  int length;
  int width;
  char gameboard;
  
  PopulateSquares squares;
  squares.GetDimentions();

  length = squares.GetLength();				    // Set the values for the length and width of the array
  width = squares.GetWidth();

  std::cout <<  "Columbs: " << width << " Rows: " << length << std::endl; // Debugging

  Gameboard Tiles(length, width);
  gameboard = Tiles.GetGameboard();
  PrintGameboard(gameboard);

  return 0;
}
