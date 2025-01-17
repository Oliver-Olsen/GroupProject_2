/**
 * @file main.cpp
 * @author your name (you@domain.com)
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




float temperature = 0;
float humidity    = 0;
float airquality  = 0;
bool motion_state = false;  // Initial state of the room.
bool motion_val   = false;  // Intial Value of the Sensor.



int update_web = 0;


void setup() {
  Serial.begin(11500);

  wifi_init();
  motionSensor_init(); // PIR motion sensor sat as input.
  tempHumi_Init();
  dataLCD_setup();

}



  /*
  * CODE STRUCTURE
  *
  * MEASURED DATA (TEMP/HUM)
  * MEASURE CO2
  * UPLOAD TO THINKSPEAK
  * GET CLOAD DATA
  * HANDLE/ACT ON DATA
  * SCHEDULE THE DIFFERENT TASKS
  *   TEMPERATURE/HUMIDITY EVERY XXX SEC
  *   MQ135 EVERY XXX SEC
  *
  *   UPDATE WEB
  *
  */



void loop()
{

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
    delay(15000);
    update_web++;
}