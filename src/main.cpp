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
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include "airQual.h"



#define DHT_SENSOR_PIN  D7 // The ESP8266 pin D7 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11

#define Motion_Sensor_PIN  D5 // Sets the motion sensor as pin  
int motion_state = LOW;              // Initial state of the room. 
int motion_val = 0;                  // Intial Value of the Sensor.




DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);


// WiFi Variables
WiFiClient client;

// DHT11 Variables
float temperature = 0;  // Stores temperature in Celsius
float humidity  = 0;        // Stores  humidity   in percent




// Function Declarations
void temp_humi(float *temperature, float *humi);
void Motion_Sensor(int *motion_state, int *motion_val);



void setup() {
  Serial.begin(11500);
  dht_sensor.begin(); // initialize the DHT sensor
  pinMode(Motion_Sensor_PIN, INPUT); // PIR motion sensor sat as input. 

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


  temp_humi(&temperature, &humidity);
  airQual_measurement(&temperature, &humidity);
  Motion_Sensor(&motion_state, &motion_val);
  delay(10000);
}






/**
 *
 * @author Markus Kenno
 * @brief Reads the temperature in "°dC" [Deci-celcius] and hunitity in "%"" (percentage) using a DH11 module.
 *
 * @param temperature reads the temperature as a float.
 * @param humidity reads the humitity as a float.
 */
void temp_humi(float *temperature, float *humidity){
    *humidity  = dht_sensor.readHumidity();
    *temperature = dht_sensor.readTemperature();
    //Prints to Serial.
    Serial.print("Humidity: ");
    Serial.print(*humidity);
    Serial.print("%");
    Serial.print("  |  ");
    Serial.print("Temperature: ");
    Serial.print(*temperature);
    Serial.println("°dC");
  // wait a 2 seconds between readings
  delay(2000);
}

/**
 * @author Markus Kenno
 * @brief Detects if there is motion using a HC-SR501 PIR MOTION DETECTOR.
 * @param motion_state motion state of the room.
 * @param motion_val motion value. Reads the motion sensors value.
 */

void Motion_Sensor(int *motion_state, int *motion_val){
    *motion_val = digitalRead(Motion_Sensor_PIN);   //value of motion sensor by reading pin 5.
  //checks if there is motion and if there previous was no motion. 
  if  (*motion_val == HIGH) {     
    delay(500);           
    if (*motion_state == LOW) {
      Serial.println("  Motion detected "); 
      *motion_state = HIGH; //Motion detected.
    }
  } 
  // When motion stops.
  else {          
      if  (*motion_state == HIGH){
        Serial.println("Motion Stopped");
        delay(500);
        *motion_state = LOW; //Motion stopped in the room.
    }
  }
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
