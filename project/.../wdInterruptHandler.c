#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char count = 0;//how long a instance lasts

  
  switch(button)
    {
    case 1://add to song
	 
      break;
    case 2:// play song
	  
      break;
    case 3:// alter frequency up
	  
      break;
    case 4:// alter frequncy down

      break;
      
      // default:// switch leds
      //if(++count==125)
      //	{
      //	state_advance();
      //	count=0;
      //	}
      // break;
    }
  }
