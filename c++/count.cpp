# include <iostream>
# include <stdlib.h>
# include <cmath>


using namespace std;

void help();

int main( int argc, char *argv[] ) {

  // Checks if arguments exits
  if (argc < 2) {
    help();
    exit(0);
  }
  // Checks if the argument is valid
  else if ( atoi(argv[1]) > pow(10,9) ) {
    help();
    exit(0);
  }
  // Ignores the argument if it's a string
  else if ( atoi(argv[1]) / 1 == 0) {
    help();
    exit(0);
  }

  // Print loop
  for( int i = 0; i < atoi(argv[1]) + 1; i++ ) {
    cout << i << endl;
  }

  return 0;
  
}

void help() {

  // Help Info printed
  cout << "Help Information:\n" << endl;
  cout << "COMMAND: " << endl;
  cout << "\tcount [number]" << endl;
  cout << "\n\tThe number can only be less than a billion" << endl;
}
