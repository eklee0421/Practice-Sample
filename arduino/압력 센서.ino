/*
압력 센서를 누르는 힘에 따라 아날로그 A0 핀에 입력되는 전압이 변화하고, 이를 디지털 3번 핀에 연결된 LED 밝기 변화로 나타내는 코드
*/

int led = 3;  // led 출력 핀

void setup() {
  Serial.begin(9600); //시리얼 초기화
}

void loop() {
  int val = analogRead(A0); //아날로그 입력 0번
  int value = map(val, 0, 1023, 0, 255);  //PWM 범위로 변환
  
  analogWrite(led, value);  //PWM 신호 출력
  
  Serial.println("Analog Input: "+ String(val) + "PWM Output: " + String(value));
  
  delay(1000)
}
