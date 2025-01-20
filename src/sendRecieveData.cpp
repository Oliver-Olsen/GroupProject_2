/**
 * @file sendData.cpp
 * @author Oliver Olsen
 * @brief Handles data to be sent
 * @section Can sent data with the function sendData_payload()
 *
 * @version 0.1
 * @date 2025-01-16
 * @copyright Copyright (c) 2025
 */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include "sendRecieveData.h"

#define CONNECT_PORT 80

#define CHANNEL_NUMBER 2810501UL
const char Read_APIKey[] = "AMPXQDNAKUDP9COD";

const char* ssid = "Connection Error";
const char* pswrd = "Gasvo012";


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
 * @see recievedata()
 */
void connectThingSpeak()
{
  client.connect("api.thingspeak.com", CONNECT_PORT);
}


/**
 * @brief Similar to @p recieveData()
 * @see recieveData()
 * @section used to smoothly merge with recieverModule.cpp
 * @param field
 * @param channelID
 * @param Read_APIKey
 * @return int
 */
int readThingSpeak(int field)
{
  return ThingSpeak.readIntField(CHANNEL_NUMBER, field, Read_APIKey);
}

