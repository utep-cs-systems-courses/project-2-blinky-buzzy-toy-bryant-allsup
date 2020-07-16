#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char button1_down, button2_down, button3_down, button4_down, switch_state_changed;
/* effectively boolean */

char button = 0;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  
  button1_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  button2_down = (p2val & SW2) ? 0 : 1;
  button3_down = (p2val & SW3) ? 0 : 1;
  button4_down = (p2val & SW4) ? 0 : 1;

  switch_state_changed=1;

  
  if(button1_down){
    green_on = 1;
    led_changed =1;
    led_update();
    
    // button = 1;
  }
  if(button2_down){button = 2;}
  if(button3_down){button = 3;}
  if(button4_down){button = 4;}
  
}
