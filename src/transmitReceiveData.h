/**
 * @file transmitReceiveData.h
 * @author Oliver Olsen
 * @brief 
 * @version 0.1
 * @date 2025-01-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef TRANSMITRECEIVEDATA_H
#define TRANSMITRECEIVEDATA_H

#define THINGSPEAK_AIRQUALITY     1
#define THINGSPEAK_MOTION         2
#define THINGSPEAK_TEMPERATURE    3
#define THINGSPEAK_HUMIDITY       4
#define THINGSPEAK_TRANSMITMAX            THINGSPEAK_HUMIDITY

#define THINGSPEAK_WINDOW         5
#define THINGSPEAK_LIGHT          6
#define THINGSPEAK_SPACEHEATER    7
#define THINGSPEAK_RECEIVEMAX            THINGSPEAK_SPACEHEATER

void wifi_init();
void sendData_fieldValue(int field, float data);
void sendData_fieldValue(int field, int data);
void sendData_payload(int field, int data, unsigned long channelID, const char *Write_APIKey);
int readThingSpeak(int field);
void connectThingSpeak();
void sendData_finished();
#endif // TRANSMITRECEIVEDATA_H