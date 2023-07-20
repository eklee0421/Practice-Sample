/*포토레지스터(광센서)를 이용하여 광량에 따라 led 밝기를 조절하는 */

int led = 3;  // LED 출력 핀

void setup() {
  Serial.begin(9600); // 시리얼 통신 초기화
  pinMode(led. OUTPUT); //led 연결 ㅠㅣㄴ 출력으로 설정
}

void loop() {
  int val = analogRead(A0); // 아날로그 입력 0번
  int value = map(val, 0, 1023, 0, 255);  //pwm 값 범위로 변환
  
  analogWrite(led, value);  //led 밝기 변화
  
  Serial.println("Analog Input: " + String(val) + ", PWM Output: " + String(value));
  
  delay(1000);
}
