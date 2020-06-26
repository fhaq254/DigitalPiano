// dac.c
// This software configures DAC output
// Runs on LM4F120 or TM4C123
// Program written by: Fawadul Haq and Rafael Herrejonn 
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

#include <stdint.h>
#include "tm4c123gh6pm.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 4-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){
//B
	GPIO_PORTB_LOCK_R = 0x4C4F434B; //Unlock GPIO Port B
	GPIO_PORTB_CR_R = 0x3F;        //Allow changes to PB 0-5
	GPIO_PORTB_AMSEL_R = 0x00;     //Disable analog on PB
	GPIO_PORTB_PCTL_R = 0x3F;      //PCTL GPIO on PB 0-5
	GPIO_PORTB_DIR_R = 0x3F;       //PB 0-5 outputs
	GPIO_PORTB_DEN_R = 0x3F;       //Enable digital I/O on PB 0-5
	GPIO_PORTB_DR8R_R = 0x3F;
}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
void DAC_Out(uint32_t data){
GPIO_PORTB_DATA_R = data;
}
