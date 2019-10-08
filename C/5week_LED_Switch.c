//스위치 입력에 따라 LED 좌우로 껐다 켜기
//4가지 버전

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

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

void PB_Rshift(){
	char LED;
	int i;
	LED=0xfe;
	for (i=0;i<8;i++){
		_delay_ms(500);
		PORTB =LED;
		LED=(LED<<1)|0x80;
	}
}

void PB_LEDonoff(){
	_delay_ms(500);
	PORTB =0x0f;
	_delay_ms(500);
	PORTB =0x00;
}

void PB_LEDswitch(){
	_delay_ms(500);
	PORTB =0x03;
	_delay_ms(500);
	PORTB =0x0c;
}


int main(void)
{
    char key;
	DDRB=0xff;
	DDRD=0x00; //상위 4비트만 입력 스위치로 이용
	
	while(1){
		key=(PIND & 0xf0);
		switch(key){
			case 0xe0: //1110 0000
			PB_Rshift(); _delay_ms(500); break; 
			
			case 0xd0:  //1101 0000
			PB_Lshift(); _delay_ms(500); break;
			
			case 0xb0: //1011 0000
			PB_LEDswitch(); _delay_ms(500); break; 
			
			case 0x70:  //0111 0000
			PB_LEDonoff(); _delay_ms(500); break;
			
			default: break;
		}
	}	
}

