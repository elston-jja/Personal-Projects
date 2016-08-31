#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

/*
  Game of Life [V 0.1]
  
  By: Elston A.
  Created by: John Conway
  Date 'finished': Aug 21, 2016
  
  RULES

  **For each cell that is 'populated'

  Each cell with one or no neighbors dies, as if by solitude. 
  Each cell with four or more neighbors dies, as if by overpopulation. 
  Each cell with two or three neighbors survives. 

  **For a space that is 'empty' or 'unpopulated'

  Each cell with three neighbors becomes populated. 

*/

void PrintGameboard(char **gameboard, int height, int width, bool print);
int CheckNeighbours(char **gameboard, int x, int y, int width, int height);

int main() {

  //Vars
  std::string splitstring, input_d, input_a, dimentions_s;
  int height, width, cellsalive, x, y, neighbours, turn, endturn;
  char **gameboard; bool running;
  std::vector<std::string>inputarray, alivecellsinput;

  std::cout << "Enter The Dimentions [WxH]: ";
  std::getline(std::cin, input_d);			    // Get the dimentions from the user as string
  std::stringstream stringbuf(input_d);			    // Create string buffer
  
  while (std::getline(stringbuf, splitstring, 'x')) {	    // Break input using a delimiter 
    inputarray.push_back(splitstring);			    // and push it into a string vector
  }
  height = std::stoi(inputarray[1]) +1;			    // Assign height and width from the vector values
  width = std::stoi(inputarray[0])  +1;
  
  gameboard = new char *[width];			    // Gamelist will point to width.
  for (int i = 0; i < width; i++) {                         // For each width value in the gameboard array point
    gameboard[i] = new char[height]; 			    // to the array of heights
  }							    
  
  std::cout << "How many turns to play: ";		    // Turns to end the main game loop
  std::cin >> endturn;  
  std::cout << "How many cells are alive: ";		    // Get the amount of cells alive
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
    
    if ( x <= width  and  y <= height ) {		    // Check if they are within range
      gameboard[x][y] = 'A';			    // change the value of the selected cells to 'A'
    }
  }
  std::cout << "The final playing board looks: \n\n";
  PrintGameboard(gameboard, height, width, true);	    // Only print the gameboard
  running = true;
  turn = 0;
  while (running) {
    
    for ( y = 0; y < height ; y++) {
      for ( x = 0; x < width ; x++) {
	if (gameboard[x][y] == 'A') {
	  neighbours = CheckNeighbours(gameboard, x, y, width - 1, height - 1); // Returns the # of cell neighbours
	  if (neighbours < 2 or neighbours >= 4) {
	    gameboard[x][y] = '-';
	  }
	}
	else {
	  neighbours = CheckNeighbours(gameboard, x, y, width - 1, height - 1);
	  if (neighbours == 3) {
	    gameboard[x][y] = 'A';
	  }
	}
      }
    }
    PrintGameboard(gameboard, height, width, true);	    // Only print the gameboard
    std::cout << "--- turn " << turn + 1 << " ---\n"; 
    turn++;
    if (turn == endturn){running = false; }
  }
  
  for (int i = 0; i < width; i++) {			    // delete each pointer from pointer list before exit
    delete[] gameboard[i];
  }
  return 0;
}

// Print out the name of the Gameboard
void PrintGameboard(char **gameboard, int height, int width,bool print ) {
  std::cout << std::endl;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (!print) {
      gameboard[x][y] = '-';
      }
      std::cout << gameboard[x][y] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// Multitude of If statements to return the number of neighbours
int CheckNeighbours(char **gameboard, int x, int y, int width, int height) { 
  int NeighboursFound = 0;
  
  if ( x != 0 and y != 0 and x != width and y != height) {
    if (gameboard[x+1][y+1] == 'A') { NeighboursFound++; }
    if (gameboard[x+1][y-1] == 'A') { NeighboursFound++; }
    if (gameboard[x-1][y+1] == 'A') { NeighboursFound++; }
    if (gameboard[x-1][y-1] == 'A') { NeighboursFound++; }
    if (gameboard[x][y-1] == 'A')   { NeighboursFound++; }
    if (gameboard[x][y+1] == 'A')   { NeighboursFound++; }
    if (gameboard[x-1][y] == 'A')   { NeighboursFound++; }
    if (gameboard[x+1][y] == 'A')   { NeighboursFound++; } 
  }  
  else if (x == 0 and y !=0 and y != height) {
    if (gameboard[x+1][y+1] == 'A') { NeighboursFound++; }
    if (gameboard[x+1][y-1] == 'A') { NeighboursFound++; }
    if (gameboard[x][y-1] == 'A')   { NeighboursFound++; }
    if (gameboard[x][y+1] == 'A')   { NeighboursFound++; }
    if (gameboard[x+1][y] == 'A')   { NeighboursFound++; }
  }
  else if (y == 0 and x != 0 and x != width) {
    if (gameboard[x+1][y+1] == 'A') { NeighboursFound++; }
    if (gameboard[x-1][y+1] == 'A') { NeighboursFound++; }
    if (gameboard[x-1][y] == 'A')   { NeighboursFound++; }
    if (gameboard[x+1][y] == 'A')   { NeighboursFound++; }
    if (gameboard[x][y+1] == 'A')   { NeighboursFound++; }
  }
  else if (y == height and x != width and x != 0) {
    if (gameboard[x+1][y-1] == 'A') { NeighboursFound++; }
    if (gameboard[x-1][y-1] == 'A') { NeighboursFound++; }
    if (gameboard[x-1][y] == 'A')   { NeighboursFound++; }
    if (gameboard[x+1][y] == 'A')   { NeighboursFound++; }
    if (gameboard[x][y-1] == 'A')   { NeighboursFound++; }
  }
  else if (x == width and y != height and y != 0){
    if (gameboard[x-1][y+1] == 'A') { NeighboursFound++; }
    if (gameboard[x-1][y-1] == 'A') { NeighboursFound++; }
    if (gameboard[x][y+1] == 'A')   { NeighboursFound++; }
    if (gameboard[x][y-1] == 'A')   { NeighboursFound++; }
    if (gameboard[x-1][y] == 'A')   { NeighboursFound++; }
  }
  else if (x == 0 and y == 0) {
    if (gameboard[x+1][y+1] == 'A') { NeighboursFound++; }
    if (gameboard[x+1][y] == 'A')   { NeighboursFound++; }
    if (gameboard[x][y+1] == 'A')   { NeighboursFound++; }
  }
  else if (x == width and y == height){
    if (gameboard[x-1][y-1] == 'A') { NeighboursFound++; }
    if (gameboard[x-1][y] == 'A')   { NeighboursFound++; }
    if (gameboard[x][y-1] == 'A')   { NeighboursFound++; }
  }
  else if (x == 0 and y == height) {
    if (gameboard[x+1][y-1] == 'A') { NeighboursFound++; }
    if (gameboard[x+1][y] == 'A')   { NeighboursFound++; }
    if (gameboard[x][y-1] == 'A')   { NeighboursFound++; }
  }
  else if (y == 0 and x == width) {
    if (gameboard[x-1][y-1] == 'A') { NeighboursFound++; }
    if (gameboard[x][y-1] == 'A')   { NeighboursFound++; }
    if (gameboard[x-1][y] == 'A')   { NeighboursFound++; }
  }

  return(NeighboursFound); 
}


