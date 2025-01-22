/**
 * @file stepperPlus.cpp
 * @author Nils Linus Metsälä Wulff
 * @brief
 * @version 0.1
 * @date 2025-01-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <Arduino.h>
#include "stepperPlus.h"

/* Preamble with pin definitions and value declarations:
 */

//Defines the amount of steps per revolution
#define SPR    2048

//Creates an array containing pin values
int pins[4] = {
   D5, D6, D7, D8
};

//An integer to keep track of the current step
int step = 0;

//Creates an array containing pin states per step
const int steps[4][4] = {
   { 1, 1, 0, 0 },
   { 0, 1, 1, 0 },
   { 0, 0, 1, 1 },
   { 1, 0, 0, 1 }
};


/**
 * @brief Initializes the stepper function with pin declarations
 *
 */
void stepperInit()
{
   for(int i = 0; i < 4; i++){  //Loops through all the four pins and sets them as OUTPUTS
       pinMode(pins[i], OUTPUT);
       }
}

/**
 * @brief Main function taking an input of the amount rotaions it should perform
 *
 * @param rotation
 */
void stepperRotate(int rotation)
{
   //Checks if the input is positive
   if(rotation > 0){
      for(int i = 0; i < (rotation * SPR); i++){ //While the stepper motor hasn't turned the decided amount it will perfom these steps:
          //1: Check if the step count is above 3, which indicates it has completed a cycle
          if(step > 3){
             //1.5: If it has completed a cycle, resets the step value
             step = 0;
             }
          //2: Sends the current step value to the stepper motor
          stepWrite(step);
          //3: Increments the stepper by 1
          step++;
          //4: Waits for 5ms before next step
          delay(5);
          }
      }

   //Checks if the input is negative
   if(rotation < 0){
      for(int i = (rotation * SPR); i < 0; i++){ //While the stepper motor hasn't turned the decided amount it will perfom these steps:
          //1: Check if the step count is below 0, which indicates it has completed a cycle
          if(step < 0){
             //1.5: If it has completed a cycle, resets the step value
             step = 3;
             }
          //2: Sends the current step value to the stepper motor
          stepWrite(step);
          //3: Decrements the stepper by 1
          step--;
          //4: Waits for 5ms before next step
          delay(5);
          }
      }
}

/**
 * @brief Updates the pin states to match that of the current step
 *
 * @param step
 */
void stepWrite(int step)
{
   for(int i = 0; i < 4; i++){ //Runs a loop four times, updating one pin at a time
       digitalWrite(pins[i], steps[step][i]);
       }
}
