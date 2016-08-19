#include <iostream>

class Divide
{
private:
  double numerator;
  double denominator;
  
public:
  void getFactoial();  
  //Divide (double x, double y): numerator(x), denominator(y) {}
  double getPercent() {return double((numerator)/(denominator))*100 ;}
  double getAnswer();
};

void Divide::getFactoial () {
  std::cout << "Please enter the numerator: ";
  std::cin >> numerator;

  denominator = 0;

  while(denominator == 0) {
    std::cout << "Please enter the denominator: ";
    std::cin >> denominator;
  }
}
double Divide::getAnswer() {return double(numerator)/(denominator) ;}

int main() {
  Divide foo;
  foo.getFactoial();  
  std::cout << "The percent is " << foo.getPercent() << "% " << std::endl;
  std::cout << "The decimal is " << foo.getAnswer() << std::endl;

  return 0;
}
