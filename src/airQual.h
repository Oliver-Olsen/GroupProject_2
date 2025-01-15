#ifndef airQual.h
#define airQual.h

#include <MQ135.h>

void mq135_measurement(float *resistance_zero, float *corrected_zero, float *resistance, float *ppm_measured,  float *ppm_corrected);


#endif