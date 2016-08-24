#include <iostream>

char** createEmptyGameboard(int square);
void deleteGameboard(char**gameboard, int square);
void printGameboard(char**gameboard, int square);
void createQueen(char**gameboard, int squares, int x, int y);
bool checkMove(char**gameboard, int x, int y);

int main() {

  int input, x(0), y(0),a ;
  bool valid;

  std::cout << "Amount of queens: ";
  std::cin >> input;

  char** gameboard = createEmptyGameboard(input);
  printGameboard(gameboard, input);

  createQueen(gameboard, input, a, y);
  
  for ( int i = 0; i < input; i++){
    createQueen(gameboard, input, i, y);
    for (int a = 1; a < input; a++){
      for (int b = 0; b < input; b++){
	valid = checkMove(gameboard, b, a);
	if (valid) {
	  createQueen(gameboard,input ,b ,a );
	}
      }
      break;
    }
  }
  printGameboard(gameboard, input);

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
