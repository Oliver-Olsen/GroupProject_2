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
#include "airQual.h"




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

