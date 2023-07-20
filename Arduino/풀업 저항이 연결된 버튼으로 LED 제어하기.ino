int ledOut = 8; //led 출력 핀
int buttonIn = 9; //버튼 입력 핀

void setup() {
  pinMode(ledOut, OUTPUT);  //led 핀 출력으로 설정
  pinMode(buttonIn, INPUT); //버튼 핀 입력으로 설정
}
 
void loop() {
  int buttonState = digitalRead(buttonIn);  // 버튼 상태 읽기
  digitalWrite(ledOut, buttonState);  // 버튼 상태에 따라 led on/off
}
