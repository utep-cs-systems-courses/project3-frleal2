//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
//#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

#define LED BIT6

short redrawScreen = 1;

void update_shape();

int main(void) {
  P1DIR |= LED;
  P1OUT |= LED;
  
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  lcd_init();
  switch_init();
  
  //led_init();
  buzzer_init();
  enableWDTInterrupts();	/* enable periodic interrupt */
  or_sr(0x8);		//ENABLE INTERRUPTS;
  
  // clearScreen(COLOR_RED);
  while(1){ 
    if(redrawScreen){
      redrawScreen = 0;
      my_shape(COLOR_BLACK);
      clearScreen(COLOR_GREEN);
    }
    P1OUT &= ~LED; //LED OFF
    or_sr(0x10); //CPU OFF
    P1OUT |= LED; //LED ON
  }
}

void wdt_c_handler(){
  static int secCount = 0;
  secCount ++;
  if ((secCount == 15) && (stopCPU == 0)) {/* 10/sec */
    secCount = 0;
    redrawScreen = 1;
  }
  if(secCount > 15){
   secCount = 0;
  }
}
