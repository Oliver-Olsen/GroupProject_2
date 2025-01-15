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
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

#define DHT_SENSOR_PIN  D7 // The ESP8266 pin D7 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);


// read temperature in Celsius and convert to deci-celcius
float temperature = 0;
// read humidity as float
float humi  = 0;

void temp_humi(float *temperature, float *humi);

  /*
  * CODE STRUCTURE
  *
  * MEASURED DATA (TEMP/HUM)
  * MEASURE CO2
  * UPLOAD TO THINKSPEAK
  * GET CLOAD DATA
  * HANDLE/ACT ON DATA
  * 
  * 
  * 
  */
 

void setup() {
dht_sensor.begin(); // initialize the DHT sensor
  
}

void loop() {
  temp_humi(&temperature, &humi);
}

void temp_humi(float *temperature, float *humi){
  *humi  = dht_sensor.readHumidity();
  *temperature = dht_sensor.readTemperature();
    Serial.print("Humidity: ");
    Serial.print(*humi);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Temperature: ");
    Serial.print(*temperature);
    Serial.println("°dC");
  // wait a 2 seconds between readings
  delay(2000);
}
