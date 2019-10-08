//인터럽트를 이용하여 버튼을 누르면 LED가 켜지는 프로그램
//0번 스위치를 한번 누를 때마다 LED는 2진수로 켜진다.
//ex) 누르기전 - 00000000  
// 1번 누른 뒤 - 00000001

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "_main.h"
#define F_CPU 14745600UL

char count;

SIGNAL(INT0_vect) {
	count++;
}

void Interrupt_init(void){
	SREG |=0x88;
	EICRA = 0x02;  //INT 0의 Falling Edge trigger
	EIMSK = 0x01;  //INT 0만 허가
	DDRD=0x00;  //INT0~3은 PD0~3
} 

int main(void)
{
		Interrupt_init();
		DDRB=0xff;
		count =0;
		while(1){
			PORTB = ~count; // '~' 는 부정의 의미
			if(count > 255) count=0;
		}
}

