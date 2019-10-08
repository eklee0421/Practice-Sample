//인터럽트를 이용하여
//Rshift / Lshift를 수행하다가 스위치가 눌리면 토글

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "_main.h"
#define F_CPU 14745600UL

char Direction;

SIGNAL(INT0_vect) {
	Direction = ~Direction;

}

void Interrupt_init(void){
	SREG |=0x88;
	EICRA = 0x02;  //INT 0의 Falling Edge trigger
	EIMSK = 0x01;  //INT 0만 허가
	DDRD=0x00;  //INT0~3은 PD0~3
}

void Lshift(void){
	int i;
	char tmp;
	tmp = 0xff;
	for(i=0; i<8;i++){
		_delay_ms(500);
		PORTB = tmp;
		tmp = (tmp<<1) | 0x01;
	}
}

void Rshift(void){
	int i;
	char tmp;
	tmp = 0x7f;
	for(i=0; i<8;i++){
		_delay_ms(500);
		tmp = (tmp>>1) | 0x80;
		PORTB = tmp;
	}
}

int main(void)
{
	DDRB = 0xFF;
	Interrupt_init();
	PORTB = 0x0f;
	Direction = 0;
	while(1){
		if(Direction) Rshift();
		else Lshift();
	}
}

