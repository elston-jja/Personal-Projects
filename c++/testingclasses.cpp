#include <iostream>

class Divide
{
public:
  int numerator;
  int denominator = 0;

  Divide()
  {
    std::cout << "Please enter the value for first number: ";
    std::cin  >> numerator;
    while ( denominator == 0) {
      std::cout << "Please enter the value for the second number: ";
      std::cin >> denominator;
    }  
  }
  double getAnswer() { return static_cast<double>(numerator) / denominator; }
  double getPercent() { return static_cast<double>(getAnswer()) * (100); }
};

int main() {
  
  Divide frac;

  std::cout << "DECIMAL\n";
  std::cout << frac.getAnswer() << std::endl;
  std::cout << "Percent\n";
  std::cout << frac.getPercent() << "%" << std::endl;
  
  
  return 0;
}
