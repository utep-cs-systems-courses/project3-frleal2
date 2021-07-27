
//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

#define LED BIT6

short redrawScreen = 1;

int main(void) {
  P1DIR |= LED;
  P1OUT |= LED;
  
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  lcd_init();
  switch_init();
  
  //led_init();
  buzzer_init();
  enableWDTInterrupts();	/* enable periodic interrupt */
  or_sr(0x18);		/* CPU off, GIE on */

  clearScreen(COLOR_RED);
  
}

void wdt_c_handler(){
  static int secCount = 0;
  secCount ++;
  if (secCount >= 25) {/* 10/sec */
    secCount = 0;
    redrawScreen = 1;
  }
}
