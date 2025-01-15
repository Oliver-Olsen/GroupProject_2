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
#include <MQ135.h>


#define MQ_PIN          A0
#define DHT_SENSOR_PIN  D7 // The ESP8266 pin D7 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11



DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
MQ135 mq135_sensor(MQ_PIN);

// DHT11 Variables
float temperature = 0;  // Stores temperature in Celsius
float humi  = 0;        // Stores  humidity   in percent

// MQ135 Variables
float resistance_zero   = 0;
float corrected_zero    = 0;
float resistance        = 0;
float ppm_measured      = 0;
float ppm_corrected     = 0;


// Function Declarations
void temp_humi(float *temperature, float *humi);
void mq135_measurement(float *resistance_zero, float *corrected_zero, float *resistance, float *ppm_measured,  float *ppm_corrected);


 

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
  */


  temp_humi(&temperature, &humi);
  mq135_measurement(&resistance_zero, &corrected_zero, &resistance, &ppm_measured,  &ppm_corrected);
  delay(10000);
}






/**
 * @brief 
 * 
 * @param temperature reads the temperature as a float.
 * @param humi reads the humitity as a float.
 */
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




/**
 * @brief Measures the air quality in ppm. Sensor is calibrated, each time
 * 
 * @param resistance_zero   Measures the lowest resistance
 * @param corrected_zero    Correction of the measured lowest resistance
 * @param resistance        Measures the resistance
 * @param ppm_measured      Measured ppm
 * @param ppm_corrected     Correction of measured ppm. This is the variable we need/use
 */
void mq135_measurement(float *resistance_zero, float *corrected_zero, float *resistance, float *ppm_measured,  float *ppm_corrected)
{
  *resistance_zero = mq135_sensor.getRZero();
  *corrected_zero  = mq135_sensor.getCorrectedResistance(temperature, humi);
  *resistance      = mq135_sensor.getResistance();
  *ppm_measured    = mq135_sensor.getPPM();
  *ppm_corrected   = mq135_sensor.getCorrectedPPM(temperature, humi);

  
  Serial.print(*ppm_corrected);
  Serial.println(" ppm");
  
}