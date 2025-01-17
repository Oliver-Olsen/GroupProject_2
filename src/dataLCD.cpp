#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "dataLCD.h"


LiquidCrystal_I2C lcd(0x27,20,4);


void dataLCD_setup()
{
    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("N/A");
    lcd.setCursor(5, 0);
    lcd.print("ppm");

    lcd.setCursor(9, 0);
    lcd.print("N/A");
    lcd.setCursor(13, 0);
    lcd.print((char)223+"C");

    lcd.setCursor(0, 1);
    lcd.print("N/A");
    lcd.setCursor(5, 1);
    lcd.print("%  humidity");
}


void dataLCD_print(float data, int dataType)
{
    switch (dataType)
    {
    case 1:
        lcd.setCursor(0, 0);
        lcd.print(data);
        break;
    
    case 2:
        lcd.setCursor(9, 0);
        lcd.print(data);
        break;

    case 3:
        lcd.setCursor(0, 1);
        lcd.print(data);
        break;
    
    default:
        break;
    }
}



