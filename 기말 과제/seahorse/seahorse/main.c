#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "_main.h"
#include "_glcd.h"
#include "_adc.h"
#include "_buzzer.h"

unsigned int Data_ADC3=0; //조이스틱 상하 데이터 값 저장용
unsigned int Data_ADC4=0; //조이스틱 좌우 데이터 값 저장용
#define ADC_VREF_TYPE 0x00 //AD 컨버터 사용 기준 전압 REFS 설정
#define ADC_AVCC_TYPE 0x40 //AD 컨버터 사용 기준 전압 AVCC 설정
#define ADC_RES_TYPE 0x80 //AD 컨버터 사용 기준 전압 RES 설정
#define ADC_2_56_TYPE 0xC0 //AD 컨버터 사용 기준 전압 2.56 설정
#define F_CPU 16000000UL

int hitbox_x = 0, hitbox_y = 0;

volatile uint8_t timer_cnt = 0;
volatile bool flag = 0;
volatile bool phase_flag = 0;
volatile uint32_t chance_time = 0;
volatile bool chance_flag = 0;
volatile uint32_t lonely_time = 0;
volatile bool lonely_flag = 0;

int weight = 0;
int num_air = 0;
int hit = 0;

int run = 0;
bool direction[4] ={};

int x_feed[20]={};
int y_feed[20]={};
int num_feed = 0;
volatile bool feed_flag[20] = {};
int eat = 0;

