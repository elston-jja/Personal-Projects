import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setup(37, GPIO.OUT)
GPIO.output(37, GPIO.LOW)

print("Currently running main.py")
try:
    while 1:
        GPIO.output(37, GPIO.HIGH)
except KeyboardInterrupt:
    GPIO.cleanup()
