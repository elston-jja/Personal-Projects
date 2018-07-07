import Adafruit_CharLCD as LCD
import time as t

lcd_rs  = 25
lcd_en  = 24
lcd_d4  = 23 
lcd_d5  = 17
lcd_d6  = 18
lcd_d7  = 22
lcd_columns = 16
lcd_rows = 2
lcd_backlight = 4

lcd = LCD.Adafruit_CharLCD(lcd_rs,lcd_en,lcd_d4,lcd_d5,lcd_d6,lcd_d7,lcd_columns,lcd_rows,lcd_backlight)
# Have not used python in such a long time
status = 'Working'

while (1):  
    lcd.message('Hello World')
    t.sleep(5.0)
    lcd.clear()
    t.sleep(1.0)
    lcd.message('LCD Status\n'+status)
    t.sleep(5.0)
    lcd.clear()

