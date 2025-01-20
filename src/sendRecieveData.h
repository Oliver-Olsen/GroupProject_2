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




/**
 * @brief Function declarations
 *
 */
void wifi_init();
void connectThingSpeak();
int readThingSpeak(int field);

#endif // SENDRECIEVEDATA_H