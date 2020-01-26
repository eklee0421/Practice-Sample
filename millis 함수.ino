//프로그램 실행 시간을 1초마다 밀리초 단위로 시리얼 모니터에 출력하는 코드

unsigend long time; //경과 시간 저장할 변수

void setup() {
  Serial.begin(9600); // 경과 시간 출력을 위한 시리얼 통신 장치
}

void loop() {
  Serial.print("Time: );  
  time = millis(); // 경과 시간
  Serial.println(time); // 경과 시간 출력
  
  delay(1000);  //1초 지연
}
