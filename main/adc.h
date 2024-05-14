// header file for ADC functions
#include <avr/io.h>
#include <util/delay.h> 
#include <Arduino.h>


#ifndef adc.h
#define adc.h

void takeMeasurement(int measurement_array[], int samples, int cap_delay, int rstADC, int t_ref, int t_in, int v_toggle, int adc_ext_int);

#endif 