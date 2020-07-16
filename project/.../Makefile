# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf 

#additional rules for files
toy.elf: ${COMMON_OBJECTS} main.o stateMachines.o led.o wdInterruptHandler.o buzzer.o switches.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

erase:
	rm -f *~ *#

main.o: main.c

led.o: led.c led.h

buzzer.o: buzzer.c buzzer.h 

switches.o: switches.c switches.h p1_interrupt_handler.c

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h
