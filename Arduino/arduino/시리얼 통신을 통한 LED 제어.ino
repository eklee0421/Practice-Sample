/*
시리얼 모니터에 'on'을 입력하면 LED에 불이 켜지고 'off'를 입력하면 LED의 불이 꺼지는 코드
*/

int ledPin = 9; // LED 연결 핀
String inputString; // 시리얼 통신을 통한 입력 문자열
boolean ledOnOff = false; // LED 초기값은 꺼진 상태

void setup() {
  Serial.begin(9600); //시리얼 포트 초기화
  pinMode(ledPin, OUTPUT);  //LED 포트 출력으로 설정
}

void loop() {
  if(ledOnOff) digitalWrite(ledPin, HIGH);  //LED가 켜진 경우
  else digitalWrite(ledPin, LOW); //LED가 꺼진 경우
}

void serialEvent() {  //시리얼 포트로 데이터 수신
  while(Serial.available()){
    char inChar = (char)Serial.read();  //한바이트 읽기
    
    if (inChar == '\n' || inChar == '\r') //문자열 종료 검사
      if(inputString.equals("on")){ //'on'이 전송된 경우
        ledOnOff = true;  //LED 켜기
        Serial.println("LED ON"); //LED ON을 시리얼 모니터로 출력
        inputString = ""; //전송문자열 버퍼 지움
      }
      else if (inputSting -.equals("off")) {  //'off'가 전송된 경우
        ledOnOff = false; //LED 끄기
        Serial.println("LED OFF");  //LED OFF를 시리얼 모니터로 출력
        inputString = "";
      }
    }
    else inputString += inChar; //문자열이 종료될 때까지 이어 붙임
  }
}
