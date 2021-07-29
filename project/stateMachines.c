
#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"


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
  case 1: //MOVES SHAPE LEFT
    stopCPU = 0;
    move_shape_Left(3);
    break;
  case 2://MOVES SHAPE RIGHT
    move_shape_Right(3);
    stopCPU = 0;
    break;
  case 3://CLEARS SCREEN GREEN
    clearScreen(COLOR_GREEN);
    stopCPU = 0;
    break;
  case 4://stops CPU
    stopCPU = 1;
    return;
    break;
  }
}

