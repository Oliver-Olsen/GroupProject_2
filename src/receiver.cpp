/**
 * @file receiver.cpp
 * @author Nils Linus Metsälä Wulff
 * @brief All the code needed to run the receiver module
 * @version 0.1
 * @date 2025-01-22
 *
 * @copyright Copyright (c) 2025
 *
 */



#include <Arduino.h>
#include "transmitReceiveData.h"
#include "recieverModule.h"



unsigned short int seconds_15 = 15000; // ThingSpeak read/write speed (free subscription)


int receive_web = THINGSPEAK_WINDOW;


/**
 * @brief Sets up all the necessary function for the receiver module
 *
 */
void receiverSetup()
{
   wifi_init();
   receiverModule_init();
}

/**
 * @author Oliver Olsen
 * @brief Gets data from ThingSpeak every 15 seconds
 * @section Loop counter @param receive_web decides which data, to update in @p receiverModule_update()
 */
void receiverMain()
{
   switch(receive_web){
       case THINGSPEAK_WINDOW:
       case THINGSPEAK_LIGHT:
       case THINGSPEAK_SPACEHEATER:
          receiverModule_update(receive_web);


       default:
          break;
       }

   if(receive_web >= THINGSPEAK_RECEIVEMAX){
      receive_web = THINGSPEAK_WINDOW;
      }

   delay(seconds_15);
   receive_web++;

   Serial.println(".");
}
