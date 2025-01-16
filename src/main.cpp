/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-01-14
 *
 * @copyright Copyright (c) 2025
 *
 */




  /*
  * CODE STRUCTURE
  *
  * MEASURED DATA (TEMP/HUM)
  * MEASURE CO2
  * UPLOAD TO THINKSPEAK
  * GET CLOAD DATA
  * HANDLE/ACT ON DATA
  */


#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include "airQual.h"
#include "tempHumi.h"
#include "motionSensor.h"


// WiFi Variables
WiFiClient client;


float temperature = 0;
float humidity    = 0;
float airquality  = 0;
bool motion_state = false;  // Initial state of the room. 
bool motion_val   = false;  // Intial Value of the Sensor.





void setup() {
  Serial.begin(11500);

  motionSensor_init(); // PIR motion sensor sat as input. 
  tempHumi_Init();

}

void loop() {

  /*
  * CODE STRUCTURE
  *
  * MEASURED DATA (TEMP/HUM)
  * MEASURE CO2
  * UPLOAD TO THINKSPEAK
  * GET CLOAD DATA
  * HANDLE/ACT ON DATA
  * SCHEDULE THE DIFFERENT TASKS
  *   TEMPERATURE/HUMIDITY EVERY XXX SEC
  *   MQ135 EVERY XXX SEC
  *
  *   UPDATE WEB
  *   
  */
  tempHumi_read(&temperature, &humidity);
  airQual_measurement(&temperature, &humidity);
  motionSensor_detect(&motion_state, &motion_val);
  delay(10000);
}














/**
* @author Marcus & Emil
* @brief sends data to our Thingspeak cloud (Requires WiFi.Begin in setup)
* @param port which Thingspeak field the data is sent to (1-8)
* @param data the data send
* @param channelID The channel ID
* @param Write_APIKey The key to write to Thingspeak
* Port 1 = CO2 , Port 2 = Sound, Port 3 = Temperature, Port 4 Humidity
*/
void senddata(int port,int data, unsigned long channelID,const char *Write_APIKey){
  ThingSpeak.begin(client);
  client.connect("api.thingspeak.com", 80); //connect(URL, Port)
  ThingSpeak.setField(port, data);
  ThingSpeak.writeFields(channelID, Write_APIKey);
  // Delay of 30 seconds to make sure the data is recieved correctly by thingspeak
  delay(30000);
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
  return ThingSpeak.readIntField(channelID,port,Read_APIKey); //returns the read data from Thingspeak
  //Delay of 30 seconds to avoid using too many 
  delay(30000);
}
