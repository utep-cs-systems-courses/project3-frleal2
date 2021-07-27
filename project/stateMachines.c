
#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

char interruptTime;

char turn_on_green(){
  green_on = 1;
  led_changed = 1;
  led_update();
}

char turn_off_green(){
  green_on = 0;
  led_changed = 1;
  led_update();
}

char turn_on_red(){
  red_on = 1;
  led_changed = 1;
  led_update();
}

char turn_off_red(){
  red_on = 0;
  led_changed = 1;
  led_update();
}

void state_advance()		/* alternate between toggling red & green */
{

  switch(state){
  case 1: //fully bright
    clearScreen(COLOR_RED);
    move_shape_Left(3);
    buzzer_set_period(2551);
    break;
  case 2: // half dim
    clearScreen(COLOR_RED);
    move_shape_Right(3);
    buzzer_set_period(2551);
    break;
  case 3:// full dim
    clearScreen(COLOR_GREEN);
    //drawString("GAME OVER");
    break;
  case 4:
    buzzer_set_period(0);
    break;
  }
}

