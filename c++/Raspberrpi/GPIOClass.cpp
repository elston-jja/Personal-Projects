#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "GPIOClass.h"

using namespace std;

GPIOClass::GPIOClass() {

  this->gpionum = "4";					    // Set 4 to be the default pin
}

GPIOClass::GPIOClass(string gnum) {

  this->gpionum = gnum;					    // Initialize the GPIOClass object for the GPIO pin number "gnum"
}

int GPIOClass::export_gpio(){

  string export_str = "/sys/class/gpio/export";
  ofstream exportgpio(export_str.c_str());                  // Open the export file :: convert c++ string to c string
  if (exportgpio < 0) {
    cout << "The operation failed, unable to export GPOIO" << this->gpionum << " ." << endl;

    return -1;
  }

  exportgpio << this->gpionum ;				    // Write GPIO number to export
  exportgpio.close();					    // Close the export file
  return 0;
}

int GPIOClass::unexport_gpio() {

  string unexport_str = "sys/class/gpio/unexport";
  ofstream unexportgpio(unexport_str.c_str());		    // Open export file

  if (unexportgpio < 0) {

    cout << "Operation failed, unable to unexport GPIO" << this ->gpionum << " ." << endl;
    return -1;
  }

  unexportgpio << this->gpionum ;			    // wite gpio number to unexport
  unexportgpio.close();					    // close the unexport file
  return 0;
  
}


int GPIOClass::setdir_gpio(string dir) {

  string setdir_str = "/sys/class/gpio/gpio" + this->gpionum + "/direction";
  ofstream setdirgpio(setdir_str.c_str());		    // open directiob file for gpio

  if (setdirgpio < 0) {
    cout << "Operation failed, unable to set direction GPIO" << this ->gpionum << " ." << endl;

    return -1;
  }

  setdirgpio << dir;					    // write direction to the direction file
  setdirgpio.close();					    // close direction file

  return 0;
}

int GPIOClass::setval_gpio(string val) {

  string setval_str = "/sys/class/gpio/gpio" + this->gpionum +"/value";
  ofstream setvalgpio(setval_str.c_str());

  if (setvalgpio < 0 ){
    cout << "Operation failed, unable to set value of GPIO" << this ->gpionum << " ." << endl;

    return -1;
  }

  setvalgpio << val ;
  setvalgpio.close();
  return 0;
  
}

int GPIOClass::getval_gpio(string& val){

  string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
  ifstream getvalgpio(getval_str.c_str());

  if (getvalgpio < 0) {
    cout << "Operation failed, unable to get value of GPIO" << this ->gpionum << " ." << endl;

    return -1;
  }

  getvalgpio >> val;

  if(val != "0")
    val = "1";
  else
    val = "0";

  getvalgpio.close();
  return 0;
  
}

string GPIOClass::get_gpionum(){

  return this->gpionum;
}
