/**
 * @file recieverModule.h
 * @author Nils
 * @brief 
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef RECIEVERMODULE_H
#define RECIEVERMODULE_H

//Initializes custom functions
void receiverModule_init(int windowCh, int heaterCh, int lightCh); 

void receiverModule_update(const int channelID, const int APIKey); 

void servoControl(int input); 

void stepperControl(int rotations); 

void lightControl(int state); 

#endif //RECIEVERMODULE_H