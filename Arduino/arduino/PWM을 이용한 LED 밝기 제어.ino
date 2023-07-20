int LED_pin = 3;  //LED 연결 핀

void setup() {
  pinMode(LED_pin, OUTPUT); //출력 모드 설정
}

void ioop() {
int i;
  for(i =0; i< 256; i++) {
  analogWrite(LED_pin, i); //0(꺼짐) 상태에서 255(켜짐)로 서서히 변화
  delay(10);
  }
}
