#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <ncurses.h>
#include <cstdlib>
#include <algorithm>
#include "GPIOClass.h"
#include <vector>

using namespace std;

void sig_handler(int sig);

bool ctrl_c_pressed = false;

vector<int> pressedkeys;

void get_keyboard();

int keyboard;



int main(void) {


  struct sigaction sig_struct;
  sig_struct.sa_handler = sig_handler;
  sig_struct.sa_flags=0;
  sigemptyset(&sig_struct.sa_mask);
  
  if (sigaction(SIGINT, &sig_struct, NULL) == -1) {
    cout << "Problem with sigaction" << endl;
    exit(1);
  }

  
  string inputstate;
  string outputstate;
  GPIOClass* gpio_red = new GPIOClass("4"); 		    // Create new GPIO object attached to pin 4
  GPIOClass* gpio_blue = new GPIOClass("17"); 		    // Create new GPIO object attached to pin 17
  GPIOClass* gpio_green = new GPIOClass("27");
  GPIOClass* gpio_yellow = new GPIOClass("22");
    
  gpio_red->export_gpio();					      // export GPIO4
  gpio_blue->export_gpio();                                           // export GPIO17
  gpio_green->export_gpio();                                          // export GPIO27
  gpio_yellow->export_gpio();                                         // export GPIO23
  cout << "pins exported" << endl;

  gpio_red->setdir_gpio("out");				    // set as pin output
  gpio_blue->setdir_gpio("out");                             // set as pin output
  gpio_green->setdir_gpio("out");                             // set as pin output
  gpio_yellow->setdir_gpio("out");                             // set as pin output
  cout << "GPIO pin directions are set" << endl;

  initscr();						    // Initialize ncurses
  noecho();						    // Do not echo the keys pressed to the prompt
  cbreak();						    // Disables buffer erase/kill
  keypad(stdscr, TRUE);					    // Enable the Keypad
  nodelay(stdscr, TRUE);				    // Do not wait for inputstate

  
  while(1) {

    keyboard = getch();					    // Check what key is pressed

    if( keyboard != ERR ){				    // If key is pressed

      if (keyboard == 259) {
	gpio_red->setval_gpio("1");
	usleep(50000);
      }
      if (keyboard == 258){
        gpio_blue->setval_gpio("1");
	usleep(50000);
      }	
      if (keyboard == 261){
        gpio_green->setval_gpio("1");
	usleep(50000);
      }
      if (keyboard == 260){
        gpio_yellow->setval_gpio("1");
	usleep(50000);
      }

      
      if (keyboard != 259)
        gpio_red->setval_gpio("0");
      if (keyboard != 258)
        gpio_blue->setval_gpio("0");
      if (keyboard != 261)
        gpio_green->setval_gpio("0");
      if (keyboard != 260)
        gpio_yellow->setval_gpio("0");

      usleep(500);
    }
    

    if(ctrl_c_pressed)
      {
	endwin();
	
        cout << "Unexporting pins" << endl;
        gpio_red->unexport_gpio();
        gpio_blue->unexport_gpio();
	gpio_green->unexport_gpio();
	gpio_yellow->unexport_gpio();
        cout << "Deallocating GPIO Objects" << endl;
	
        delete gpio_red;
	gpio_red = 0;
	delete gpio_blue;
	gpio_blue = 0;
	delete gpio_green;
	gpio_green = 0;
	delete gpio_yellow;
	gpio_yellow = 0;
	
        break;
      }
    refresh();
  }
    return 0;
}


void sig_handler(int sig) {
  write(0, "\nCtrl^C pressed in sig handler\n", 32);
  ctrl_c_pressed = true;
}
