//전용모드에서 거리를 측정하는 예시 - 전용 모드에서는 트리거와 에코핀을 하나의 핀에서 처리
// 아두이노에 연결하기 위해 필요한 핀의 갯수는 적지만 각각 출력과 입력으로 매번 설정해주어야 한다

int distance;

int trigger_echo = 7; //전용 모드에서는 에코핀과 트리거핀이 통합되어 있음

void setup() {
  Serial.begin(9600);
}

void loop() {
 
  pinMode(trigger_echo, OUTPUT); //트리거를 위해 출력으로 설정
  digitalWrite(trigger_echo, HIGH);
  delayMicroseconds(10); //10μs의 펄스를 발생
  digitalWrite(trigger, LOW);
  
  pinMode(trigger_echo, INPUT); //에코를 위해 입력으로 설정
  distance = pulseIn(trigger_echo, HIGH) / 58;  //입력으로부터 거리를 cm 단위로 계산
  
  Serial.println("Distane(cm) = " + String(distance));
  
  delay(1000);
}
