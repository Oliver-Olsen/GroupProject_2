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

/* This boolean determines if the code should run as a receiver or transmitter
*/
bool transmitter = false; 

/**
 * @brief Initiates serial for debugging and runs the setup for the relevant code
 * 
 */
void setup() {
    Serial.begin(115200);

    if (transmitter == true) {
        transmitterSetup(); 
    }  else {
        receiverSetup();  
    }  
}

/**
 * @brief Loops through the relevant code for the application
 * 
 */
void loop()
{
    if (transmitter == true) {
        transmitterMain(); 
    }  else {
        receiverMain(); 
    }
}