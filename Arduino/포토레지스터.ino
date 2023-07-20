/*
시리얼 모니터를 통해 현재 광량에 따라 변하는 입력 전압을 시리얼 모니터로 
*/

void setup() {
  Serial.begin(9600); // 시리얼 통신 초기화
}

void loop() {
  int val = analogWrite(A0);  // 아날로그 입력 0번 핀
  
  Serial.println(Srting(val));
  
  delay(1000);
}
