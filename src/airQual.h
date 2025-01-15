#ifndef AIRQUAL_H
#define AIRQUAL_H


void airQual_init();
void airQual_measurement(float *temperature, float *humidity);
float airQual_get_Value();


#endif // AIRQUAL_H