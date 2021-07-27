
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
    interruptTime = 0;
    clearScreen(COLOR_RED);
    drawPixel(0,0,COLOR_BLACK);
    drawCircle(80);
    //buzzer_set_period(2551);
    break;
  case 2: // half dim
    interruptTime = 2;
    clearScreen(COLOR_WHITE);
    //buzzer_set_period(3005);
    break;
  case 3:// full dim
    interruptTime = 0;
    clearScreen(COLOR_GREEN);
    //buzzer_set_period(3889);
    break;
  case 4:
    interruptTime = 0;
    turn_on_green();
    //buzzer_set_period(2551);
    break;
  }
}

void drawCircle(int r){
  int n = 2 * r+1;
  int x, y;
  for (int i = 0; i<n; i++){
    for(int j = 0; j< n; j++){
      x = j-r;
      y = j-r;
      if(x*x + y*y <= r*r+1){
	drawPixel(x,y,COLOR_BLACK);
      }
      else{
	drawPixel(x,y,COLOR_BLACK);
      }
      drawPixel(x,y,COLOR_BLACK);
    }
  }
}

