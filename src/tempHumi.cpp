/**
 * @file tempHumi.cpp
 * @author Oliver Olsen
 * @brief Handles the temp/humi measurement
 * @section Moved to a seperate .h file. This clears up the main function, and allows us to controll the functions easier.
 * @version 0.1
 * @date 2025-01-16
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include "tempHumi.h"

#define DHT_SENSOR_PIN  D7      // The ESP8266 pin D7 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);


/**
 * @author Oliver Olsen
 * @brief Init
 */
void tempHumi_Init()
{
    dht_sensor.begin();
}


/**
 *
 * @author Markus Kenno
 * @brief Reads the temperature in "°C" [Celcius] and humidity in "%"" (percentage) using a DH11 module.
 *
 * @param temperature reads the temperature as a float.
 * @param humidity reads the humidity as a float.
 */
void tempHumi_read(float *temperature, float *humidity)
{
    *temperature = dht_sensor.readTemperature();
    *humidity = dht_sensor.readHumidity();
}
