#ifndef DEBUG_H
#define DEBUG_H

#define SERIAL_TRACE 0


#if (SERIAL_TRACE == 0)
    #undef SERIAL_TRACE
#endif


#endif // DEBUG_H