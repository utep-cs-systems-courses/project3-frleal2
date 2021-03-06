#ifndef switches_included
#define switches_included

#define SW1 BIT0 //ALL SWITCHES WITH BITS RESPECTIVELY
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (SW1|SW2|SW3|SW4) //ALL SWITHCES ON THE GREEN BOARD

void switch_init();
void switch_interrupt_handler();

//extern int state;
//extern int stopCPU;
extern char interruptTime;
extern char switch_state_down_1, switch_state_changed;
extern char switch_state_down_2; /* effectively boolean */
extern char switch_state_down_3; /* effectively boolean */
extern char switch_state_down_4; /* effectively boolean */

#endif // included
