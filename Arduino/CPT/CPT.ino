#include <Servo.h>

// Written by Michael Nugyen and Elston Almeida
// Grade 12 Computer Enginnering CPT
// Create a self driving robot

// const pin number ints
#define trigPin 4
#define echoPin 3
#define leftMotorP 9
#define leftMotorN 10
#define rightMotorP 7
#define rightMotorN 8

// A check to skip forward check (1st if)
bool skipFlag = false;

// Assign s as a servo type
Servo s;

// forward declaration
bool colCheck();
int DistanceToClose();
void moveForward();
void moveReverse();
void rotate(bool vecDir, int dur);

void setup()
{
  // Start terminal interface on 9600
  Serial.begin(9600);

  //  pins for ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set up pins for motor
  int pins[] =
    {
      leftMotorP,
      leftMotorN,
      rightMotorP,
      rightMotorN,
    };
  
  // for each pins in the pins array set them to high
  for ( int i; i < 4 ; i++ )
    {
      pinMode(pins[i], OUTPUT);
    }

  // Define Servo on pin 9
  s.attach(11);
}

void loop()
{
 // point sensor forwards
  s.write(165);
  int distance(DistanceToClose());
  if( 15 < distance && distance < 30)
   {
     //Distance too close move away
     // only if the distance is greater than 15 cm
     rotate(false, 1000);
     moveForward();
     rotate(true, 750);
   }

  // distance is less than 30
  else if(distance > 0 && distance < 15)
    {
      rotate(false, 200);
      rotate(true, 100);
    }
  else if(distance > 100)
    {
      rotate(true,700);
      moveForward();
      rotate(false, 1000);
    }
      
  if (colCheck())
    {
      // if in range
      moveForward();
    }
  else
    {
      // if out of range
      moveForward();
      moveForward();
      rotate(true,1500);
      moveForward();
    }
}

// check if a wall is neat <150
bool colCheck()
{
  int duration(0), distance(0);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration /2) / 29.2;
  if (distance > 0 && distance < 60)
    {
      return (true);
    }
  return(false);
}
int DistanceToClose()
{
    int duration(0), distance(0);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration /2) / 29.2;
  if (distance > 0 && distance <150)
    {
      return (distance);
    }
  return(0);
}

void moveForward()
{
  digitalWrite(rightMotorP, HIGH);
  digitalWrite(leftMotorP, HIGH);

  delay(1000);

  digitalWrite(rightMotorP, LOW);
  digitalWrite(leftMotorP, LOW);
}

void moveReverse()
{
  digitalWrite(rightMotorN, HIGH);
  digitalWrite(leftMotorN, HIGH);

  delay(1000);

  digitalWrite(rightMotorN, LOW);
  digitalWrite(leftMotorN, LOW);
}

void rotate(bool vecDir, int dur)
{
  // if the direction is true
  // rotate left
  if (vecDir)
    {
      
      digitalWrite(rightMotorP, HIGH);
      digitalWrite(leftMotorN, HIGH);
      
      delay(dur);

      digitalWrite(rightMotorP, LOW);
      digitalWrite(leftMotorN, LOW);
      
    }
  //rotate right
  else
    {
      digitalWrite(rightMotorN, HIGH);
      digitalWrite(leftMotorP, HIGH);
      
      delay(dur);
      
      digitalWrite(rightMotorN, LOW);
      digitalWrite(leftMotorP, LOW);
      
    }
}
