#include <vector>
#include <iostream>

struct images
{
  std::string n;
  std::string p;

  images(std::string name, std::string path): n(name), p(path) {} 
};


int main()
{
  std::vector <images> strarray;
  
  strarray = {("u","s")};
  //   {
  //     ( "hello","test"),
  //     ( "my","test"),
  //     ("name","test")
  //   };

    // std::cout << strarray[0] << std::endl;
}
