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




  /*
  * CODE STRUCTURE
  *
  * MEASURED DATA (TEMP/HUM)
  * MEASURE CO2
  * UPLOAD TO THINKSPEAK
  * GET CLOAD DATA
  * HANDLE/ACT ON DATA
  */


#include <Arduino.h>
#include "sendData.h"
#include "airQual.h"
#include "tempHumi.h"
#include "motionSensor.h"




float temperature = 0;
float humidity    = 0;
float airquality  = 0;
bool motion_state = false;  // Initial state of the room. 
bool motion_val   = false;  // Intial Value of the Sensor.






void setup() {
  Serial.begin(11500);

  motionSensor_init(); // PIR motion sensor sat as input. 
  tempHumi_Init();

}

void loop() {

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
  tempHumi_read(&temperature, &humidity);
  airQual_measurement(&temperature, &humidity);
  motionSensor_detect(&motion_state, &motion_val);
  delay(10000);
}