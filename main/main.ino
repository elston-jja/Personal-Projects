#include <Servo.h>
#include "car.h"

// Written by Michael Nugyen and Elston Almeida
// Grade 12 Computer Enginnering CPT
// Create a self driving robot

// pin number ints
#define trigPin 4
#define echoPin 3
#define leftMotorP 9
#define leftMotorN 10
#define rightMotorP 7
#define rightMotorN 8
#define left true
#define right false

Car car(9600, 13);

Servo s;

void setup()
{
  car.USSetup(trigPin, echoPin);
  car.MotorSetup(leftMotorP, leftMotorN, rightMotorP, rightMotorN);
  s.attach(11);
  s.write(165);
  delay(2000);
}

void loop()
{
  //car.sensor(90);

  // car is too close
  if (car.distance() < 50)
  {
    car.turn(right, 1000);
    car.forward();
    car.turn(left, 750);
  }

  // car is almost out of range
  if( car.distance() > 100 && car.distance() < 120)
  {
  car.turn(left, 750);
  car.forward();
  car.turn(right, 200);     
  }

  // car is out of range, turn left
  if (car.distance() > 120)
  {
      s.write(120);
      delay(1000);
    if (car.distance() < 30)
    {
      car.reverse();
      car.turn(right, 2000); 
      car.forward();
      car.forward();
    }
    s.write(165);
    delay(1000);
    car.turn(left, 1200);
    car.forward();
  }
  
  // Car is in range
  if (50 < car.distance() < 100)
  {
    car.forward();
  }
}

