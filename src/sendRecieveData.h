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


// Used in the switch in main and in receiverModule
#define THINGSPEAK_WINDOW           5
#define THINGSPEAK_LIGHT            6
#define THINGSPEAK_SPACEHEATER      7
#define THINGSPEAK_MAX              THINGSPEAK_SPACEHEATER




/**
 * @brief Function declarations
 *
 */
void wifi_init();
void connectThingSpeak();
int readThingSpeak(int field);

#endif // SENDRECIEVEDATA_H