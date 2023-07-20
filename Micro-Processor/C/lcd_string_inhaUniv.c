#include <avr/io.h>
#include <util/delay.h>
#include "_main.h"
#include "_glcd.h"
#include "_adc.h"

unsigned int Data_ADC0=0;
// 사용한  Graphic LCD 모듈의 CS0 , CS1 신호가 Active Low로 동작하기 때문에
// 다음에 정의되어 있는 LCD제어 Address 순서가 반대로 되어 있다.
unsigned char Korean_buffer[32];					/* 32 byte Korean font buffer */

char Dis_Scr1[]={"===================="};
char Dis_Scr2[]={" INHA UNIVERSITY  "};
char Dis_Scr_IO_ON[]={"O"};
char Dis_Scr_IO_OFF[]={"X"};

unsigned char data2[] = {0xA0, 0x61,
	0xB7, 0xA1, 0xC7, 0x61, 0x9D,
	0xA1, 0xCF, 0x61, 0x9D, 0xA1,
0xAD, 0x41, 0xAC, 0xE1, 0x00};
unsigned char data3[] = " ATmega128";
unsigned char data4[] = "----------------";
void Port_init(void) 						// 포트 초기화 구문입니다.
{
	PORTA = 0x00; 	DDRA = 0xFF;			// PORTA 출력 LOW ,핀의 출력 설정
	PORTB = 0xFE; 	DDRB = 0b11111110;			// PORTB 출력 LOW ,핀의 출력 설정
	PORTC = 0x00; 	DDRC = 0xF0;			// PORTC 상위 4bit 입력, 하위 4bit 출력
	PORTD = 0x80;	DDRD = 0b10000000;		// 핀의 입출력 설정
	PORTE = 0x00; 	DDRE = 0xFF;			// PORTE 출력 LOW ,핀의 출력 설정
	PORTF = 0x00; 	DDRF = 0x00;			// PORTE 출력 LOW ,핀의 출력 설정
}
void init_devices(void)
{
	cli();
	Port_init();
	lcd_init();
	Adc_init();
	sei();
}
int main(void)
{
	init_devices();
	lcd_clear();
	lcd_string(0,0,Dis_Scr1);
	lcd_string(1,0,Dis_Scr2);
	lcd_string(2,0,Dis_Scr1);
	while(1)
	{
	}
}
