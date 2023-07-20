#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F_CPU 14745600UL
#include "_main.h"
#include "_glcd.h"

unsigned char led = 0xfe;
unsigned char cnt = 0;
int count;

/* 

인터럽트 발생 주기 1/(14.7456MHz)*1024분주*256 = 17.8ms
17.8ms * 56 = 1sec

*/


//Timer0에 대한 초기화 루틴
void Init_Timer0(void){
	TCCR0 = 0x07; //0000 01111 , normal mode , prescale 1024
	TCNT0 = 0x00;
	SREG = 0x80;
	TIMSK = 0x01; //TOIE0 = 1
}

//INT0
ISR(TIMER0_OVF_vect){
	cnt++;
	if(cnt==56){ // 1sec?
		count++;
		lcd_string(6,1,"TIMER(SEC): ");
		lcd_xy(6,14);
		GLCD_4DigitDecimal(count);
		led<<=1;
		led |= 0x01;
		if(led==0xff) led = 0xfe;
			PORTB = led;
			cnt=0;
			if(count>=255) count = 0;		
		
	}
}

//port 초기화
void Port_init(void){ 
	PORTA = 0x00; DDRA = 0xff; 	
	PORTB =  0xff; DDRB = 0xff;
	PORTC =  0x00; DDRB = 0xf0;
	PORTD =  0x80; DDRD = 0x80;
	PORTE =  0x00; DDRE = 0xff;
	PORTF =  0x00; DDRF = 0xf0;
}

void init_devices(void){
	cli(); //disalbe all interrupt
	Port_init();
	lcd_init();
	sei(); //re-enable interrupt
}

//screen 표시
void screen_display(void){
	lcd_clear();
	lcd_string(0,0,"================");
	lcd_string(1,0,"   TIMER TEST   ");
	lcd_string(2,0,"================");
}

int main(void)
{	
	init_devices();
	screen_display();
	Init_Timer0();

    while (1) 
    {
    }
}

