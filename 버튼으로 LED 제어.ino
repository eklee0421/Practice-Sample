// 디지털 2번 핀에 연결된 푸시 버튼을 누르면 13번 디지털 핀에 연결된 보드상의 led가 켜지도록 하는 

int ledPin = 13;  //13번 핀에 연결된 LED
int inPin = 2;  // 7번 핀에 연결된 푸시 버튼
int val = 0;  // 입력값 저장을 위한 변수

void setup() {
  pinMode(ledPin, OUTPUT);  // 13번 핀을 출력으로 설정
  pinMode(inPin, INPUT);  // 7번 핀을 입력으로 설정
}

void loop() {
  val = digitalRead(inPin); //버튼 상태 읽기
  digitalWrite(ledPin, val);  //버튼 상태를 led에 표시
}
