/**
 * @file receiverMain.cpp
 * @author Nils Linus Metsälä Wulff
 * @brief All the code needed to run the receiver module
 * @version 0.1
 * @date 2025-01-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */



#include <Arduino.h>
#include "sendRecieveData.h"
#include "recieverModule.h"



unsigned short int seconds_15 = 15000; // ThingSpeak read/write speed (free subscription)


int update_web = 5;


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
 * @brief Updates ThingSpeak or gets data from ThingSpeak
 * @section Updates ThingSpeak every 15 seconds if sending station. If receiving end, gets data every 15 seconds.
 */
void receiverMain()
{
   switch(update_web){
       case 5: 
       case 6:
       case 7:
          receiverModule_update(update_web);


       default:
          break;
       }

   if(update_web >= THINGSPEAK_MAX){
      update_web = 4;
      }

   delay(seconds_15);
   update_web++;

   Serial.println(".");
}
