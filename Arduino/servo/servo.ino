#include <Servo.h>

#define trigPin 4
#define echoPin 3

Servo myservo;

int rotation, val;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(11);
}

void loop()
{
	
	// put your main code here, to run repeatedly:
  int duration, distance,cdistance = 160, angle = 0;
  
  for (int i = 2; i <= 90; i++)
    {
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration/2) / 29.2;
      
      // Debug print serial
      Serial.print("Duration: ");
      Serial.println(duration);
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      Serial.print("Angle");
      Serial.println(myservo.read());
      Serial.println("---------");
      
      // Check only if the distance is less than 2m
      if (distance > 0 && distance < 160)
	{
	  // Debug print serial
	  Serial.print("Object detected at: \t");
	  Serial.print(distance);
	  Serial.println(" cm");
	  Serial.println("----------");
	  
	  // Check if the distance is less than the highest
	  // distance measured
	  if (cdistance > distance)
	    {
	      cdistance = distance;
	      angle = i;
	    }
	}
      delay(200);
      myservo.write(i);
    }
  
  myservo.write(angle);
  Serial.print("Turning to angle: ");
  Serial.println(angle);
  delay(6000);
  
}
