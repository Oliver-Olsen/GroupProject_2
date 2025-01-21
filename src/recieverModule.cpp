/**
 * @file recieverModule.cpp
 * @author Oliver Olsen
 * @brief
 * @version 0.1
 * @date 2025-01-16
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <AccelStepper.h>
#include <Servo.h>
#include "recieverModule.h"
#include "sendRecieveData.h"


/* Pin definitions
*  Four pins are used to control the stepper motor (Heating control)
*  One pin is used to control the servo motor (Window actuation)
*  One pint is used to control the lights
*/
#define IN1 5
#define IN3 7
#define IN2 6
#define IN4 8
#define servoPin 2
#define lightPin 0

#define STEPPER_ANALOG A0

// Motor configuration
#define stepsPerRevolution 32 //The amount of steps in a rotation from the stepper motor
AccelStepper stepper(AccelStepper::FULL4WIRE, 5, 7, 6, 8);
Servo windowControl; //Creates a Servo class called 'windowControl'


typedef struct
{
  int servo;
  int stepper;
  int light;
} Previous_Values;


Previous_Values pv;



void receiverModule_init(void) 
{
  memset(&pv, 0, sizeof(pv));

  stepper.setMaxSpeed(1000); //Sets the stepper motors speed to 10RPM
  windowControl.attach(servoPin); //Attaches the pin 18 to the servo motor class
  pinMode(lightPin, OUTPUT);
}



void receiverModule_update(uint32_t field) 
{
    connectThingSpeak();

    int reading;
    Serial.print(field);
    switch (field)
    {
      case THINGSPEAK_AIRQUALITY:
        reading = readThingSpeak(field); //Reads the relevant ThingSpeak data for the current modules
        if (pv.servo != reading)
        {
          pv.servo = reading;
          servoControl(pv.servo);
        }
        break;

      case THINGSPEAK_TEMPERATURE:
      case THINGSPEAK_HUMIDITY:
        reading = readThingSpeak(field); //Reads the relevant ThingSpeak data for the current modules
        if (pv.stepper != reading)
        {
          pv.stepper = reading;
          stepperControl(pv.stepper);
        }
        break;

      case THINGSPEAK_MOTION:
        reading = readThingSpeak(field); //Reads the relevant ThingSpeak data for the current modules
        if (pv.light != reading)
        {
          pv.light = reading;
          lightControl(pv.light);
        }
        break;
        default:
        
        break;
  }
}

/**
 * @brief Code to control the servo motor
 *
 * @param input
 */
void servoControl(int input) {
  switch (input) {
    case -1: //If the input value is -1, closes the window
    windowControl.write(0); //Sets the target value of the servo to 0°
    break;

    case 1: //If the input value is 1, opens the window
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
  switch (rotations)
  {
  case -1:
    stepper.moveTo(1023);
    stepper.setSpeed(100);
    stepper.runSpeedToPosition();
    break;
    
  case 1:
    stepper.moveTo(0);
    stepper.setSpeed(100);
    stepper.runSpeedToPosition();
    break;
  
  default:
    break;
  }
}

/**
 * @brief Turns on/off the lights
 *
 * @param state
 */
void lightControl(int state) {
  if (state == 0) { //If the input i zero, turns the lights off
    digitalWrite(lightPin, LOW);
  } else { //Otherwise the lights are on
    digitalWrite(lightPin, HIGH);
  }
}