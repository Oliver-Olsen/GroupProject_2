#ifndef RECIEVERMODULE_H
#define RECIEVERMODULE_H

//Initializes custom functions
void init(int windowCh, int heaterCh, int lightCh); 

void update(const int channelID, const int APIKey); 

void servoControl(int input); 

void stepperControl(int rotations); 

void lightControl(int state); 

#endif //RECIEVERMODULE_H