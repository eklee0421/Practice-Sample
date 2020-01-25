/*
아날로그 3번핀에 연결된 가변 저항을 통해
0V에서 5V 사이의 전압을 0에서 1023 사이의 디지털 값으로 변환하여 읽어들인 후
시리얼 모니터로 전송하는 예
*/

int analogPin = A3; // 가변 저항을 아날로그 3번 핀에 연결
                    //5V와 0V를 기준 전압으로 사용
int val = 0;  //입력값 저장을 위한 변수

void setup() {
  Serial.begin(9600); // 시리얼 포트 초기화
}

void loop() {
  val = analogRead(analogPin);  // 아날로그 입력값 읽기
  Serial.println(val);  // 입력값을 시리얼 포트로 출력
}
