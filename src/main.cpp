/**
 * @file main.cpp
 * @author Nils Linus Metsälä Wulff
 * @brief 
 * @version 0.1
 * @date 2025-01-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */



#include <Arduino.h>
#include "receiver.h"
#include "transmitter.h"


bool transmitter = true; 

void setup() {
    Serial.begin(115200);
    receiverSetup(); 
    transmitterSetup(); 
}


void loop()
{
    if (transmitter == true) {
        transmitterMain(); 
    }  else {
        receiverMain(); 
    }
}