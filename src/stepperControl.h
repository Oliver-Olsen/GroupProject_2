/**
 * @file stepperControl.h
 * @author Nils Linus Metsälä Wulff (s223968@student.dtu.dk)
 * @brief 
 * @version 0.1
 * @date 2025-01-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef STEPPERCONTROL_H
#define STEPPERCONTROL_H

//Initializes custom functions
void stepWrite(int step); 
void stepperInit(); 
void stepperRotate(int rotation); 

#endif // STEPPERCONTROL_H