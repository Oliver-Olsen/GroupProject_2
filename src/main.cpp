/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */



#include <Arduino.h>
#include "receiverMain.h"


bool transmitter = true; 

void setup() {
    Serial.begin(115200);
    receiverSetup(); 
    //Transmitter setup
}


void loop()
{
    if (transmitter == true) {
        //Transmitter function
    }  else {
        receiverMain(); 
    }
}