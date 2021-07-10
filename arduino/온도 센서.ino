void setup() {
  Serial.begin(9600); //시리얼 포트 초기화
}

void loop() {
  int reading = analodRead(A0);   //센서 읽기
  float voltage = reading * 5.0 /1024.0;  //전압으로 변환
  Serial.print(voltage);
  Serial.print("V: ");
  
  //섭씨온도
  float temperatureC = (voltage - 0.5) * 100;
  Serial.print(temperatureC);
  Serial.print("C, ");
  
  //화씨 온도
  float temperatureF = (voltage * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF);
  Serial.print("F");
  
  delay(1000);
}

