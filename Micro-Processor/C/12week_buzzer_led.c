#include <avr/io.h>
#define F_CPU 14745600
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "_main.h"
#include "_buzzer.h"

int main(void)
{
    PORTB=0xFE;
	S_Start();
    while (1) 
    {
		for(int i=0; i<7; i++)
		{
			PORTB=PORTB>>1;
			_delay_ms(500);
		}
    }
}

