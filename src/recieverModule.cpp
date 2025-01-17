/**
 * @file recieverModule.cpp
 * @author Nils Linus Metsälä Wulff, s223968@student.dtu.dk
 * @brief 
 * @version 0.1
 * @date 2025-01-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//Libraries used: 
#include <ESP8266WiFi.h>
#include <Stepper.h>
#include <Servo.h>
#include <ThingSpeak.h>
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

// Motor configuration
#define stepsPerRevolution 2038 //The amount of steps in a rotation from the stepper motor
Stepper tempControl = Stepper(stepsPerRevolution, IN1, IN3, IN2, IN4); //Creates a Stepper class called 'tempControl'
Servo windowControl; //Creates a Servo class called 'windowControl'


// Values for the active elements
//The ThingSpeak channel IDs of the different elements
int servoChannel = 0; 
int stepperChannel = 0; 
int lightChannel = 0; 

//The current values read from ThingSpeak
int servoD = 0; 
int stepperD = 0; 
int lightD = 0; 

//The previous values from ThingSpeak
int servoP = 0; 
int stepperP = 0; 
int lightP = 0; 

//Creates an array from all the different values to ease optimization
int data[3][3] = {
  {servoD, servoP, servoChannel}, 
  {stepperD, stepperP, stepperChannel}, 
  {lightD, lightP, lightChannel}
}; 

//Timer for delay
unsigned long timer = 0; 


/**
 * @brief Sets up initial values
 * 
 * @param windowCh 
 * @param heaterCh 
 * @param lightCh 
 */
void init(int windowCh, int heaterCh, int lightCh) {
  //Assigns the correct channel values
  servoChannel = windowCh; 
  stepperChannel = heaterCh; 
  lightChannel = lightCh; 

  tempControl.setSpeed(10); //Sets the stepper motors speed to 10RPM
  windowControl.attach(servoPin); //Attaches the pin 18 to the servo motor class
  pinMode(lightPin, OUTPUT); 
}


/**
 * @brief Updates all the attached modules
 * 
 * @param channelID 
 * @param APIKey 
 */
void update(const int server, const int channelID, char * APIKey, unsigned long delay) {
  if ((millis() + timer) >= delay) { //Inserts a non-blocking delay
    connectTingSpeak();

    for (int i = 0; i < 3; i++) { //Loopes through all modules
        data[i][0] = readThingSpeak(channelID, data[i][2], APIKey); //Reads the relevant ThingSpeak data for the current modules

        if (data[i][0] != data[i][1]) { //Checks if an update has occured in the data for the current module
        switch (i) { //Runs different function depending on what module is currently active
            case 0: 
            servoControl(data[i][0]); //Runs the servo motor
            break;

            case 1: 
            stepperControl(data[i][0]); //Runs the stepper motor
            break; 

            case 2: 
            lightControl(lightD); //Switches the light
            break; 

            default: 
            break; 
        }

        data[i][1] = data[i][0]; //Updates the previous value
        }
    }

    sendData_finished(); //Ends WiFi communication

    timer = millis(); //Updates the timer
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
    delay(3000); //Waits for three seconds while the servo turns
    break; 

    case 1: //If the input value is 1, opens the window
    windowControl.write(180); //Sets the target value of the servo to 180°
    delay(3000); //Waits for three seconds while the servo turns
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
  tempControl.step(stepsPerRevolution * rotations); //Rotates the stepper motor for a defined number of rotations
  delay(1000); //Waits for a second before continuing
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