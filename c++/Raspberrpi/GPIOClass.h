# ifndef GPIO_CLASS_H
# define GPIO_CLASS_H

#include <string>

/* GPIO Class 
 * Control each GPIO pin individually
 */

class GPIOClass
{
 public:
  GPIOClass();	                                      //Create a GPIO object that controls GPIO4 (default)
  GPIOClass(std::string x);                           // Create a GPIO object that conrols GPIOx, where x is phased
  int export_gpio();                                  // Exports GPIO
  int unexport_gpio();                                  // Unexport GPIO
  int setdir_gpio(std::string dir);                        // Set GPIO Direction
  int setval_gpio(std::string val);			      // Set GPIO value (putput pins ?)
  int getval_gpio(std::string &val);                       // Get GPIO (I/O pins)
  std::string get_gpionum();                               // returns the instance of the object
 private:
  std::string gpionum;
};

#endif