bool death[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t death_reason = 0;			// 1 ~ 8까지 죽음의 이유
uint8_t all_death = 0;

bool air_run = 0;

int LED = 0x00;

//#include "delay.h"                // 초기화 헤더

unsigned int Data_ADC0=0;
// 사용한  Graphic LCD 모듈의 CS0 , CS1 신호가 Active Low로 동작하기 때문에
// 다음에 정의되어 있는 LCD제어 Address 순서가 반대로 되어 있다.
unsigned char Korean_buffer[32];					/* 32 byte Korean font buffer */

unsigned char seaHorse[30][16] = {
								{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
								{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
								{0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0},
								{0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0},
								{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
								{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
								{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0},
								{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0},
								{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0},
								{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0},
								{0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0},
								{0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0},
								{0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0},
								{0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0},
								{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
								{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
								{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
								{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
								{0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},
								{0,0,0,0,0,1,1,1,1,0,0,1,1,1,0,0},
								{0,0,0,0,0,1,1,1,1,0,0,1,1,1,0,0},
								{0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0},
								{0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0},
								{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0},
								{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0},
																
};
unsigned char fishingRod[30][6] = {
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{0,0,0,0,1,1},
									{1,1,0,0,1,1},
									{1,1,1,0,1,1},
									{1,1,0,0,1,1},
									{1,1,0,0,1,1},
									{1,1,1,1,1,1},
									{1,1,1,1,1,1}
};

unsigned char scratch[6][6]={
								{1,0,0,1,0,1},
								{0,1,0,0,1,0},
								{1,1,1,1,0,1},
								{0,1,0,1,0,0},
								{0,1,0,1,1,0},
								{1,0,1,0,0,0},	
};



/**************************************************
 ************* Initialization Functions ***********
 **************************************************/

void timer_init(void) {
	TCCR0 |= (1<<WGM01);					// CTC Mode
	TCCR0 |= (1<<CS02);						// Prescaler 64 (16MHz/64)
	TCNT0 = 0x00;							// 초기값
	OCR0 = 249;								// TOP값 (1ms마다 타이머 인터럽트 진입)
	TIMSK |= (1<<OCIE0);					// Timer/Counter0 CTC Mode Interrupt Enable
}
void Port_init(void) 						// 포트 초기화 구문입니다.
{
	PORTA = 0x00; 	DDRA = 0xFF;			// PORTA 출력 LOW ,핀의 출력 설정
	PORTB = 0xFE; 	DDRB = 0b11111110;		// PORTB 출력 LOW ,핀의 출력 설정
	PORTC = 0x00; 	DDRC = 0xF0;			// PORTC 상위 4bit 입력, 하위 4bit 출력
	PORTD = 0x81;	DDRD = 0b10000000;		// 핀의 입출력 설정
	PORTE = 0x00; 	DDRE = 0xFF;			// PORTE 출력 LOW ,핀의 출력 설정
	PORTF = 0x00; 	DDRF = 0x00;			// PORTE 출력 LOW ,핀의 출력 설정
}
void ADC_init(void){
	ADCSRA = 0x00;  //disable adc
	ADMUX = 0x00;   //select adc input 0
	ACSR = 0x80;	  //1000 0000
	ADCSRA = 0xC3;  //1100 0011
}
void init_devices(void)
{
	cli();
	timer_init();
	Port_init();
	lcd_init();
	Adc_init();
	sei();
}

/**************************************************
 ************* Peripheral Functions ***************
 **************************************************/

void printSeaHorse(void){
	for(int y = 0; y < 16; y++){
		for(int x = 0; x < 30; x++){
			if(seaHorse[x][y] == 1){
				GLCD_Dot(x + hitbox_x, y + hitbox_y);
			} else continue;
		}
	}	
}


void print_scratch(void){
	hit++;
	int x_n = rand() % 55;
	int y_n = rand() % 115;
	for(int y = 0; y < 6; y++){
		for(int x = 0; x < 6; x++){
			if(scratch[x][y] == 1){
				GLCD_Dot(x + x_n, y + y_n);
			} else continue;
		}
	}	
}

void printAir(){
	num_air++;
	int y = rand() % 100 + 10;
	int x = 60 ;
	for(x = 60; x > 0; x--){
		air_run = 1;
		GLCD_Circle_black(x,y,3);
		_delay_ms(300);
		move_seahorse();
		_delay_ms(100);
		lcd_clear();
		ScreenBuffer_clear();
	}
	air_run = 0;
}

void printFishingRod(void) {
	for(int y = 0; y < 6; y++) {
		for(int x = 0; x < 30; x++) {
			if(fishingRod[x][y] == 1) {
				GLCD_Dot(x, y + 61);
			} else continue;
		}
	}
	//lcd_string(10, 0 , "Let's escape on the fishing rod!");
}

void setFeed(void){		//먹이를 출력하는 함수
	if(num_feed < 20){
		int x1 = rand() % 59 +1;
		int y1 = rand() % 121 + 1;
		x_feed[num_feed] = x1;
		y_feed[num_feed] = y1;
		feed_flag[num_feed]++;
		num_feed++;	
	}
}

void printFeed(int x1, int y1){
	GLCD_Rectangle_black(x1, y1, x1+4, y1+4);
}

void move_seahorse(void) {
	short Voltage1 = 0, Voltage2 = 0;
	Data_ADC3 = Read_Adc_Data(3) / 14;
	Data_ADC4 = Read_Adc_Data(4) / 8;
	
	//좌(<--) 조작
	if(Data_ADC3 > 50) {
		if(hitbox_y > 0) {
			hitbox_y--;
			if(!direction[0]){
				direction[0] = 1;
				direction[1] = 0;
				direction[2] = 0;
				direction[3] = 0;
				run++;
			}
		}
		if (hitbox_y == 0){
			if(!death[1]) {
				death_reason = 1;	
			}
		}
	}
	//우(-->) 조작
	else if(Data_ADC3 < 20) {
		if(hitbox_y < 112) {
			hitbox_y++;
			if(!direction[1]){
				direction[0] = 0;
				direction[1] = 1;
				direction[2] = 0;
				direction[3] = 0;
				run++;
			}
		}
		if (hitbox_y == 112){
			if(!death[1]) {
				death_reason = 1;
			}
		}
	}
	//하(--v) 조작
	else if(Data_ADC4 > 90) {
		if(hitbox_x < 34) {
			hitbox_x++;
			if(!direction[2]){
				direction[0] = 0;
				direction[1] = 0;
				direction[2] = 1;
				direction[3] = 0;
				run++;
			}
		}
		if (hitbox_x == 34){
			if(!death[1]) {
				death_reason = 1;
			}
		}
	}
	//상(--^) 조작
	else if(Data_ADC4 < 20) {
		if(hitbox_x > 0) {
			hitbox_x--;
			if(!direction[3]){
				direction[0] = 0;
				direction[1] = 0;
				direction[2] = 0;
				direction[3] = 1;
				run++;
			}
		}
		if (hitbox_x == 0){
			if(!death[1]) {
				death_reason = 1;
			}
		}
	}

	lcd_clear();
	ScreenBuffer_clear();
	printSeaHorse();
	
	if(chance_flag) {
		printFishingRod();
	}
	
	for(int i =0; i< 20 ; i++){
		if(feed_flag[i]){
			printFeed(x_feed[i], y_feed[i]);
		}
	}
}

void fishing_rod_event(void) {
	printFishingRod();
	if((hitbox_y >= 61 && hitbox_y <= 67) && (hitbox_x >= 0 && hitbox_x <= 30)) {
		while(1) {
			if((PIND & 0x01) == 0) {
				death_reason = 9;
				break;
			}
		}
		
	}
}

void eat_feed(void){
			num_feed--;
			eat++;
			x_feed[num_feed] = 0;
			y_feed[num_feed] = 0;
			feed_flag[num_feed] = 0;
			lcd_clear();
			ScreenBuffer_clear();
			for(int j =0; j<20;j++){
				printFeed(x_feed[j],y_feed[j]);
			}
			int i = rand() % 10;
			if(i == 0){
				if(!death[7]){
					death_reason = 7;
				}
			}
}


/**************************************************
 *************** Phase Functions ******************
 **************************************************/

void Phase_1(void) {					// Start Main Menu
	hitbox_x = 0;
	hitbox_y = 0;
	Data_ADC0 = Read_Adc_Data(0) / 10;  //0번 아날로그 포트 읽기
	_delay_ms(5000);
	lcd_clear();
	ScreenBuffer_clear();
	lcd_string(0, 0, "     ==============");
	lcd_string(1, 0, "     Seahorse Game");
	lcd_string(2, 0, "     ==============");
	lcd_string(4, 0, "Press Button to Start");
	printSeaHorse();

	while(1) {
		if((PIND & 0x01) == 0) {			// 0번 스위치가 눌리면 게임을 시작
			break;
		}
	}
}


void Phase_2(void) {					// Game Play
	
	eat =0;
	num_feed = 0;
	run = 0;
	num_air =0;
	hit = 0;
	
	phase_flag ^= 1;
	hitbox_x = 30;
	hitbox_y = 30;
	while(1) {
		
		if((PIND & 0x02) == 0) {			// 1번 스위치가 눌리면 음식을 준다
			setFeed();
			_delay_ms(5000);
		}	
		
		if((PIND & 0x04) == 0){
			eat_feed();
			move_seahorse();
			_delay_ms(5000);
		}
		
		
		if((PIND & 0x08) == 0){
			printAir();
		}
		
		if((PIND & 0x10) == 0){
			print_scratch();
			_delay_ms(5000);
		}
		
		if(flag) {
			move_seahorse();
			flag ^= 1;
		}
		if(chance_flag) {
			fishing_rod_event();
		}
		
		if(lonely_flag) {
			if(!death[2]){
				death_reason = 2;
				lonely_flag =0;
			}
		}
		
		if(eat == 15){
			if(!death[3]){
				death_reason = 3;
			}
		}
		
		if(num_feed == 9){
			if(!death[4]) {
				death_reason = 4 ;
			}
		}
		
		if(run == 20){
			if(!death[5]){
				death_reason = 5;
			}
		}
		
		if(num_air == 3){
			if(!death[6]){
				death_reason = 6;
			}
		}
		
		if(hit == 10){
			if(!death[8]){
				death_reason = 8;
			}
		}
		
		if(death_reason > 0) {
			break;
		}
	}
	
	phase_flag ^= 1;
}

void LED_ON(void){	//물고기가 죽으면 레벨이 올라가면서 LED가 켜진다
	S_Start();
	DDRB = 0xff;
	PORTB = 0x00;
	if(all_death == 0){
		LED = 0xfe;
	}
	else {
		LED = (LED << 1);
	}
	PORTB = LED;
}

void Phase_3(void) {					// Death Screen
	char death_string[20] = {};
	if(death_reason == 1) {
		LED_ON();
		all_death++;
		death[1]++;
		strcpy(death_string, "It crashed!!");
	} else if(death_reason == 2) {
		LED_ON();
		all_death++;
		death[2]++;
		strcpy(death_string, "So lonely!");
	} else if(death_reason == 3) {
		LED_ON();
		all_death++;
		death[3]++;
		strcpy(death_string, "It is full!");
	} else if(death_reason == 4) {
		LED_ON();
		all_death++;
		death[4]++;
		strcpy(death_string, "Water is so dirty!");
	} else if(death_reason == 5) {
		LED_ON();
		all_death++;
		death[5]++;
		strcpy(death_string, "It is so dizzy!!");
	} else if(death_reason == 6) {
		LED_ON();
		all_death++;
		death[6]++;
		strcpy(death_string, "Be swept away..");
	} else if(death_reason == 7) {
		LED_ON();
		all_death++;
		death[7]++;
		strcpy(death_string, "It eats trash..");
	} else if(death_reason == 8) {
		LED_ON();
		all_death++;
		death[8]++;
		strcpy(death_string, "Fishbowl is broken.");
	} else if(death_reason == 9) {
		strcpy(death_string, "Fishing Rod Kill");
	}
	

	_delay_ms(5000);
	lcd_clear();
	ScreenBuffer_clear();

	lcd_string(0, 0, "====================");
	lcd_string(1, 0, " Seahorse Died..i-i ");
	lcd_string(2, 0, death_string);
	lcd_string(3, 0, "  But don't worry!  ");
	lcd_string(4, 0, "Seahorse has a child");
	lcd_string(5, 0, " Restart with child ");
	lcd_string(6, 0, "  <<Press Button>>  ");
	lcd_string(7, 0, "====================");
	while(1) {
		if((PIND & 0x01) == 0) {

			if(death_reason == 9) {
				_delay_ms(5000);
				lcd_clear();
				ScreenBuffer_clear();
				uint8_t hint = 0;
			REPEAT:
				hint = (rand() % 8) + 1;
				if(death[hint]) {
					goto REPEAT;
				}
				if(hint == 1) {
					strcpy(death_string, "Fishbowl has glass walls");
				} else if(hint == 2) {
					strcpy(death_string, "It wants friend..");
				} else if(hint == 3) {
					strcpy(death_string, "It hate full");
				} else if(hint == 4) {
					strcpy(death_string, "It loves fresh!");
				} else if(hint == 5) {
					strcpy(death_string, "It loves to stay");
				} else if(hint == 6) {
					strcpy(death_string, "It is bad swimmer");
				} else if(hint == 7) {
					strcpy(death_string, "Don't give trash");
				} else if(hint == 8) {
					strcpy(death_string, "Don't hit the wall");
				}
				lcd_clear();
				ScreenBuffer_clear();
				lcd_string(0, 0, "HINT:");
				lcd_string(1, 0, death_string);
				lcd_string(3, 0, "<<Press Button>>");
				hint =0;
				chance_time = 0;
				chance_flag = 0;				
			}

			death_reason = 0;
			while(1) {
			if((PIND & 0x01) == 0) {
				break;
				_delay_ms(5000);
			}
			}
			break;
		}
	}
	for(int i = 0; i< 20; i++){
			x_feed[i] =0;
			y_feed[i] =0;
			num_feed =0;
			feed_flag[i] =0;
	}
	
		if(all_death == 8) {
			while(1) {
				Data_ADC0 = Read_Adc_Data(0) / 10;  //0번 아날로그 포트 읽기
				_delay_ms(200);
				lcd_clear();
				ScreenBuffer_clear();
				lcd_string(0, 0, "    ==============");
				lcd_string(1, 0, "    YOU WIN!!!!!!!");
				lcd_string(2, 0, "    ==============");
				lcd_string(3, 0, "Your Seahorse Won");
				lcd_string(4, 0, "GAME COMPLETE!");
				lcd_string(5, 0, "Thank you for playing");
				printSeaHorse();
			}
		}
}

int main(void)
{
	init_devices();
	lcd_clear();

	while(1) {
		Phase_1();
		Phase_2();
		Phase_3();
	}
}

ISR(TIMER0_COMP_vect) {
	if(phase_flag) {
		timer_cnt++;
		if(timer_cnt == 50) {				// 50ms 마다 해마 움직일 수 있는 flag
			flag ^= 1;
			timer_cnt = 0;
			chance_time = (rand() % 500) + 1;
			if(death[2] == 0){
				lonely_time = (rand() % 1000) + 1;
			}
			if(air_run == 0 && chance_time == 5) {
				chance_flag = 1;
				for(int i = 0; i< 20; i++){
					x_feed[i] =0;
					y_feed[i] =0;
					num_feed =0;
					feed_flag[i] =0;
	}
				S_S6();
			}
			if(lonely_time == 5){
				lonely_flag = 1;
				lonely_time = 0;
			}
		}
	}
}

/**************************************************
 *************** death Functions ******************
 **************************************************/
//1번 죽음의 이유는 어항벽에 부딪히면 죽음
//2번 죽음의 이유는 외로워서(랜덤으로 사망)
//3번 죽음의 이유는 먹이가 너무 많아서 어항 속이 너무 더러움
//4번 죽음의 이유는 먹이를 너무 많이 먹어서 배가 불러서 죽음
//5번 죽음의 이유는 너무 많이 돌아다니면 어지러워서 죽음
//6번 죽음의 이유는 여과기 너무 많이 돌리면 휩쓸려서 죽음
//7번 죽음의 이유는 쓰레기 잘못 먹어서 죽음
//8번 죽음의 이유는 어항 너무 많이 두드리면 스트레스 받아서 죽음