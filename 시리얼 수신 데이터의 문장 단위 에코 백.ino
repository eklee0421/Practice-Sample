/*

시리얼 모니터로부터 문자열을 수신하고, 개행 문자를 발견한 경우 문장이 끝난 것으로 파악하고 이를 다시 재전송하는 코드

*주의: 시리얼 모니터에서 'Newline' 혹은 'Both NL & CR' 중 하나로 설정해야 '\n' 값이 들어오며 문장 종료 파악 가능

*/

String inputString = "";  //수신 데이터 저장 버퍼
boolean stringComplete = false;  // 수신 문자열이 개행 문자로 종료

void setup() {
  Serial.begin(9600); // 시리얼 포트 초기화
  inputString.reserve(200);   //최대 200문자가지 보관
}

void loop() {
  if(stringComplete) {
    Serial.println(inputString);  //수신 개행 문자로 끝난 경우
    inputString = ""; //에코 백(echo back)
    stringComplete = false; //수신 버퍼 지움
  }
}

void serialEvent() {
  while (Serial.available()) {  //도착한 모든 데이터 읽음 //Serial.available() => 시리얼 포트에 수신되어 저장되어 있는 바이트 수 반환
    char inchar = (char)Serial.read();  //1바이트 읽음
    inputString += inChar;  //문자열 뒤에 붙임
    if(inChar == '\n') {  // 개행 문자이면 문자열 종료 표시
      stringComplete = true;
    }
  }
}
