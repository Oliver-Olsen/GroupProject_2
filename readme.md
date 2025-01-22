# Setup Guide


## INSTRUCTIONS:

* Change the ssid and pswrd in the sendData or receiveData. Depending on if you want to transmit or receive data.
* Change the API key in sendData or receiveData, depending on if a read/write API key is needed for the ThingSpeak channel.. 
* Change the ChannelID to the ThingSpeak  channel you wish to send data to.
* In main.cpp change the bool transmitter to true if, you wish to send data or false for receiveing data.

# Optimal Guide
We HIGHLY reccomend that the ESP8266 that is the transmitter (sensor side) is run with the code in the transmitter branch, and the receiver (motor side and lights) is run with the receiver branch code. This way we won't have any junk file uploaded.
The main branch is everything merged, and also works.


