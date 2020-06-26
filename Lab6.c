// Lab6.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// MOOC lab 13 or EE319K lab6 starter
// Program written by: Fawadul Haq and Rafael Herrejon
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********


#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
uint32_t input;               // piano input: PE0 = A, 1 = C, 2 = E
uint32_t period;              // the reload value for a note: A = 2840, C = 4770, E = 3787


/*int main(void){
  unsigned long Data; // 0 to 15 DAC output
  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);  // like Program 4.6 in the book, 80 MHz
  DAC_Init();
  for(;;) {
    DAC_Out(Data);
    Data = 0x0F&(Data+1); // 0,1,2...,14,15,0,1,2,...
   }
}*/

int main(void){


  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);    // bus clock at 80 MHz
  Piano_Init();
  Sound_Init(0);
	uint32_t n=250000;
  // other initialization
  EnableInterrupts();
  
  while(1){ 
    input = Piano_In();
    switch(input){
      case 0: period = 0;    break; // disable interrupts and stop sound
      case 1: period = 2840; break;
      case 2: period = 4770; break; 
      case 3: period = 0;    break;
      case 4: period = 3787; break;
      case 5: period = 0;    break;
		  case 6: period = 0;    break;
		  case 7: period = 0;    break;
		// convert inputs into reload values
    // then send them to sound play
    }
		
		
    Sound_Play(period);
  }
}


