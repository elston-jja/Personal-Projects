import time
import os
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

PIN_CLK = 17
PIN_DO  = 27
PIN_DI  = 23
PIN_CS  = 24

# Setup Pins
GPIO.setup(PIN_DI, GPIO.OUT)
GPIO.setup(PIN_CS, GPIO.OUT)
GPIO.setup(PIN_CLK, GPIO.OUT)
GPIO.setup(PIN_DO, GPIO.IN)

def getADC(channel):

    # Clear OLD DATA
    GPIO.output(PIN_CS, True)
    GPIO.output(PIN_CS, False)

    # Clock
    GPIO.output(PIN_CLK, False)

    for i in [1,1,channel]:
        if(i == 1):
            GPIO.output(PIN_DI, True)
        else:
            GPIO.output(PIN_DI, False)

        GPIO.output(PIN_CLK, True)
        GPIO.output(PIN_CLK, False)

    ad = 0

    for i in range(8):
        GPIO.output(PIN_CLK, True)
        GPIO.output(PIN_CLK, False)
        ad <<= 1
        if (GPIO.input(PIN_DO)):
            ad |= 0x1

    GPIO.output(PIN_CS, True)

    return ad

if __name__ == "__main__":
    while True:
        print("ADC[0]: {}\t ADC[1]: {}".format(getADC(0), getADC(1)))
        time.sleep(1)
