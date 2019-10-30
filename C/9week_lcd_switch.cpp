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
unsigned char set;
unsigned char Temp = 0;

//Timer0에 대한 초기화 루틴
void Init_Timer0(void){
	TCCR0 = 0x6f;  // 0110 1111  고속 PWM  1024분주
	DDRB = 0x10;   // 0001 0000  PORTB의 4번 출력으로 설정 OC0 핀
	OCR0 = 0xf0;
	TCNT0 = 0x00;
	TIMSK |=(1<<OCIE0);   // 출력비교 인터럽트 허가
 }

//INT0
ISR(TIMER0_COMP_vect){
		                                                                                                                                                
	SetBit(PORTB, PORTB4);
}

//port 초기화
void Port_init(void){ 
	PORTA = 0x00; DDRA = 0xff; 	
	PORTB =  0xff; DDRB = 0xff;
	PORTC =  0x00; DDRB = 0xf0;
	PORTD =  0x00; DDRD = 0x00;
	PORTE =  0x00; DDRE = 0xff;
	PORTF =  0x00; DDRF = 0x00;
}

void init_devices(void){
	cli(); //disalbe all interrupt
	Port_init();
	lcd_init();
	sei(); //re-enable interrupt
}

//screen 표시
void screen_display(void){
	lcd_clear();   //그래픽 LCD 지우기
	lcd_string(0,0,"====================");
	lcd_string(1,0,"      PWM test      ");
	lcd_string(2,0,"====================");
	
}

int main(void)
{	
	unsigned char ch;
	int i;
	Temp = 0;
	init_devices();
	Init_Timer0();
	Port_init();
	screen_display();
	SREG |= 0x80;
	PIND = 0xff;
	PORTB = 0x20;   //모터컨트롤러 제어 0010 0000 portb5=1, 6=0 --> forward
	
    while (1) 
    {
		PORTB = 0xff;
		ch = (PIND & 0xF0);  //스위치 입력 값 비교하기 위한 데이터 저장
		
		switch(ch) {
			PORTB = 0x00;
			_delay_ms(200);
			
			case 0xe0:  //PORTB 6번 스위치가 선택된 경우		
				OCR0=0x01;
				break;
			case 0xd0:  //PORTB 5번 스위치가 선택된 경우
				OCR0=0x8f;
				break;
			case 0xb0:  //PORTB 4번 스위치가 선택된 경우
				OCR0=0xfd;
				break;
			
			default:
			break;
		}
    }
}
