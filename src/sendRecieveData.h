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

void sendData_payload(int port,int data, unsigned long channelID,const char *Write_APIKey);
void sendData_finished();

#endif // SENDRECIEVEDATA_H