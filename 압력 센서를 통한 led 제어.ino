/*압력센서에 가해지는 압력에 비례하여 켜지는 led 개수가 변화하는 회로*/

int led[] = {8, 9, 10, 11}; //led 연결 핀

void setup() {
  for(int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT);  // led 연결 핀 출력으로 설정
  }
}

void loop() {
  int val = analog(A0); // 압력 센서 값 읽기
  
  //압력 센서 값을 led 개수로 변환
  //4는 센서 값이 최대일 때 켜질 led의 개수로 사용하는 led의 개수에 따라 다른 값을 사용해야 한다.
  int value = map(val, 0, 1023, 0, 4);
  
  for(int i = 0; i < value; i++){
    digitalWrite(led[i], HIGH);
 }
 
  for(int i = value; i < 4; i++){
    digitalWrite(led[i], LOW);
 }

  delay(1000);
}
