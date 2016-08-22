#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>

using namespace std;

// Vars
int base, intermediate, intermediate_2, conv_base, arraycall;
string init_value, finalnum[10];


void Convert_To();
void Print_letter(int y);
void Help();

int main( int argc, char *argv[]) {

  // Not enough arguments
  if (argc < 4) {
    Help();
    exit(0);
  }

  // Checks if the ints are valid
  else if (atoi(argv[1]) / 1 == 0 || atoi(argv[3])/ 1 == 0) {
      Help();
      exit(0);
  }
  
  // Checks if the string is valid
  else if ( stoi( string(argv[2]), nullptr, atoi(argv[1]) ) == 0) {
    cout << "The answer is 0\n";
    Help();
    exit(0);
  }

  base = atoi(argv[1]);					  // initial base
  init_value = string(argv[2]);           		  // initial value
  conv_base = atoi(argv[3]);				  // base to convert to
    

  Convert_To();						  // Calls function to convert number

  while ( arraycall != 0 ) {

    cout << finalnum[arraycall - 1];			  // Prints out the strings in reverse order

    arraycall--;
  }
  cout << endl;						  // Cleanly flush the output

  return 0;

}

void Convert_To() {

  // Skips if base is the same as converted base
  if (base != conv_base) {

    intermediate = stoi( init_value, nullptr, base );	  // Convert nummber to decimal

    // Get the number to zero and convert it each time
    while ( intermediate != 0) {
      
      intermediate_2 = intermediate % conv_base;          // Take the remainder from dividing base 10 by the converted base 
      intermediate = intermediate / conv_base;		  // Take the product from dividing the base 10 by the converted base

      if ( intermediate_2 < 10 ) { 
	finalnum[arraycall] = to_string(intermediate_2);  // Adds the values to an array of strings
      }
      else {
	Print_letter(intermediate_2);			  // Go to function to change the numbers over 10 to words
      }
      arraycall++;					  // Keeps track of all the ints entered into the list
	}
  }

  else {

    intermediate = stoi(init_value);			  // return the same number input if no conversion takes place
  }
}

void Print_letter(int y){

  map<int, string> Comparator;				  // Creates a map for matching the corresponding str for the int

  Comparator[10] = "A";
  Comparator[11] = "B";
  Comparator[12] = "C";
  Comparator[13] = "D";
  Comparator[14] = "E";
  Comparator[15] = "F";
  Comparator[16] = "G";
  Comparator[17] = "H";
  Comparator[18] = "I";
  Comparator[19] = "J";
  Comparator[20] = "K";
  Comparator[21] = "L";
  Comparator[22] = "M";
  Comparator[23] = "N";
  Comparator[24] = "O";
  Comparator[25] = "P";
  Comparator[26] = "Q";
  Comparator[27] = "R";
  Comparator[28] = "S";
  Comparator[29] = "T";
  Comparator[30] = "U";
  Comparator[31] = "V";
  Comparator[32] = "X";
  Comparator[33] = "Y";
  Comparator[34] = "Z";

  finalnum[arraycall] = Comparator[y];			  // Adds the corresponding value to the final answer
  
  
}

// Prints help information
void Help()  {

  cout << "Help Information" << endl;
  cout << "COMMAND:" << endl;
  cout << "\tconversions [initial base] [initial value] [Final base]" << endl;
  cout << "\n\tThe output cannot be over ten characters [Did not use vectors]" << endl;
}
