/*
가변 저항으로부터 0에서 1023 사이의 값을 읽어 들이고, 값에 비례하도록 5개의 LED에 나타내는 프로그램
*/

int LED_pins[] = {8, 9, 10, 11, 12};  //LED 5개 연결
int currentVoltage = 0;   //현재 입력 전압
int previousVoltage = 0;  //이전 입력 전압

void setup() {
  for(int  i = 0; i < sizeof(LED_pins) / sizeof(int); i++)}
    pinMode(LED_pins[i], OUTPUT); //LED 핀을 출력으로 설정
  }
  Serial.begin(9600);
}

void loop() {
  int analogIn = analogRead(A0);  //가변 저항 읽기
  currentVoltage = map(analogIn, 0, 1023, 0, 5);  //ADC 값을 0 ~ 5V로 변환
  
  if(currentVoltage != previousVoltage) { //전압이 바뀐 경우
    previousVoltage = currentVoltage; // 이전 전압 갱신
    
    for(int i = 0; i < currentVoltage; i++) { //전압에 비례하여 LED 켜기
      digitalWrite(LED_pins[i], HIGH);
    }
    for(int t = currentVoltage; i < 5; i++){  //나머지 LED 끄기
      digitalWrite(LED_pins[i], LOW);
    }
  }
}  
