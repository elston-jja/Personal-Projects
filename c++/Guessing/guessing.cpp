#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

  // Declare Vars
  int randint, guess;

  // Generate a random number
  srand(time(NULL));
  randint = rand()%100;


  // Intro

  cout << "Guessing Game V0.1" << endl;
  cout << "------------------" << endl;
  cout << "Guess a number between 0 and 100" << endl;
  cout << "Guess: ";

  // Input guess
  cin >> guess;

  // Checks if guess == randint

  while (guess != randint) {

    system("clear");

    // Too high
    if ( guess > randint ) {
      cout << "Guess too high" << endl;
      
    }

    // Too low
    else {
      cout << "Guess too low" << endl;
      
    }

    // Next guess
    cout << "Please Try again" << endl;
    cout << "Guess: ";
    cin >> guess;
  }

  cout << "You guessed correctly " << randint << endl;
  
  return 0;
}
