/**
 * @file dataLCD.cpp
 * @author Oliver Olsen
 * @brief Printing data to the LCD using I2C
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "dataLCD.h"


LiquidCrystal_I2C lcd(0x27,20,4);



/**
 * @author Oliver Olsen
 * @brief Init
 * @section Initialization, and lcd layout setup
 */
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



/**
 * 
 * @author Oliver Olsen
 * @brief Prints measured data
 * 
 * @param data sensor measurements
 * @param dataType type of data
 */

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



