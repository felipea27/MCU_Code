#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "globalDefs.h"
#include "testingFunctions.h"


/*
int avg_meas_time;
float avg_t_in;
float avg_v_in;
float avg_rth;
*/
volatile bool comparatorFlag = 1;
bool *comparatorFlagPtr = &comparatorFlag;
//unsigned short vtp_measurements[sampleSize];
//float vth_measurements[sampleSize];

//bool adc_int_flag = 1;


void setup() {
  // put your setup code here, to run once:
  //Declare pins as inputs
  pinMode(START_BTN_PIN, INPUT);
  pinMode(ADC_EXT_INT, INPUT);
  pinMode(V_TH_PIN, INPUT);

  //Declare pins as outputs
  pinMode(RST_ADC, OUTPUT);
  pinMode(V_TOGGLE, OUTPUT);

  //Enable interrupts:
  //D7 bit of SREG (status register) enables all interrupts globally
  //Set D7 of SREG HIGH
  //Set relavent bit for interrupt pin in TIMSK register
  sei();
  attachInterrupt(ADC_EXT_INT, ISR_adcExtInt, FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:

  testInterrupt(comparatorFlagPtr);
  System.println("test done");
  while(1)
}

void ISR_adcExtInt()
{
  comparatorFlag = 0;
}

//REGISTER AND PORT CONFIGURATIONS:
//Configure PB6 for external clk input

//Configure PB7 for external clk input

//Configure PC0 to be an output pin, stays high and gets driven low upon activation. Enable pull up resistor

//Reset ADC -- drive PC0 low for 1 clk cycle

//Configure PC1 to be an output pin, stays low and gets driven high upon activation.

//Toggle ADC input -- drive PC1 high for a CLK cycle. 

//Configure PD2 to be an input (or interrupt) pin (experiment with timing on both)
//Need to set PD2 to 0: DDRD |= 0000000;

//Configure PB0 to be an input pin

//Connect timer T0 to a certain CLK

//Prescale CLK to 1MHz

//Read PD2 pin

//Read PB0 pin
/*
void setupTC0()
{
  //set TC0 register to correct timer prescale
  //In the TCCR0B register
  //CS0 = //desired prescalar, bottom 3 bits of TCCR0B register.

  001 -> no prescalar
  010 -> clk_io / 8
  011 -> clk_io / 64
  100 -> clk_io / 256
  101 0> clk_io / 1024


//Set the value of the OCR0A to the overflow value of TC0

  //Enable interrupt that corresponds to OCF0A flag. 
    // Set the OCIE0A [1] bit to 1 in the TIMSK0 register to high.
    // Also need to set the I bit in the status I register to 1
  TIMSK0 |= 0x02; //Set the second bit to high
  sei();
  

  //OCF0A flag goes up when TCNT0 goes to 0x00, so OCF0A becomes high when timer is at Tclk * (OCR0A + 1)
  //TOV0 goes up when TC0 overflows, gets cleared with the timer interrupt
}

void enableTC0()
{
  //Minimizing Power consumption register (PRR0), PRTIM0 bit = 0
  //TCNT0 = timer T0 value, this is an 8 bit register

  //OCR0A = timer max number <-- sets the maximum value of the timer. Default is MAX = 255
}
*/
