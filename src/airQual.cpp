/**
 * @file airQual.cpp
 * @author Oliver Skou Olsen
 * @brief   Measures the Air Quality (MQ135)
 * @version 0.1
 * @date 2025-01-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <Arduino.h>
#include <MQ135.h>
#include "airQual.h"

#define MQ_PIN          A0



MQ135 mq135_sensor(MQ_PIN);



// MQ135 Variables
typedef struct
{
    float resistance_zero;
    float corrected_zero;
    float resistance;
    float ppm_measured;
    float ppm_corrected;
} mq135_env_t;


mq135_env_t mq135_data;




/**
 * @brief Initializes variables
 *
 */
void airQual_init()
{
    mq135_data.resistance_zero   = 0;
    mq135_data.corrected_zero    = 0;
    mq135_data.resistance        = 0;
    mq135_data.ppm_measured      = 0;
    mq135_data.ppm_corrected     = 0;
}


/**
 * @brief Measures the air quality in ppm. Sensor is calibrated each reading
 *
 * @param temperature Measured temperature
 * @param humidity    Measured humidity
 */

void airQual_measurement(float *temperature, float *humidity)
{
    mq135_data.resistance_zero = mq135_sensor.getRZero();
    mq135_data.corrected_zero  = mq135_sensor.getCorrectedResistance(*temperature, *humidity);
    mq135_data.resistance      = mq135_sensor.getResistance();
    mq135_data.ppm_measured    = mq135_sensor.getPPM();
    mq135_data.ppm_corrected   = mq135_sensor.getCorrectedPPM(*temperature, *humidity);



    Serial.print(mq135_data.ppm_corrected);
    Serial.println(" ppm");

}



float airQual_get_Value()
{
    return mq135_data.ppm_corrected;
}