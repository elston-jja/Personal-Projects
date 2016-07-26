#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>

using namespace std;

// State Vars
int randint, simon, points;
string user;
bool running;

// Main program extracted
void simonsays() {
  
  // Generate random seed based on current time
  srand(time(0));
  
  // Produces # range 0-99
  randint = rand()%100;
  // Produces # range 0-1
  simon = rand()%2;

  // Simon does not say
  if (simon == 0)
    {
      cout << "Type " << randint << "\n" << endl;
      cout <<  ">> ";
      getline( cin, user);
    
    if ( !user.empty() ) 
      {
	// If the user typed in what simon did not say
	// end program
	cout << "You failed " << user << endl;
	running = false;
      }
    else
      {
	// Add one point for getting the answer right
      points++;
      }
    }

  // Simon says
  else
    {
      cout << "Simon says type " << randint << "\n" << endl;
      cout <<  ">> ";
      getline(cin, user);

    // User did not type what simon said
    if ( user != to_string(randint) ) 
      {
	// End program 
	cout << "You failed " << user << endl;
	running = false;
      }
    else
      {
	// Add one point for getting the answer right
      points++;
      }
    }
}
  
// Main
int main(){
  
  // Intro
  cout << "Simon Says V0.2" << endl;
  cout << "---------------" << endl;
  cout << "Rules are simple, only do what simon tells you, else press return" << endl;

  running = true;  

  // Game loop
  while (running)
    {

      system("clear");
      
      // Prints out score
      cout << "Current score: " << points << "\n" << endl;

      // Run subprogram
      simonsays();
    }
  return 0;
  
}


