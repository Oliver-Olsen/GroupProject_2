/**
 * @file main.cpp
 * @author
 * @brief
 * @version 0.1
 * @date 2025-01-14
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
 * @author Oliver olsen
 * @brief Init of sensors and modules
 * @section Inits the correct elements, depending on if the station is on the recieving end or sending end
 */
void setup() {

    Serial.begin(115200);
    wifi_init();

    receiverModule_init();

    Serial.begin(115200);
}



/**
 * @author Oliver Olsen
 * @brief Updates ThingSpeak or gets data from ThingSpeak
 * @section Updates ThingSpeak every 15 seconds if sending station. If receiving end, gets data every 15 seconds.
 */
void loop()
{
    Serial.println(update_web);
switch (update_web)
    {
    case 5:
    case 6:
    case 7:
        receiverModule_update(update_web);


    default:
        break;
    }

    if (update_web >= 7)
    {
        update_web = 4;
        Serial.println(update_web);
    }

    delay(seconds_15);
    update_web++;

    Serial.print(".");
}

