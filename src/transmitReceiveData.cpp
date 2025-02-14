/**
 * @file sendData.cpp
 * @author Oliver, Marcus & Emil
 * @brief Handles data to be sent
 * @section Can sent data with the function sendData_payload()
 *
 * @version 0.1
 * @date 2025-01-16
 * @copyright Copyright (c) 2025
 */
#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>
#include "transmitReceiveData.h"

#define CONNECT_PORT              80        // ThingSpeak Port
#define SEND_CHANNEL_NUMBER       1234567UL // replace numers 1234567 with the channel number of Thingspeak
#define RECEIVE_CHANNEL_NUMBER    1234567UL // replace numers 1234567 with the channel number of Thingspeak
const char Write_APIKey[] = "WRITE_KEY";
const char Read_APIKey[]  = "READ_KEY";

const char *ssid  = "WIFI_NAME";
const char *pswrd = "WIFI_PASSWORD";


// WiFi Variables
WiFiClient client;


/**
 * @author Oliver Olsen
 * @brief Wifi init and ThingSpeak init
 */
void wifi_init()
{
   WiFi.begin(ssid, pswrd);
   ThingSpeak.begin(client);
}

/**
 * @author Oliver Olsen
 * @brief Handles float to int
 *
 * @see works with @p sendData_fieldValue()
 * @param field
 * @param data
 */
void sendData_fieldValue(int field, float data)
{
   int value = (int)(data * 100);

   sendData_payload(field, value, SEND_CHANNEL_NUMBER, Write_APIKey);
}

/**
 * @author Oliver Olsen
 * @brief Handles int to int
 *
 * @section The two functions @p sendData_fieldValue() and @p sendData_fieldValue(). Deppending on if it's an int or a float, the correct function will be chosen automatically.
 * @see works with @p sendData_fieldValue()
 * @param field
 * @param data
 */
void sendData_fieldValue(int field, int data)
{
   sendData_payload(field, data, SEND_CHANNEL_NUMBER, Write_APIKey);
}

/**
 * @author Marcus & Emil
 * @brief sends data to our Thingspeak cloud (Requires WiFi.Begin in setup)
 * @section field 1 = CO2 , field 2 = Sound, field 3 = Temperature, field 4 Humidity
 * @param field which Thingspeak field the data is sent to (1-8)
 * @param data data to be sent
 * @param channelID The channel ID
 * @param Write_APIKey The key to write to Thingspeak
 */
void sendData_payload(int field, int data, unsigned long channelID, const char *Write_APIKey)
{
   connectThingSpeak();
   ThingSpeak.setField(field, data);
   ThingSpeak.writeFields(channelID, Write_APIKey);
   // Delay of 5 seconds to make sure the data is recieved correctly by thingspeak
   //delay(5000);
}

/**
 * @author Oliver Olsen
 * @brief Reads the field value
 * @section used to smoothly merge with recieverModule.cpp
 * @see similar to @p sendData_payload
 * @param field Decides which data type is received
 * @return int
 */
int readThingSpeak(int field)
{
   return(ThingSpeak.readIntField(RECEIVE_CHANNEL_NUMBER, field, Read_APIKey));
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
 * @brief Ends the connection
 * @author Oliver Olsen
 * @section Currently not used
 */
void sendData_finished()
{
   client.stop();
}
