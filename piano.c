// Piano.c
// This software configures the off-board piano keys
// Runs on LM4F120 or TM4C123
// Program written by: Fawadul Haq and Rafael Herrejon
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data
#include <stdint.h>
#include "tm4c123gh6pm.h"

// **************Piano_Init*********************
// Initialize piano key inputs, called once 
// Input: none 
// Output: none
void Piano_Init(void){volatile unsigned long delay; 
//clock
	SYSCTL_RCGC2_R |= 0x00000032;  //Activate Ports F,E,B
	delay = SYSCTL_RCGC2_R;        // Allow time for clock to start	
//E
	GPIO_PORTE_LOCK_R = 0x4C4F434B;//Unlock GPIO Port E
	GPIO_PORTE_CR_R = 0x07;        //Allow changes to PE 0,1,2
	GPIO_PORTE_AMSEL_R = 0x00;     //Disable analog on PE
	GPIO_PORTE_PCTL_R = 0x07;      //PCTL GPIO on PE 0,1,2
	GPIO_PORTE_DIR_R = 0x00;       //PE 0-7 inputs
	GPIO_PORTE_DEN_R = 0x07;       //Enable digital I/O on PE 0,1,2
	//F
	GPIO_PORTF_LOCK_R = 0x4C4F434B; //Unlock GPIO Port F
	GPIO_PORTF_CR_R = 0x04;        //Allow changes to PF 2
	GPIO_PORTF_AMSEL_R = 0x00;     //Disable analog on PF
	GPIO_PORTF_PCTL_R = 0x04;      //PCTL GPIO on PF 2
	GPIO_PORTF_DIR_R = 0x04;       //PF 2 outputs
	GPIO_PORTF_DEN_R = 0x04;       //Enable digital I/O on PF 2
}

// **************Piano_In*********************
// Input from piano key inputs 
// Input: none 
// Output: 0 to 7 depending on keys
// 0x01 is just Key0, 0x02 is just Key1, 0x04 is just Key2
uint32_t Piano_In(void){
	return (GPIO_PORTE_DATA_R&0x07); // Replace with your code
}
