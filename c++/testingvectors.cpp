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
  return 0;
  
}

void GetNames()
{
  
  std::string names;
  
  while (names != "done")
    {
      std::cout << "Please enter names for the raffle: ";
      std::cin >> names;
      namelist.push_back(names);
      
    }
  
  namelist.erase(namelist.end());
}

void EliminationSequence()
{
  
  while (namelist.size() !=  1)
    {
      std::cout << namelist.size() << ". ";
      std::cout << namelist[namelist.size()] << std::endl;
      namelist.pop_back();
      
    }

  for (int i; i < 10 ; i++)
    {
      std::cout << namelist[i] << std::endl;

    }

}

