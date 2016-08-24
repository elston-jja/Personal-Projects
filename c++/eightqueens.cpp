#include <iostream>

char** createEmptyGameboard(int square);
void deleteGameboard(char**gameboard, int square);
void printGameboard(char**gameboard, int square);
void createQueen(char**gameboard, int squares, int x, int y);

int main() {

  int input;// x1(0), y1(0);//, backup_x1(x1), backup_y1(y1), x2, y2;

  std::cout << "Amount of queens: ";
  std::cin >> input;

  char** gameboard = createEmptyGameboard(input);
  printGameboard(gameboard, input);


  // for (int i = 0; i < input; i++) {
  //   createQueen(gameboard, input, x1, y1);

  //   for (int y2 = 1; y2 < input; y2++){

  //     for (int A1 = 1; A1 < input; A1++){

  // 	if (gameboard[x1+A1][y2] != 'X'){
  // 	    x2 = x1 + A1;
  // 	    createQueen(gameboard, input, x2, y2);
  // 	    break;
  // 	  }
  //     }
  //   }
  // }

  createQueen(gameboard, input, 0, 8);

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
  int a(x),b(y);
  gameboard[x][y] = 'Q';
  if (x != squares-1 and y != squares-1 and y != 0 and x != 0) {

    //up
    for (int i = y-1; i >= 0; i--){gameboard[x][i] = 'X';}
    //down
    for (int i = y+1; i < squares; i++){gameboard[x][i] = 'X';}
    // right
    for (int i = x+1; i < squares; i++){gameboard[i][y] = 'X';}
    // left
    for (int i = x-1; i >= 0; i--){gameboard[i][y] = 'X';}
    //diagonal down left
    for (int i = y+1; i < squares; i++){ if (a-1 < 0 ){break;} ;a--; gameboard[a][i] = 'X';}
    a = x;
    //diagonal down right
    for (int i = y+1; i < squares; i++){ if (a > squares) {break;};a++;gameboard[a][i] = 'X'; }
    a = x;
    //diagonal up right
    for (int i = y-1; i > 0; i--){ if (a+1 == squares or y == 0) {break;};a++;gameboard[a][i] = 'X'; }
    a = x;
    //diagonal up left
    for (int i = y-1; i >= 0; i--){ if (a-1 < 0 ){break;} ;a--; gameboard[a][i] = 'X';}
    a = x;
  }

  if (x == 0) {
    // right
    for (int i = x+1; i < squares; i++){gameboard[i][y] = 'X';}
    if (y == 0) {
      //diagonal down right
      for (int i = y+1; i < squares; i++){ if (a > squares) {break;};a++;gameboard[a][i] = 'X'; }
      a = x;
      //down
      for (int i = y+1; i < squares; i++){gameboard[x][i] = 'X';}
    }
    else if (y != 0 and y != squares-1){
      //diagonal down right
      for (int i = y+1; i < squares; i++){ if (a > squares) {break;};a++;gameboard[a][i] = 'X'; }
      a = x;
      //diagonal up right
      for (int i = y-1; i > 0; i--){ if (a+1 == squares or y == 0) {break;};a++;gameboard[a][i] = 'X'; }
      a = x;
      //down
      for (int i = y+1; i < squares; i++){gameboard[x][i] = 'X';}
      //up
      for (int i = y-1; i >= 0; i--){gameboard[x][i] = 'X';}
    }
    else if (y == squares-1){
      //up
      for (int i = y-1; i >= 0; i--){gameboard[x][i] = 'X';}
      //diagonal up right
      for (int i = y-1; i > 0; i--){ if (a+1 == squares or y == 0) {break;};a++;gameboard[a][i] = 'X'; }
      a = x;
    }
  }

  if (x == squares-1) {

    if ( y != squares-1 and y != 0){
      //diagonal down left
      for (int i = y+1; i < squares; i++){ if (a-1 < 0 ){break;} ;a--; gameboard[a][i] = 'X';}
      a = x;
      //down
      for (int i = y+1; i < squares; i++){gameboard[x][i] = 'X';}
    }
    else if ( y == 0 ) {
      //down
      for (int i = y+1; i < squares; i++){gameboard[x][i] = 'X';}
      // left
      for (int i = x-1; i >= 0; i--){gameboard[i][y] = 'X';}
      //diagonal down left
      for (int i = y+1; i < squares; i++){ if (a-1 < 0 ){break;} ;a--; gameboard[a][i] = 'X';}
      a = x;
    }

    //up
    for (int A_1 = y-1; A_1 >= 0; A_1--){gameboard[x][A_1] = 'X';}
    //left
    for (int A_2 = x-1; A_2 >= 0; A_2--){gameboard[A_2][y] = 'X';}
    //diagonal up left
    for (int i = y-1; i >= 0; i--){ if (a-1 < 0 ){break;} ;a--; gameboard[a][i] = 'X';}
    a = x;

  }
  if ( y == squares -1) {
    //up
    for (int A_1 = y-1; A_1 >= 0; A_1--){gameboard[x][A_1] = 'X';}
    //left
    for (int A_2 = x-1; A_2 >= 0; A_2--){gameboard[A_2][y] = 'X';}
    // right
    for (int i = x+1; i < squares; i++){gameboard[i][y] = 'X';}
    //diagonal up right
    for (int i = y-1; i > 0; i--){ if (a+1 == squares or y == 0) {break;};a++;gameboard[a][i] = 'X'; }
    a = x;
    //diagonal up left
    for (int i = y-1; i >= 0; i--){ if (a-1 < 0 ){break;} ;a--; gameboard[a][i] = 'X';}
    a = x;
  }
  if ( y == 0 and x != squares -1 and x != 0) {
    //down
    for (int i = y+1; i < squares; i++){gameboard[x][i] = 'X';}
    //diagonal down left
    for (int i = y+1; i < squares; i++){ if (a-1 < 0 ){break;} ;a--; gameboard[a][i] = 'X';}
    a = x;
    //diagonal up right
    for (int i = y-1; i > 0; i--){ if (a+1 == squares or y == 0) {break;};a++;gameboard[a][i] = 'X'; }
    a = x;
  }
}
