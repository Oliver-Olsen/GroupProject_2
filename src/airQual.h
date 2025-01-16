/**
 * @file airQual.h
 * @author Oliver Olsen
 * @brief Function forward declarations and safety declarations
 * @version 0.1
 * @date 2025-01-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef AIRQUAL_H
#define AIRQUAL_H

/**
 * @brief function declarations
 * @see airQual.cpp
 */
void airQual_init();
void airQual_measurement(float *temperature, float *humidity);
float airQual_get_Value();


#endif // AIRQUAL_H