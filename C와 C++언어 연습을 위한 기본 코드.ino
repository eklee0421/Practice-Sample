void setup() {  //초기화 함수
  Serial.begin(9600);  //시리얼 포트 초기화
}

void loop() { //반복 실행 함수
  Serial.print("Without 'New Line' charater..."); //줄바꿈 없는 출력
  Serial.println("With 'New Line' charater..."); //줄바꿈 있는 출력
  Serial.println("See the different...");
  
  while(true);
}
