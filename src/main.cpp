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
#include "airQual.h"
#include "tempHumi.h"
#include "motionSensor.h"
#include "dataLCD.h"
#include "recieverModule.h"


#define SENDING_STATION   true


float temperature = 0;
float humidity    = 0;
float airquality  = 0;
bool motion_state = false;  // Initial state of the room.
bool motion_val   = false;  // Intial Value of the Sensor.
int windowCh = 5;
int heaterCh = 7;
int lightCh = 6;


unsigned short int seconds_15 = 15000; // ThingSpeak read/write speed (free subscription)


int update_web = 0;


/**
 * @author Oliver olsen
 * @brief Init of sensors and modules
 * @section Inits the correct elements, depending on if the station is on the recieving end or sending end
 */
void setup() {

  //Serial.begin(115200);
    wifi_init();
    motionSensor_init(); // PIR motion sensor sat as input.
    tempHumi_Init();
    dataLCD_setup();

    receiverModule_init(windowCh, heaterCh, lightCh);


  //Serial.println("Setup Complete");
}



/**
 * @author Oliver Olsen
 * @brief Updates ThingSpeak or gets data from ThingSpeak
 * @section Updates ThingSpeak every 15 seconds if sending station. If receiving end, gets data every 15 seconds.
 */
void loop()
{
  //Serial.print("Loop count");
  //Serial.println(update_web);

  //if (SENDING_STATION == true){

    switch (update_web)
    {
    case THINGSPEAK_AIRQUALITY:
        tempHumi_read(&temperature, &humidity);
        airQual_measurement(&temperature, &humidity);
        dataLCD_print(airQual_get_Value(), THINGSPEAK_AIRQUALITY);
        sendData_fieldValue(THINGSPEAK_AIRQUALITY, airQual_get_Value());
        break;

    case THINGSPEAK_MOTION:
        motionSensor_detect(&motion_state, &motion_val);
        sendData_fieldValue(THINGSPEAK_MOTION, 1);
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

    if (update_web >= THINGSPEAK_MAX)
    {
        update_web = 0;
    }
        delay(seconds_15);
        update_web++;
}