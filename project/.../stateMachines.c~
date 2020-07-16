#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char state = 0;
static char led_state = 0;
static int sound = 1000;
static int song [100];
static int note = 0;


void state_advance()		/* alternate between toggling red & green */
{
  switch(state)
    {
      case 1://play song
	led_state =0;
	break;

      case 2://add to song
	song[note] = sound;
	buzzer_set_period(sound);
	led_state =3;
	break;

      case 3:
	sound+=100;
	buzzer_set_period(sound);
	led_state = 1;
	break;

      case 4:
	sound-=100;
	buzzer_set_period(sound);
	led_state = 2;
        break;

      default:
	if(led_state == 4)
	  {led_state = 1;}
	toggle_led();
	led_state++; 
	break;
    }
}

void toggle_led()//manages leds
{
  switch(led_state)
    {
    case 0://green off red off
      red_on=0;
      green_on=0;
      break;
    case 1://green on red off
      red_on=0;
      green_on=1;
      break;
    case 2://green off red on
      red_on=1;
      green_on=0;
      break;
    case 3://green on red on
      red_on=1;
      green_on=1;
      break;
    }
  led_changed =1;
  led_update();
}



