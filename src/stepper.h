/**
 * @file stepper.h
 * @author Nils Linus Metsälä Wulff (s223968@student.dtu.dk)
 * @brief 
 * @version 0.1
 * @date 2025-01-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef STEPPER_H
#define STEPPER_H

//Initializes custom functions
void stepWrite(int step); 
void stepperInit(int IN1, int IN2, int IN3, int IN4); 
void stepperRotate(int rotation); 

#endif // STEPPER_H