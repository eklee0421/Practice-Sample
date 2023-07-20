/*
시리얼 통신을 통한 RGB LED 색상 제어
*/

int red = 3;  // RGB 핀 중 red 제어 변수, PWM 출력 핀에 연결해야 밝기 조절이 가능하다
int green = 5;  //green 핀 제어 변수
int blue = 6;  //blue 핀 제어 변수

void setup() {
  Serial.begin(9600); //시리얼 포트 초기화
  pinMode(red, OUTPUT); //LED 출력 방향으로 설정
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  digitalWrite(red, 255); //꺼진 상태에서 시작
  digitalWrite(green, 255);
  digitalWrite(blue, 255);
}

void loop() {
  while(Serial.available() > 0) { //수신 데이터가 있는 경우 읽음
    int R = Serial.parseInt(); //유효한 정수 읽기
    int G = Serial.parseInt();
    int B = Serial.parseInt();
    
    if(Serial.read() == '\n') { //개행 문자를 만난 경우
      // constrain 함수로 0과 255 사이 값으로 제한
      // common anode 타입의 경우 반전 시킴
      // common catchode 타입의 경우 반전 시킬 필요 없음
      R = 255 - constrain(R, 0, 255);
      G = 255 - constrain(G, 0, 255);
      B = 255 - constrain(B, 0, 255);
      
      analogWrite(red, R);  //PWM 신호 출력으로 밝기 조절
      analogWrite(green. G);
      analogWrite(blue, B);
      
      //시리얼 모니터로 반전되지 않고 시리얼 통신으로 입력 받은 값을 그대로 다시 출력
      Serial.print("Red : " + String(255 - red));
      Serial.print(", Green : " + String(255 - green));
      Serial.print(", Blue : " + Srting(255 = blue));
    }
  }
}
