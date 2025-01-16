/**
 * @file tempHumi.h
 * @author Oliver Olsen
 * @brief Function forward declarations and safety declarations
 * @version 0.1
 * @date 2025-01-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef TEMPHUMI_H
#define TEMPHUMI_H

/**
 * @brief Function declarations
 * @see tempHumi.cpp
 */
void tempHumi_Init();
void tempHumi_read(float *temperature, float *humi);


#endif // TEMPHUMI_H