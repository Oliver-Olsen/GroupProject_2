/**
 * @file recieverModule.cpp
 * @author Oliver Olsen & Nils Linus Metsälä Wulff
 * @brief Main code used for contolling the recieving end of the system
 * @version 0.1
 * @date 2025-01-16
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <Servo.h>
#include "recieverModule.h"
#include "sendRecieveData.h"
#include "stepperPlus.h"


/* Pin definitions
*  Four pins are used to control the stepper motor (Heating control)
*  One pin is used to control the servo motor (Window actuation)
*  One pint is used to control the lights
*/
 
const int servoPin = D2; 
const int lightPin = D0; 

// Motor configuration
Servo windowControl; //Creates a Servo class called 'windowControl'

int pServo = 0; 
int pStepper = 0; 
int pLight = 0; 
int pRotation = 0;


/**
 * @brief Performs all the necessary setup for the receiver module to work correctly
 * 
 */
void receiverModule_init(void) 
{
  stepperInit(); 
  windowControl.attach(servoPin); //Attaches the pin 2 to the servo motor class
  pinMode(lightPin, OUTPUT);
}

/**
 * @brief Reads the data from 'field' and runs the relevant functions for that field 
 * 
 * @param field 
 */
void receiverModule_update(uint32_t field) 
{
    connectThingSpeak();

    int reading;
    Serial.println(field); //Serial readout used for debugging
    switch (field)
    {
      case THINGSPEAK_WINDOW:
        reading = readThingSpeak(field); //Reads the relevant ThingSpeak data for the current modules
        Serial.println(reading); //Serial readout used for debugging
        pServo = reading;
        servoControl(pServo);
        break;


      case THINGSPEAK_LIGHT:
        reading = readThingSpeak(field); //Reads the relevant ThingSpeak data for the current modules
        Serial.println(reading); //Serial readout used for debugging
        pLight = reading;
        lightControl(pLight);
        break;
        
      case THINGSPEAK_SPACEHEATER:
        reading = readThingSpeak(field); //Reads the relevant ThingSpeak data for the current modules
        Serial.println(reading); //Serial readout used for debugging
        pStepper = reading;
        stepperControl(pStepper);
        break;

      default:
        
        break;
  }
}

/**
 * @brief Controls the servo motor
 *
 * @param input
 */
void servoControl(int input) {
  switch (input) {
    case -1: //If the input value is -1, closes the window
    Serial.println("Window close"); //Serial readout used for debugging
    windowControl.write(0); //Sets the target value of the servo to 0°
    break;

    case 1: //If the input value is 1, opens the window
    Serial.println("Window open"); //Serial readout used for debugging
    windowControl.write(180); //Sets the target value of the servo to 180°
    break;

    default: //All other values don't change the window status
    break;
  }
}

/**
 * @brief Controls the stepper motor
 *
 * @param steps
 * @param rotations
 */
void stepperControl(int rotations) { 
  if (rotations != pRotation) {//Checks if a new value has been recieved
    switch (rotations)
    {
    case -1: 
      Serial.println("CCW"); //Serial readout used for debugging
      stepperRotate(1); 
      break;
      
    case 1:
      Serial.println("CW"); //Serial readout used for debugging
      stepperRotate(-1); 
      break;
    
    default:
      break;
    }
    pRotation = rotations; //Updates previous value
  }
}

/**
 * @brief Turns on/off the lights
 *
 * @param state
 */
void lightControl(int state) {
  if (state == 0) { //If the input i zero, turns the lights off
    Serial.println("Light OFF"); //Serial readout used for debugging
    digitalWrite(lightPin, LOW);
  } else { //Otherwise the lights are on
    Serial.println("Light ON"); //Serial readout used for debugging
    digitalWrite(lightPin, HIGH);
  }
}