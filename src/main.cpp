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
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include "airQual.h"



#define DHT_SENSOR_PIN  D7 // The ESP8266 pin D7 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11



DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);


// DHT11 Variables
float temperature = 0;  // Stores temperature in Celsius
float humidity  = 0;        // Stores  humidity   in percent




// Function Declarations
void temp_humi(float *temperature, float *humi);



void setup() {
  Serial.begin(11500);
  dht_sensor.begin(); // initialize the DHT sensor

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


  temp_humi(&temperature, &humidity);
  airQual_measurement(&temperature, &humidity);
  delay(10000);
}






/**
 * @brief
 *
 * @param temperature reads the temperature as a float.
 * @param humidity reads the humitity as a float.
 */
void temp_humi(float *temperature, float *humidity){
    *humidity  = dht_sensor.readHumidity();
    *temperature = dht_sensor.readTemperature();
    Serial.print("Humidity: ");
    Serial.print(*humidity);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Temperature: ");
    Serial.print(*temperature);
    Serial.println("°dC");
  // wait a 2 seconds between readings
  delay(2000);
}




