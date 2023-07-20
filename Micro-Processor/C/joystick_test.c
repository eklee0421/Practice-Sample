//조이스틱이 가리키는 값 읽어

#include <avr/io.h>
#include <util/delay.h>
#include "_main.h"
#include "_glcd.h"
unsigned int Data_ADC3=0; //조이스틱 상하 데이터 값 저장용
unsigned int Data_ADC4=0; //조이스틱 좌우 데이터 값 저장용
#define ADC_VREF_TYPE 0x00 //AD 컨버터 사용 기준 전압 REFS 설정
#define ADC_AVCC_TYPE 0x40 //AD 컨버터 사용 기준 전압 AVCC 설정
#define ADC_RES_TYPE 0x80 //AD 컨버터 사용 기준 전압 RES 설정
#define ADC_2_56_TYPE 0xC0 //AD 컨버터 사용 기준 전압 2.56 설정

// ADC 초기화
void ADC_init(void){
	ADCSRA=0x00;  //disable adc
	ADMUX=0x00;   //select adc input 0
	ACSR=0x80;	  //1000 0000
	ADCSRA=0xC3;  //1100 0011
}

//ADC 값 읽는 부분
unsigned int Read_Adc_Data(unsigned char adc_input) { 
	unsigned int adc=0;
	ADCSRA = 0xC3;
	ADMUX = adc_input | ADC_AVCC_TYPE; //adc 사용핀 설정
	ADCSRA |= 0x40; //0100 0000 start conversion
	while((ADCSRA & 0x10) != 0x10); //0001 0000 interrupt flag - wait for the AD conversion to complete (1이 되면 종료한다)
	adc += ADCL + (ADCH * 256); //상위 2비트를 받아서 256를 곱하고 더한다
	ADCSRA = 0x00;
	return adc;
}

//port 초기화
void Port_init(void){
	PORTA = 0x00; DDRA = 0xFF;
	PORTB = 0xFF; DDRB = 0xFF;
	PORTC = 0x00; DDRC = 0xF0;
	PORTD = 0x80; DDRD = 0x80; //입력 받는 것
	PORTE = 0x00; DDRE = 0xFF;
	PORTF = 0x00; DDRF = 0x00;
}

void init_devices(void){
	cli();
	Port_init();
	ADC_init();
	lcd_init();
	sei();
}

void screen_diplay(void){
	lcd_clear();
	lcd_string(0,0, "=====================");  //좌표값과 출력 할 값
	lcd_string(1,0, "   *JOYSTICK TEST*   ");
	lcd_string(2,0, "=====================");
}

void LCD_Decimal(unsigned char num, short AD_data){
	unsigned char Decimal[5];
	Decimal[4]=AD_data/10000; //10000의 자리 아스키 값으로 저장
	AD_data=AD_data%10000;
	Decimal[3]=AD_data/1000; //1000의 자리 아스키 값으로 저장
	AD_data=AD_data%1000;
	Decimal[2]=AD_data/100; //100의 자리 아스키 값으로 저장
	AD_data=AD_data%100;
	Decimal[1]=AD_data/10; //10의 자리 아스키 값으로 저장
	AD_data=AD_data%10;
	Decimal[0]=AD_data/1; //1의 자리 아스키 값으로 저장
	
	//data_adc3 변환
	if(num == 0){
		lcd_xy(5,11); GLCD_1DigitDecimal(Decimal[4],1); //10000의 자리 출력
		lcd_string(5,12,".");
		lcd_xy(5,13); GLCD_1DigitDecimal(Decimal[3],1); //1000의 자리 출력
		lcd_xy(5,14); GLCD_1DigitDecimal(Decimal[2],1); //100의 자리 출력
		lcd_xy(5,15); GLCD_1DigitDecimal(Decimal[1],1); //10의 자리 출력
		lcd_xy(5,16); GLCD_1DigitDecimal(Decimal[0],1); //1의 자리 출력
	}
	//data_adc4 변환
	if(num == 1){
		lcd_xy(7,11); GLCD_1DigitDecimal(Decimal[4],1); //10000의 자리 출력
		lcd_string(7,12,".");
		lcd_xy(7,13); GLCD_1DigitDecimal(Decimal[3],1); //1000의 자리 출력
		lcd_xy(7,14); GLCD_1DigitDecimal(Decimal[2],1); //100의 자리 출력
		lcd_xy(7,15); GLCD_1DigitDecimal(Decimal[1],1); //10의 자리 출력
		lcd_xy(7,16); GLCD_1DigitDecimal(Decimal[0],1); //1의 자리 출력
	}	
}

void joystick_move_menu(void){
	short Voltage1 = 0;
	short Voltage2 = 0;
	Data_ADC3 = Read_Adc_Data(3) / 14 ; //연결이 3번에 연결되어 있음 / 값 범위 때문에 
	Data_ADC4 = Read_Adc_Data(4) / 8 ; 
	_delay_ms(30);
	lcd_string(3,0, "      ") ;//상하: 메뉴 이동, 좌우 : 메뉴 선택
	
	//좌(<--) 조작
	if(Data_ADC3 > 50) {
		lcd_string(3,0,"LEFT     ");
		_delay_ms(300);
	}
	//우(-->) 조작
	else if(Data_ADC3 < 20) {
		lcd_string(3,0,"RIGHT     ");
		_delay_ms(300);
	}
	//하(--v) 조작
	else if(Data_ADC4 > 90) {
		lcd_string(3,0,"DOWN     ");
		_delay_ms(300);
	}
	//상(--^) 조작
	else if(Data_ADC4 < 20) {
		lcd_string(3,0,"UP     ");
		_delay_ms(300);
	}
	else{
		lcd_string(3,0, "      ");
	}
	
	//ADC 값 화면 출력
	lcd_string(4,1, "Data_ADC3 : ");
	lcd_xy(4,11);
	GLCD_4DigitDecimal(Data_ADC3); //실제로 읽은 값 십진수로 표현
	lcd_string(5,1, "ADC3 V : ");
	Voltage1=(short)((0.025*Data_ADC3)*10000); //AD를 전압으로 변환
	LCD_Decimal(0,Voltage1);
	
	lcd_string(6,1, "Data_ADC4 : ");
	lcd_xy(6,11);
	GLCD_4DigitDecimal(Data_ADC4); //실제로 읽은 값 십진수로 표현
	lcd_string(7,1, "ADC4 V : ");
	Voltage2=(short)((0.025*Data_ADC4)*10000); //AD를 전압으로 변환
	LCD_Decimal(1,Voltage2);
}

int main(void)
{
    init_devices();
	screen_diplay();
    while (1) 
    {
		joystick_move_menu();
    }
}

