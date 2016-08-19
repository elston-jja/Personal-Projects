#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> namelist;

void GetNames();
void EliminationSequence();

int main()
{
  
  GetNames();
  EliminationSequence();
  std::cout << "Congrats: " << namelist[0] << " you win! \n";
  return 0;
  
}

void GetNames()
{
  
  std::string names;
  
  while (1)
    {
      std::cout << "Please enter names for the raffle: ";
      std::cin >> names;
      if (names == "done") {
	break;
      }
      else {
      namelist.push_back(names);
      }
    }
  
  namelist.erase(namelist.end());
}

void EliminationSequence() {
  while (namelist.size() !=  0)
    {
      std::cout << namelist.size() << ". ";
      std::cout << namelist[namelist.size()] << std::endl;
      namelist.pop_back();
    }
}
