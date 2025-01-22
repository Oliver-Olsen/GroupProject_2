/**
 * @file debug.h
 * @author Oliver Olsen
 * @brief Used to enable serial print
 * @version 0.1
 * @date 2025-01-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef DEBUG_H
#define DEBUG_H

#define SERIAL_TRACE 1


#if (SERIAL_TRACE == 0)
    #undef SERIAL_TRACE
#endif


#endif // DEBUG_H