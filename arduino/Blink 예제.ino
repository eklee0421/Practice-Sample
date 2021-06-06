//디지털 13번 핀에 연결된 보트 내장 led를 1초 간격으로 점멸하는 코드

int ledPin = 13;  //LED는 13번 디지털 핀에 연결

void setup() {
  pinMode(ledPin, OUTPUT);  // 디지털 핀을 출력으로 설정
}

void loop() {
  digitalWrite(ledPin, HIGH); //LED on
  delay(1000);  //1초 대기
  digitalWrite(ledPin, LOW) //LED off
  delay(1000);  //1초 대기
}
