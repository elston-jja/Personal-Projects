#include <iostream>

// Forward Declaration
void createEmptyGameboard();
void deleteGameboard();
void printGameboard();

bool checkMove(int x, int y);
bool processTurns(int queens);

// GLOBAL VARS
char**gameboard;

int N;

int main() {
  
  N = 8;
  
  createEmptyGameboard();	                            // Create the board for playing based on queens

  if ( processTurns(0) )                                    // Calls function to check if reclusive solution exists
    {
      printGameboard();                                     // Print out the valid gameboard solved
    }
  else
    {
      std::cout << "A solution does not exist" << std::endl;
    }

  deleteGameboard();					    // Delete the gameboard pointers

  return 0;
}

bool processTurns(int queens){

  if (queens == N){					    // Solved as there are as many queens as rows
    return true;
  }

  for (int row = 0; row < N; row++) {		    // Run throught the columns

    if (checkMove(row, queens)) {
      
      gameboard[row][queens] = 'Q';

      if (processTurns(queens+1)) {
	return true;
      }
      else {
	gameboard[row][queens] = '~';
      }
    }
  }
  return false;
}

// The subprograms below works.

void createEmptyGameboard() {

  gameboard = new char*[N];
  for (int i = 0; i < N; i++) { gameboard[i] = new char[N];}
  for (int y = 0; y < N; y++) { for (int x = 0; x < N; x++){
      gameboard[x][y] = '-' ;
    }
  }
}

void deleteGameboard(){

  for (int i = 0; i < N; i++){ delete [] gameboard[i]; }
  delete [] gameboard;
}

void printGameboard() {
  
  for (int y = 0; y < N; y++){ for (int x = 0; x < N; x++){
      std::cout << gameboard[x][y] << " "; }
    std::cout << std::endl; }
}

bool checkMove(int x, int y) {
   
   for (int b = 0; b < N; b++){ for (int a = 0; a < N; a++){ if (gameboard[a][b] == 'Q')
	 {
	   if(abs(a)-abs(x) == 0 || abs(b)-abs(y) == 0 || abs((b-y)/(a-x)) == 1) {return false;}
	 }
     } 
   }
   return true;						    
 }
