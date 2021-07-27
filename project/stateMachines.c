#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

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
    interruptTime = 0;
    turn_on_red();
    turn_off_green();
    buzzer_set_period(2551);
    break;
  case 2: // half dim
    interruptTime = 2;
    turn_on_red();
    buzzer_set_period(3005);
    break;
  case 3:// full dim
    interruptTime = 0;
    turn_on_red();
    turn_off_red();
    buzzer_set_period(3889);
    break;
  case 4:
    interruptTime = 0;
    turn_on_green();
    buzzer_set_period(2551);
    break;
  }
}



