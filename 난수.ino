long randNumber;  //랜덤 숫자를 저장 할 변수

void setup() {
  Serial.begin(9600); // 시리얼 포트 초기화
 
 //핀 A0가 연결되지 않은 경우 아날로그 잡음이 유입되어 의사 난수 시작점을 무작위로 초기화 시킨다.
 randomSeed(analogRead(A0));
 }
 
 void loop() {
  randNumber = random(300); //0~299 사이의 난수
  Serial.println(randNumer);
  
  randNumber = random(10, 20);   //10~19 사이의 난수
  Serial.println(randNumber);
  
  delay(50);
  }
