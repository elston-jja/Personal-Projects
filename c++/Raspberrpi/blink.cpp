#include <wiringPi.h>
int main(void)
{
	wiringPiSetup();
	pinMode(37, OUTPUT);
	while(1)
	{
		digitalWrite(37, HIGH); delay(500);
		digitalWrite(37, HIGH); delay(500);
	}
	return 0;
}
