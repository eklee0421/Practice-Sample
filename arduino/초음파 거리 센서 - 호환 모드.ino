//호환모드에서 거리를 측정하는 예시 - 호환 모드에서는 에코 출력과 트리거 입력핀이 분리되어 있다

int distance;

int trigger = 7;
int echo = 6;

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT); //트리거핀 출력으로 설정
  pinMode(echo, INPUT); //에코핀 입력으로 설정
}

void loop() {
  //트리거핀으로 10μs의 펄스를 발생
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  //에코핀 입력으로부터 거리를 cm 단위로 계산
  distance = pulseIn(echo, HIGH) / 58;
  
  Serial.println("Distane(cm) = " + String(distance));
  
  delay(1000);
}
