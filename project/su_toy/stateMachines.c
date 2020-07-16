#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"

static int sound=1000;
static enum{off=0,dim=1,on=2}brightness;
char counter =0;
char state = 0;
char led_toggle = 0;

void state_advance()
{
  switch(state)
    {

   case 1:
      led_toggle = 0;
      toggle_led();
      sound = 0;
      buzzer_set_period(sound);
      break;

    case 2:
      led_toggle = 3;
      toggle_led();
      sound = 1000;
      buzzer_set_period(0);
      break;

    case 3:
      if(sound<2000)
	{sound+=100;}
      led_toggle = 1;
      toggle_led();
      buzzer_set_period(sound);
      break;

    case 4:
      if(sound>500)
	{sound-=100;}
      led_toggle = 2;
      toggle_led();
      buzzer_set_period(sound);
      break;      
    }
}

void
toggle_led()
{
  leds_changed = 1;
  count();
  switch(led_toggle)
    {
    case 0:
      green_led = 0;
      red_led = 0;
      break;
    case 1:
      green_led = (counter<1);
      red_led = 0;
      break;
    case 2:
      green_led = 0;
      red_led = (counter>1);
      break;
    case 3:
      green_led = 1;
      red_led = 1;
      break;
    }
  led_update();
}

void bright()
{brightness = (brightness+1)%3;}

void count()
{counter = (counter+1)%3;}






