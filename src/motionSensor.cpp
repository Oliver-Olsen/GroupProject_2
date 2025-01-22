/**
 * @file motionSensor.cpp
 * @author Oliver Olsen & Markus Kenno
 * @brief Handles the motion detection
 * @section This
 * @version 0.1
 * @date 2025-01-16
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <Arduino.h>
#include "motionSensor.h"


#define MOTIONSENSOR_PIN    D5 // Sets the motion sensor as pin


/**
 * @brief Initialization
 * @author Oliver Olsen
 */
void motionSensor_init()
{
   pinMode(MOTIONSENSOR_PIN, INPUT);
}

/**
 * @author Markus Kenno
 * @brief Detects motion
 * @section  We are using a HC-SR501 PIR MOTION DETECTOR.
 * @param motion_state motion state of the room.
 * @param motion_val motion value. Reads the motion sensors value.
 */
void motionSensor_detect(bool *motion_state, bool *motion_val)
{
   *motion_val = digitalRead(MOTIONSENSOR_PIN);    //value of motion sensor by reading pin 5.

   //checks if there is motion and if there previous was no motion.
   if(*motion_val == HIGH){
      if(*motion_state == LOW){
         *motion_state = HIGH;    //Motion detected.
         }
      }
   // When motion stops.
   else{
       if(*motion_state == HIGH){
          *motion_state = LOW;   //Motion stopped in the room.
          }
       }
}