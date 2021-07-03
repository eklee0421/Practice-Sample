/*
시리얼 버퍼에 도착한 데이터를 바이트 단위로 읽어 이를 재전송해주는 코드

ex) ABC를 전송한다면
I received: 65
I received: 66
I received: 67
을 각각 출력

*/

int incomingByte = 0; //수신 데이터

void setup() {
  Serial.begin(9600); //  시리얼 포트 초기화
}

void loop() {
  if(Serial.availabe() > 0) { //수신 데이터가 있는 경우
    incomingByte = Serial.read();   //버퍼의 첫 번째 데이터 읽기
    
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);  // 문자의 ASCII 코드 값 전송
  }
}
