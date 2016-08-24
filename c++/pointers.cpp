#include <iostream>

void changeArray(int*);

int main() {

  int value = 5;
  int* ptr = &value;

  std::cout << value << " " << *ptr << std::endl;
  value = 8;
  std::cout << value << " " << *ptr << std::endl;
  *ptr = 0;

  int array[] = {0,1,2,3,4};
  std::cout << "Element 0 is: " << array[0] << std::endl;
  changeArray(array);
  std::cout << "Element 0 is now: " << array[0] << std::endl;
  std::cout << "Element 1 is now: " << array[1] << std::endl;

  return 0;
}
