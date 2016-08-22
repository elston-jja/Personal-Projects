#include <iostream>
#include <time.h>
#include <vector>
#include <string>

int main() {

  //Vars
  int randint, namelistsize;
  std::string names;
  std::vector<std::string> namelist;
  
  while (1) {
    std::cout << "Please enter the names in the lottery: ";
    std::getline(std::cin, names);			    // Store the string entered into string var names
    if (names != "done") {
      namelist.push_back(names);			    // Add the names entered into the vector 
    }
    else {
      break;
    }
  }
  namelistsize = namelist.size();                           // Static size of vector for loop
  std::srand(time(0));					    // Produce the seed for ranint
  for (int i=0; i < namelistsize -1; i++) {
    randint = std::rand()%namelist.size();		    // Create a random int in range of the vectors size
    std::cout << "Sorry " << namelist[randint] << std::endl; // Provide an elimination statement
    namelist.erase(namelist.begin()+randint);		    // Delete the name stated from the vector
  }
  std::cout << "Therefore the winner is " << namelist[0] << ". Congratulations!" << std::endl;

  return 0;
}
