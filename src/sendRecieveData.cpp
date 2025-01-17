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
#include <Wifi.h>
#include <ThingSpeak.h>
#include "sendRecieveData.h"



unsigned long channelID = 2810501;
const char Write_APIKey[] = "6475AR5ZBC5ZU3A7";
const char Read_APIKey[] = "AMPXQDNAKUDP9COD";

const char* ssid = "Connection Error";
const char* pswrd = "Gasvo012";



// WiFi Variables
WiFiClient client;


void wifi_init()
{
  WiFi.begin(ssid, pswrd);
}


void sendData_fieldValue(int port, float data)
{
  int value = (int)(data * 100);
  sendData_payload(port, value, channelID, Write_APIKey);
}


void sendData_fieldValue(int port, int data)
{
  sendData_payload(port, data, channelID, Write_APIKey);
}


/**
* @author Marcus & Emil
* @brief sends data to our Thingspeak cloud (Requires WiFi.Begin in setup)
* @section Port 1 = CO2 , Port 2 = Sound, Port 3 = Temperature, Port 4 Humidity
* @param port which Thingspeak field the data is sent to (1-8)
* @param data data to be sent
* @param channelID The channel ID
* @param Write_APIKey The key to write to Thingspeak
*/
void sendData_payload(int port,int data, unsigned long channelID,const char *Write_APIKey){
  ThingSpeak.begin(client);
  client.connect("api.thingspeak.com", 80); //connect(URL, Port)
  ThingSpeak.setField(port, data);
  ThingSpeak.writeFields(channelID, Write_APIKey);
  // Delay of 5 seconds to make sure the data is recieved correctly by thingspeak
  //delay(5000);
}


/**
* @author Marcus & Emil
* @brief recieves data from Thingspeak (Requires WiFi.Begin in setup)
* @param port which Thingspeak field the data is read from (1-8)
* @param channelID The channel ID
* @param Read_APIKey The key to read to Thingspeak
* Port 5 = window motor control, port 6 = sound led control
*/
int recievedata(int port,long channelID,const char *Read_APIKey){
  ThingSpeak.begin(client);
  client.connect("api.thingspeak.com", 80); //connect(URL, Port)
  return ThingSpeak.readIntField(channelID, port, Read_APIKey); //returns the read data from Thingspeak
  //Delay of 30 seconds to avoid using too many
  //delay(30000);
}



/**
 * @author Oliver Olsen
 * @brief Similar to @p recieveData()
 * @section used to smoothly merge with recieverModule.cpp
 * @see recievedata()
 */
void connectTingSpeak()
{
  ThingSpeak.begin(client);
  client.connect("api.thingspeak.com", 80);
}


/**
 * @brief Similar to @p recieveData()
 * @see recieveData()
 * @section used to smoothly merge with recieverModule.cpp
 * @param port 
 * @param channelID 
 * @param Read_APIKey 
 * @return int 
 */
int readThingSpeak(int port, long channelID, const char *Read_APIKey)
{
  return ThingSpeak.readIntField(channelID, port, Read_APIKey);
}





/**
 * @brief Ends the connection
 * @author Oliver Olsen
 */
void sendData_finished()
{
    client.stop();
}