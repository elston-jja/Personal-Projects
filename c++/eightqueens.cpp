#include <iostream>

char** createEmptyGameboard(int square);
void deleteGameboard(char**gameboard, int square);
void printGameboard(char**gameboard, int square);
void createQueen(char**gameboard, int squares, int x, int y);
bool checkMove(char**gameboard, int x, int y);
void checkQueens(char**gameboard, int squares);

int main() {

  int input, y(0);

  std::cout << "Amount of queens: ";
  std::cin >> input;

  char** gameboard = createEmptyGameboard(input);
  //printGameboard(gameboard, input);
  
  for (int i = 0; i < input; i++){			    // Go through the first line
    createQueen(gameboard, input, i, y);		    // Create a queen on the first square
    for (int b = 1; b < input; b++){			    // itterate through the y (y=1,y=2,y=3...)
      for (int a = 1; a < input; a++){			    // itterate through the x (x'')
	if (gameboard[a][b] == '-'){                        // Check if it is and empty square
	  createQueen(gameboard, input, a, b);		    // Create queen on empty square
	}
	else if ( a > input ) {				    // if the whole row is full check the next row
	  a = 0;					    // got to the next line and set the x value to zero
	  b++;
	  createQueen(gameboard, input, a, b);
	}
	else if ( b > input ) {				    // check if the y value is at the end
	  break;					    // end the loop if it is
	}
      }
    }
    break;
  }

  
  printGameboard(gameboard, input);

  checkQueens(gameboard, input);

  deleteGameboard(gameboard, input);

  return 0;
}

char** createEmptyGameboard(int square) {

  char **gameboard = new char*[square];
  for (int i = 0; i < square; i++) {
    gameboard[i] = new char[square];
  }
  for (int y = 0; y < square; y++){
    for (int x = 0; x < square; x++){
      gameboard[x][y] = '-' ;
    }
  }
  return gameboard;
}

void deleteGameboard(char**gameboard, int square){
  for (int i = 0; i < square; i++){
    delete [] gameboard[i];
  }
  delete [] gameboard;

}

void printGameboard(char**gameboard, int square) {
  std::cout << std::endl;
  for (int y = 0; y < square; y++){
    for (int x = 0; x < square; x++){
      std::cout << gameboard[x][y] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void createQueen(char**gameboard, int squares, int x, int y) {
  int a(x);
  gameboard[x][y] = 'Q';
  for (int i = y-1; i >= 0; i--){gameboard[x][i] = 'X';}	// Up
  for (int i = y+1; i < squares; i++){gameboard[x][i] = 'X';}   // Down
  for (int i = x+1; i < squares; i++){gameboard[i][y] = 'X';}   // Right
  for (int i = x-1; i >= 0; i--){gameboard[i][y] = 'X';}        // Left
  for (int i = y+1; i < squares; i++){ if (a-1 < 0 ){break;} ;a--; gameboard[a][i] = 'X';}    // Down Left
  a = x;
  for (int i = y+1; i < squares; i++){ if (a+1 == squares) {break;};a++;gameboard[a][i] = 'X'; } //Down Right
  a = x;
  for (int i = y-1; i >= 0; i--){ if (a+1 > squares-1) {break;};a++;gameboard[a][i] = 'X'; }  //Up Right
  a = x;
  for (int i = y-1; i >= 0; i--){ if (a-1 < 0 ){break;} ;a--; gameboard[a][i] = 'X';}         // Up Left
  a = x;
}

bool checkMove(char**gameboard,int x, int y){
  if (gameboard[x][y] == 'X') {
    return false;
  }
  else {
    return true;
  }
}

void checkQueens(char**gameboard, int squares) {	    // Quick way to read output and checks
  int queensfound(0);
  for (int y = 0; y < squares; y++){
    for (int x = 0; x < squares; x++){
      if (gameboard[x][y] != 'X'){
	queensfound++;
	std::cout << "X: " << x << " Y: " << y << std::endl;
      }
    }
  }
  std::cout << "Total queens drawn: " << queensfound << std::endl;
  if (queensfound < squares) {
    std::cout << "Program Failed" << std::endl;
  }
  else{
    std::cout << "Program Wroks" << std::endl;
  }
}
