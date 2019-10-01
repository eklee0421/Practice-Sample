//LED 0번부터 8번까지 순서대로 켜고 끄기

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LED_main.h"

void PB_Lshift(){
	char LED;
	int i;
	LED=0xfe;
	for (i=0;i<8;i++){
		_delay_ms(500);
		PORTB =LED;
		LED=(LED<<1)|0x01;
	}
}

int main(void)
{
    DDRB =0xff;
    while (1) 
    {
		PB_Lshift();
		_delay_ms(500);
		   }
}

