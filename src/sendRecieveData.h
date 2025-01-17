/**
 * @file sendData.h
 * @author Oliver Olsen
 * @brief Function forward declarations and safety declarations
 * @version 0.1
 * @date 2025-01-16
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SENDRECIEVEDATA_H
#define SENDRECIEVEDATA_H




#define THINGSPEAK_TEMPERATURE      3
#define THINGSPEAK_HUMIDITY         4
#define THINGSPEAK_AIRQUALITY       1
#define THINGSPEAK_MOTION           2
#define THINGSPEAK_MAX              THINGSPEAK_HUMIDITY




void wifi_init();
void sendData_fieldValue(int port,float data);
void sendData_fieldValue(int port,int data);
void sendData_payload(int port,int data, unsigned long channelID,const char *Write_APIKey);
int recievedata(int port,long channelID,const char *Read_APIKey);
void connectTingSpeak();
int readThingSpeak(int port, long channelID, const char *Read_APIKey);
void sendData_finished();

#endif // SENDRECIEVEDATA_H