/*
BLINK || Version 0.01
*/

// Sets the variable pin
int ledPin = 13;

// Set pin status
void setup(void)
{
	// Set pin as output
	pinMode(ledPin, OUTPUT);
}

// Repeat forever
void loop()
{
	// led off
	digitalWrite(ledPin, LOW);
	// wait 3 seconds (3000ms)
	delay(150);
	// led on
	digitalWrite(ledPin, HIGH);
	// wait 3 seconds (3000ms)
	delay(150);
}
