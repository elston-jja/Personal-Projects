#include <Servo.h>

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
void moveForward();
void moveReverse();
void rotate(bool vecDir);

void setup()
{
  // Start terminal interface on 9600
  Serial.begin(9600);

  // Setup pins for ultrasonic sensor
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
  while(1){
 // point sensor forwards
  s.write(90);

  if (!skipFlag)
    {
      // check if it previously reversed
      if (!colCheck())
	{
	  // Send motor to move a certain distance
	  moveForward();
	  continue;
	}
    }
  skipFlag = false;


  // point sensor left
  s.write(165);
    delay(1000);

  if (!colCheck())
    {
      // Just rotate 
      // turn off one wheel and rotate body, left priority
      rotate(true);
      continue;
    }

  // point sensor right
  s.write(6);
  delay(1000);

  if (!colCheck())
    {
      // Just rotate
      // turn off one wheel and rotate body, check right
      rotate(false);
      continue;
    }

  // trun motor back
  //
  moveReverse();
  
  // Set flag to skip 1st if statement
  skipFlag = true;
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
  if (distance > 0 && distance < 50)
    {
      return (true);
    }
  return(false);
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

void rotate(bool vecDir)
{
  // if the direction is true
  // rotate left
  if (vecDir)
    {
      
      digitalWrite(rightMotorP, HIGH);
      digitalWrite(leftMotorN, HIGH);
      
      delay(2000);

      digitalWrite(rightMotorP, LOW);
      digitalWrite(leftMotorN, LOW);
      
    }
  //rotate right
  else
    {
      digitalWrite(rightMotorN, HIGH);
      digitalWrite(leftMotorP, HIGH);
      
      delay(2000);
      
      digitalWrite(rightMotorN, LOW);
      digitalWrite(leftMotorP, LOW);
      
    }
}
