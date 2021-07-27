
//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

short redrawScreen = 1;

int main(void) {

  
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  switch_init();
  lcd_init();
  buzzer_init();
  enableWDTInterrupts();	/* enable periodic interrupt */

  or_sr(0x18);		/* CPU off, GIE on */
}

void wdt_c_handler(){
  clearScreen(COLOR_RED);
}
