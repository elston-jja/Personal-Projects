#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

// Vars

int base, intermediate, intermediate_2, conv_base, conv_number;
string number;

void Convert_To();

int main() {

  cout << "Please enter the current base\n> ";
  cin >> base;						  // Initial base

  cout << "Please enter the value\n> ";
  cin >> number;					  // Initial value 
  
  cout << "Please enter the value to convert to\n> ";
  cin >> conv_base;					  // Final base
  
  Convert_To();						  // Calls function to convert number

  conv_number = intermediate;				  // Set the final number to the converted intermediate value
  
  cout << conv_number <<endl;				  // Print out the final converted number

  return 0;

}

void Convert_To() {

  // Skips if base is the same as converted base
  if (base != conv_base) {

    intermediate = stoi( number, nullptr, base );	  // Convert nummber to decimal

    // Get the number to zero and convert it each time
    while ( intermediate != 0) {
      
      intermediate_2 = intermediate % conv_base;          // Take the remainder from dividing base 10 by the converted base 
      intermediate = intermediate / conv_base;		  // Take the product from dividing the base 10 by the converted base

      cout << intermediate_2 << endl;
    }
    
  }

  else {

    intermediate = stoi(number);
  }




}
