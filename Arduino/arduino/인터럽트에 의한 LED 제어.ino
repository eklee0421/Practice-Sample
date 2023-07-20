/*
외부 인터럽트 함수

2번 핀에 버튼을 연결하고 버튼의 상태가 바뀌는 것을 인터럽트 0번에 연결하여 13번 디지털 핀에 연결된 LED 상태 바꾸는 코드

*/

int pin = 13;

//ISR 함수 내에서 delay 함수는 무시되고 millis 함수의 반환값은 증가하지 않으며 시리얼 데이터는 유실된다
//따라서 동기화를 위해 ISR 내에서 값이 변경되는 변수는 volatile로 선언되어야 한다
volatile int state = LOW;

void setup() {
  pinMode(pin, OUTPUT); //13번 핀을 출력으로 설정
  // 0번 인터럽트 입력 신호의 상태가 변할 때 인터럽트 발생
  // 인터럽트 처리 함수로 blink 함수 연결
  attachInterrupt(0, blink, CHANGE);  //attachInterrupt(인터럽트 번호, ISR, 인터럽트가 발생하는 지점);
                                                                            // 여기서 CHANGE는 핀의 값이 변화 할 때 실행  
  }
  
  void loop() {
   digitalWrite(pin, state);  // 인터럽트에 의해 바뀐 상태를 LED로 출력
   }
   
   void blink() {
    state = !state; //인터럽트 발생시 반전
  }
