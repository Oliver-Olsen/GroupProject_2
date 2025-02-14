/**
 * @file stepperPlus.h
 * @author Nils Linus Metsälä Wulff
 * @brief Functions and guard
 * @version 0.1
 * @date 2025-01-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef STEPPERPLUS_H
#define STEPPERPLUS_H

//Initializes custom functions
void stepWrite(int step);
void stepperInit();
void stepperRotate(int rotation);

#endif // STEPPERPLUS_H
