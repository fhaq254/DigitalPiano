// Sound.c
// This module contains the SysTick ISR that plays sound
// Runs on LM4F120 or TM4C123
// Program written by: Fawadul Haq and Rafael Herrejon
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

// Code files contain the actual implementation for public functions
// this file also contains any private functions and private data
#include <stdint.h>
#include "dac.h"
#include "piano.h"
#include "tm4c123gh6pm.h"

uint8_t flute[64] = {6,7,9,9,10,11,12,13,13,14,15,15,15,15,15,14,13,
	                 13,12,11,10,9,8,7,7,6,6,5,5,5,5,4,4,4,4,4,4,3,3,
                   3,3,3,2,2,1,1,1,1,0,0,0,0,0,0,1,1,1,2,2,3,3,4,4,5}; // tone table

uint32_t Index = 0;        // index of the tone table
	
// **************Sound_Init*********************
// Initialize Systick periodic interrupts
// Called once, with sound initially off
// Input: interrupt period
//           Units to be determined by YOU
//           Maximum to be determined by YOU
//           Minimum to be determined by YOU
// Output: none
void Sound_Init(uint32_t period){
  NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = period; 
	NVIC_ST_CURRENT_R = 0;
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; // priority 2
	NVIC_ST_CTRL_R = 0x00000007; //0111
	
	DAC_Init();
}


// **************Sound_Play*********************
// Start sound output, and set Systick interrupt period 
// Input: interrupt period
//           Units to be determined by YOU
//           Maximum to be determined by YOU
//           Minimum to be determined by YOU
//         input of zero disable sound output
// Output: none
void Sound_Play(uint32_t period){
	
		NVIC_ST_RELOAD_R = period;
	  if(period == 0){
			DAC_Out(0);
		}
	}

void SysTick_Handler(uint32_t period){
	
	if(period){
	DAC_Out(flute[Index]);
	Index = (Index + 1)&0x1F;
	}
}
