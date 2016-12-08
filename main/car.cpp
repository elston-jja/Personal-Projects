#include "car.h"
#include "/usr/share/arduino/hardware/arduino/avr/cores/arduino/Arduino.h"


Car::Car(int baud, int servoPin)
{
	Serial.begin(baud);
//	e.attach(servoPin);
}

void Car::USSetup(int trigPin, int echoPin)
{
	tp = trigPin;
	ep = echoPin;
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

void Car::MotorSetup(int leftMotorP, int leftMotorN, int rightMotorP, int rightMotorN)
{
	lP = leftMotorP;
	lN = leftMotorN;
	rP = rightMotorP;
	rN = rightMotorN;
	
	int pins[4] = {lP,lN,rP,rN};

	for ( int i; i < 4 ; i++ )
    {
		pinMode(pins[i], OUTPUT);
    }
}
int Car::distance()
{
    int duration(0), distance(0);
	digitalWrite(tp, HIGH);
	delayMicroseconds(1000);
	digitalWrite(tp, LOW);
	duration = pulseIn(ep, HIGH);
	distance = (duration /2) / 29.2;
	if (distance > 0)
    {
		return (distance);
    }
	return(0);
}

void Car::forward()
{
  digitalWrite(rP, HIGH);
  digitalWrite(lP, HIGH);
  delay(1000);
  digitalWrite(rP, LOW);
  digitalWrite(lP, LOW);
}

 void Car::reverse()
{
  digitalWrite(rN, HIGH);
  digitalWrite(lN, HIGH);
  delay(1000);
  digitalWrite(rN, LOW);
  digitalWrite(lN, LOW);
}


void Car::turn(bool direction, int duration)
{
  //rotate and reverse rotate each wheel respectivly
	// go left
	if (direction)
    {
      digitalWrite(rP, HIGH);
      digitalWrite(lN, HIGH);
      delay(duration);
      digitalWrite(rP, LOW);
      digitalWrite(lN, LOW);
      
    }
  //rotate right
  else
    {
      digitalWrite(rN, HIGH);
      digitalWrite(lP, HIGH);
      delay(duration);
      digitalWrite(rN, LOW);
      digitalWrite(lP, LOW);
    }
}

void Car::turnH(bool direction, int duration)
{	
  //rotate ONLY one wheel
  if (direction)
    {
      //turn left
      digitalWrite(rP, HIGH);
      delay(duration);
      digitalWrite(rP, LOW);
    }
  else
    {
      //turn right
      digitalWrite(lP, HIGH);
      delay(duration);
      digitalWrite(lP, LOW);
    }
}

//void Car::sensor(int angle)
//{
//  e.write(angle);
//}
//

