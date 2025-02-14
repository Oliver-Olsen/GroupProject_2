/**
 * @file transmitter.cpp
 * @author Oliver Olsen
 * @brief
 * @version 0.1
 * @date 2025-01-14
 *
 * @copyright Copyright (c) 2025
 *
 */



#include <Arduino.h>
#include "transmitter.h"
#include "transmitReceiveData.h"
#include "airQual.h"
#include "tempHumi.h"
#include "motionSensor.h"
#include "dataLCD.h"
#include "debug.h"


float temperature  = 0;
float humidity     = 0;
float airquality   = 0;
bool  motion_state = false; // Initial state of the room.
bool  motion_val   = false; // Intial Value of the Sensor.


unsigned short int seconds_30 = 30000; // ThingSpeak read/write speed is 15 seconds(free subscription)


int transmit_web = 0;


/**
 * @author Oliver olsen
 * @brief Init of sensors and modules
 * @section Inits the correct elements, depending on if the station is on the recieving end or sending end
 */
void transmitterSetup()
{
#ifdef SERIAL_TRACE
   Serial.begin(115200);
#endif

   wifi_init();
   motionSensor_init();     // PIR init.
   tempHumi_Init();         // DHT11 init
   dataLCD_setup();         // LCD init
}

/**
 * @author Oliver Olsen
 * @brief Updates ThingSpeak
 * @section Updates ThingSpeak every 30 seconds.
 */
void transmitterMain()
{
   /**
    * @author Oliver Olsen
    * @brief Uodates a sensor pr. 30 seconds
    *@section This means that it will take 2 minutes in total to update all sensor fields. The 30 seconds is to ensure all data is received and no package loss occures.
    */
   switch(transmit_web){
       case THINGSPEAK_AIRQUALITY:
          tempHumi_read(&temperature, &humidity);
          airQual_measurement(&temperature, &humidity);
          dataLCD_print(airQual_get_Value(), THINGSPEAK_AIRQUALITY);
          sendData_fieldValue(THINGSPEAK_AIRQUALITY, airQual_get_Value());
          break;

       case THINGSPEAK_MOTION:
          sendData_fieldValue(THINGSPEAK_MOTION, motion_val);
          break;

       case THINGSPEAK_TEMPERATURE:
          tempHumi_read(&temperature, &humidity);
          dataLCD_print(temperature, THINGSPEAK_TEMPERATURE);
          sendData_fieldValue(THINGSPEAK_TEMPERATURE, temperature);
          break;

       case THINGSPEAK_HUMIDITY:
          tempHumi_read(&temperature, &humidity);
          dataLCD_print(humidity, THINGSPEAK_HUMIDITY);
          sendData_fieldValue(THINGSPEAK_HUMIDITY, humidity);
          break;

       default:
          break;
       }

   // Resets counter, so each sensor/module updates
   if(transmit_web >= THINGSPEAK_TRANSMITMAX){
      transmit_web = 0;
      }

   // Extra motion sensor update, to ensure motion detection is detected
   motionSensor_detect(&motion_state, &motion_val);
   delay(seconds_30);  // Thingspeak delay (15 seconds), 30 seconds just in case
   transmit_web++;
}
