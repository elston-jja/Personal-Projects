#include <iostream>
#include <stdlib.h>

char** createEmptyGameboard(int square);
void deleteGameboard(char**gameboard, int square);
void printGameboard(char**gameboard, int square);
bool checkMove(char**gameboard,int squares,int x, int y);
void checkQueens(char**gameboard, int squares);
bool checkColumnQueen(char**gameboard, int squares, int y);
void getSolution(char**gameboard, int input,int x, int y);
void runSolution(char**gameboard, int input,int x, int y);

int main() {

  int input;

  std::cout << "Amount of queens: ";
  std::cin >> input;					    // Get the amount of queens

  char** gameboard = createEmptyGameboard(input);	    // Create the board for playing based on input

  getSolution(gameboard, input, 0 , 0);
  
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

 bool checkMove(char**gameboard, int squares,int x, int y){
   
   for (int b = 0; b < squares; b++){
     for (int a = 0; a < squares; a++){

       if (gameboard[a][b] == 'Q'){
	 
	 if(abs(a)-abs(x) == 0)    {return false;}
	 if(abs(b)-abs(y) == 0)    {return false;}
	 if(abs((b-y)/(a-x)) == 1) {return false;}
       }
     } 
   }
   return true;						    // Returns true if 
 }

void checkQueens(char**gameboard, int squares) {	    // Quick way to read output and checks
  int queensfound(0);
  for (int y = 0; y < squares; y++){
    for (int x = 0; x < squares; x++){
      if (gameboard[x][y] == 'Q'){
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

bool checkColumnQueen(char**gameboard, int squares, int x){

  for (int i = 0; i < squares; i++ ){
    if (gameboard[x][i] == 'Q'){return true;}
  }
  return false;
}

void getSolution(char**gameboard, int input, int x, int y){

  for (int i = 0; i < input; i++) {			    
    gameboard[i][0] = 'Q';

    runSolutions(gameboard, input, 0, 0)
  }  
}

void runSolutions(char**gameboard, int input, int x, int y){

  bool valid, columnQueen;
  
  for (int x = ; x < input; x++) {
    for (int y = 0; y < input; y++){
      
      valid = checkMove(gameboard, input, x, y);
      
      if (valid) {
	
	gameboard[x][y] = 'Q';
	
	}
      if (y == input-1){
	
	columnQueen = checkColumnQueen(gameboard, input, x);
	
	if (!columnQueen) {
	  
	    std::cout << "Queen does not exist" << std::endl;
	    
	    
	}
      }
    }
  }
  break;
}
