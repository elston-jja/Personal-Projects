#include <Vector.h>

/*
MEMORY || Version 0.01
*/
int ledPin = 13;
int pinIn = 12;
int toggle = 8;
int listcount = 0;
Vector<int> mem;


void setup(void)
{
	//Set up pins
	pinMode(ledPin, OUTPUT);
	pinMode(pinIn, INPUT);
	pinMode(toggle, INPUT);
}

void loop(void)
{
	// Memory delay
	int delayVar = 0;
	
	// while the toggle is not pressed again record
	while (digitalRead(toggle) == HIGH)
	{
		while (digitalRead(pinIn) == LOW)
		{
			// Set the led off
			digitalWrite(ledPin, LOW);
			// Record the amount of seconds waited
			delayVar++;
			// Wait 1 sec
			delay(100);
		}
		// multiply the delay values
		delayVar = delayVar * 100;
		// Push back the amount of time spent as elements in a vector
		mem.push_back(delayVar);
		// Reset the delay as a pin has been pressed
		delayVar = 0;
		//push back a zero to indicate light was on
		mem.push_back(0);
		// list cout add two for the two items
		listcount += 2;
		
		// Set the pin high
		digitalWrite(ledPin, HIGH);
		delay(100);	
	}
	while (digitalRead(toggle) ==LOW)
	{
		int pD = 0;
		
		for (int i = 0; i < listcount; i++)
		{
			if (mem[i] == 0)
			{
				pD = i;
				break;	
			}
		}			
		for (int i = pD;i < listcount; i++)
		{
			
			if (mem[i] == 0)
			{
				// turn on led for 1 sec
				digitalWrite(ledPin, HIGH);
				delay(100);
			}
			else
			{
				digitalWrite(ledPin, LOW);
				// Delay if the input is not 0
				delay(mem[i]);
			}
		}	
	}
}
