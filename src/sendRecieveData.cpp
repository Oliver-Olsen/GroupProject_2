/**
 * @file sendData.cpp
 * @author Oliver Olsen
 * @brief Handles data to be sent
 * @section Can sent data with the function sendData_payload(). It is similar to senddata() in the transmitter branch
 *
 * @version 0.1
 * @date 2025-01-16
 * @copyright Copyright (c) 2025
 */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include "sendRecieveData.h"

#define CONNECT_PORT      80

#define CHANNEL_NUMBER    2810501UL
const char Read_APIKey[] = "AMPXQDNAKUDP9COD";

const char *ssid  = "Connection Error";
const char *pswrd = "Gasvo012";


// WiFi Variables
WiFiClient client;


/**
 * @author oliver Olsen
 * @brief Wifi ini
 */
void wifi_init()
{
   WiFi.begin(ssid, pswrd);
   ThingSpeak.begin(client);
}

/**
 * @author Oliver Olsen
 * @brief Similar to @p recieveData()
 * @section used to smoothly merge with recieverModule.cpp
 */
void connectThingSpeak()
{
   client.connect("api.thingspeak.com", CONNECT_PORT);
}

/**
 * @author Oliver Olsen
 * @brief Reads the field value
 * @section used to smoothly merge with recieverModule.cpp
 * @param field Decides which data type is received
 * @return int
 */
int readThingSpeak(int field)
{
   return(ThingSpeak.readIntField(CHANNEL_NUMBER, field, Read_APIKey));
}
