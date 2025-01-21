/**
 * @file motionSensor.h
 * @author Oliver Olsen
 * @brief Function forward declarations and safety declarations
 * @version 0.1
 * @date 2025-01-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H


/**
 * @brief Function declarations
 */
void motionSensor_init();
void motionSensor_detect(bool *motion_state, bool *motion_val);

#endif // MOTIONSENSOR_H